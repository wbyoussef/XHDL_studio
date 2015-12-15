// XhdlIp.cpp: implementation of the XhdlIp class.
//
//////////////////////////////////////////////////////////////////////

// STL libs 
#include <string.h>
#include <iostream>

// Xhdl libs 
#include "XhdlClasses.h"


// Xhdl IP ctor 
XhdlIp::XhdlIp()
{
  entity=new XhdlEntity(this);
  package=new XhdlPackage();
  fileOpened = false ;
  fileGen = false;  
}


// XhdlIP destructor
XhdlIp::~XhdlIp()
{
  // TODO delete members 
}


// Read IP from an XML reader
void XhdlIp::fillObject(XmlReader *xr)
{
  // Reads Documentation member 
  if(xr->getTagName()=="documentation")
    {
      if (xr->moveTofirstChild())
	{
	  documentation=xr->getTextData();
	  xr->moveToParent();
	}
    }
  xr->moveToNextSibling();
  
  
  // Reads Version  member 
  if(xr->getTagName()=="version")
    {
      if (xr->moveTofirstChild())
	{
	  version=xr->getTextData();
	  xr->moveToParent();
	}
    }
  xr->moveToNextSibling(); 
  
  // Reads Entity  member 
  if(xr->getTagName()=="entity")
    {
      XmlReader *xr1= new XmlReader(xr);
      entity->fillObject(xr1);
      delete (xr1);
    }
  xr->moveToNextSibling(); 
  
  
  // Reads Package member 
  if(xr->getTagName()=="package")
    {
      XmlReader *xr1= new XmlReader(xr);
      package->fillObject(xr1);
      delete (xr1);
      xr->moveToNextSibling();  
    }
  
  // Reads list_arch member and archs childs 
  if ( xr->getTagName() =="list_arch")   
    {
      if (xr->moveTofirstChild())
	{
	  XmlReader *xr2 = new XmlReader( xr ) ; 
	  while(xr2->getTagName()=="arch")
	    {
	      XmlReader *xr1= new XmlReader(xr2); 
	      XhdlArch *a=new XhdlArch(this);
	      a->fillObject(xr1); 
	      list_arch.push_back(a); 
	      xr2->moveToNextSibling();
	      delete(xr1);
	    }
	  delete (xr2);
	}
    }
}

// Read IP from an XML file 
void XhdlIp::openXmlDoc(string fileName)
{
  this->xmlFile = fileName; 
  xmlrd = new XmlReader ;
  if ( xmlrd->openDoc(fileName.c_str() ) )
    {
      (entity->list_bus).clear();
      (entity->list_params ).clear();
      list_arch.clear();
      
      fileOpened = true ;
    }
  else
    {
      fileOpened = false ;
    }
  
}


//  Open IP from char* pointer 
void XhdlIp::openXmlStream(char* xml_stream)
{
  xmlrd = new XmlReader ;
  xmlrd->open_stream(xml_stream);
  fileOpened = true; 
}

// gets IP's documentation
char* XhdlIp::getDocumentation()
{
  char *r = new char();
  strcpy(r  , this->documentation.c_str() ) ;
  return r;
}

// sets IP documentation 
void XhdlIp::setDocumentation (char *d )
{
  this->documentation = d;
}


// Fills IP members 
void XhdlIp::setIp()
{
  if ( !fileOpened)
    return ;
  this->fillObject(xmlrd);
  delete (xmlrd);
  fileOpened = false;
}

// Obsolete : generates VHDL code 
char* XhdlIp::genVhdl(string dstFile)
{
  return "No VHDL file was generated";
}


void XhdlIp::set_ip_name (const char* name)
{
    this->entity->name = name;
}


const char* XhdlIp::get_ip_name ()
{
    return this->entity->name.c_str();
}
