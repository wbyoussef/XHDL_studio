// XhdlSequential.cpp: implementation of the XhdlSequential class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlSequential.h"
#include "ninja_defines.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlSequential::XhdlSequential()
{
  else_found =false;
}

void XhdlSequential::fillObject (XmlReader *xr)
{
  
  xr->moveTofirstChild ();
  
  //affect inst
  if ( xr->getTagName () == "affect" )
    {
      aff = new XhdlAffectation ;
      aff->fillObject (xr);
      type = XHDLSEQUENCE_TYPE_AFFECT;
      return ;
    }
  
  // if inst
  
  if ( xr->getTagName () =="if" )
    {
      
      type = XHDLSEQUENCE_TYPE_IF;
      xr->moveTofirstChild ();
      int n;
      while ( xr->getTagName () == "cond")
	{
	  xr->moveTofirstChild ();
	  Node tempNode;
	  tempNode.cond = xr->getTextData ();
	  xr->moveToParent ();
	  xr->moveToNextSibling ();
	  
	  if ( xr->getTagName () == "list_sequential" )
	    {
	      XmlReader *xr1 = new XmlReader (xr);
	      xr1->moveTofirstChild ();
	      n = 0;
	      while ( xr1->getTagName () == "sequential")
		{
		  XmlReader *xr2 = new XmlReader (xr1);
		  XhdlSequential *seq =new XhdlSequential ;
		  seq->fillObject (xr2);
		  seq_list.push_back (seq);
		  n++;
		  xr1->moveToNextSibling () ;
		  delete (xr2);
		}
	      xr->moveToNextSibling ();
	      delete (xr1);				
	    }
	  tempNode.seq_number = n;
	  cond_list.push_back (tempNode);
	  
	}
      
      
      
      if ( xr->getTagName () =="else" )
	{
	  
	  XmlReader *xr1 = new XmlReader (xr);
	  xr1->moveTofirstChild ();
	  if ( xr1->getTagName () =="list_sequential" )
	    {
	      xr1->moveTofirstChild ();
	      while ( xr1->getTagName () == "sequential")
		{	
		  XmlReader *xr2 = new XmlReader (xr1);
		  XhdlSequential *seq = new XhdlSequential;
		  seq->fillObject (xr2);
		  else_inst.push_back ( seq );
		  xr1->moveToNextSibling ();
		  delete (xr2);
		  
		}
	      
	    }
	  else_found =true;
	  delete (xr1) ;
	  
	}
      
    }
  
  
  //case inst
  
  if ( xr->getTagName () =="case")
    {
      type = XHDLSEQUENCE_TYPE_CASE ;
      xr->moveTofirstChild ();
      int n;
      if ( xr->getTagName () == "expr" )
	{
	  XmlReader *xr1 = new XmlReader (xr);
	  expr = new XhdlExpression;
	  expr->fillObject (xr1);
	  delete (xr1);
	}
      
      xr->moveToNextSibling ();
      
      while ( xr->getTagName () == "value")
	{
	  xr->moveTofirstChild ();		
	  Node tempNode;
	  tempNode.cond = xr->getTextData ();
	  
	  xr->moveToParent ();
	  xr->moveToNextSibling ();
	  
	  if ( xr->getTagName () == "list_sequential")
	    {
	      XmlReader *xr1 = new XmlReader (xr);
	      n = 0;
	      xr1->moveTofirstChild ();
	      while ( xr1->getTagName () == "sequential" )
		{
		  XmlReader *xr2 = new XmlReader (xr1);
		  XhdlSequential *seq = new XhdlSequential ;
		  seq->fillObject (xr2) ;
		  case_seq_list.push_back ( seq );				
		  xr1->moveToNextSibling ();
		  delete (xr2);
		  n++;
		}
	      delete (xr1) ;
	      xr->moveToNextSibling ();
	    }
	  tempNode.seq_number = n;
	  val_list.push_back ( tempNode );
	  
	}
      
      
      if ( xr->getTagName () == "default" )
	{
	  XmlReader *xr1 = new XmlReader (xr);
	  xr1->moveTofirstChild();
	  if ( xr1->getTagName () == "list_sequential" )
	    {
	      xr1->moveTofirstChild ();
	      while (xr1->getTagName () == "sequential" )
		{
		  XmlReader *xr2 = new XmlReader (xr1);
		  XhdlSequential *seq = new XhdlSequential ;
		  seq->fillObject (xr2);
		  default_inst.push_back (seq);
		  delete (xr2);
		  xr1->moveToNextSibling ();
		}
	    }
	  delete (xr1);
	  default_found = true ;
	  
	}
      return ;
    }
  
  
  //for instruction
  
  if ( xr->getTagName () == "for" )
    {
      
      xr->moveTofirstChild ();
      
      if ( xr->getTagName () == "param_name" )
	{
	  xr->moveTofirstChild ();
	  param_name = xr->getTextData ();
	  xr->moveToParent ();
	}
      
      xr->moveToNextSibling ();
      
      if ( xr->getTagName () == "range" )
	{	
	  type = XHDLSEQUENCE_TYPE_RANGE_LITT ; 
	  XmlReader *xr1 = new XmlReader(xr);
	  xr->moveTofirstChild ();
	  
	  if ( xr->getTagName () == "litteral" )
	    {
	      xr->moveTofirstChild ();
	      litteral = xr->getTextData ();
	      xr->moveToParent ();
	    }
	  else if ( xr->getTagName () == "low_val")
	    {
	      type = XHDLSEQUENCE_TYPE_RANGE;
	      xr->moveTofirstChild ();
	      low_val = xr->getTextData ();
	      xr->moveToParent ();
	      xr->moveToNextSibling ();
	      
	      if ( xr->getTagName () == "high_val"  )
		{
		  xr->moveTofirstChild ();
		  high_val = xr->getTextData ();
		  xr->moveToParent ();
		  
		}
	      
	      startfrom = xr1->getAttribute ( "startfrom" );
	      
	    }
	  xr->moveToParent ();
	  delete (xr1) ;
	}
      
      xr->moveToNextSibling ();
      if ( xr->getTagName () == "list_sequential" )
	{
	  xr->moveTofirstChild ();
	  while ( xr->getTagName () == "sequential" )
	    {
	      XmlReader *xr1 = new XmlReader (xr);
	      XhdlSequential *seq = new XhdlSequential ;
	      seq->fillObject (xr1) ;
	      for_seq_list.push_back ( seq );				
	      delete (xr1) ;
	      xr->moveToNextSibling ();
	      
	    }
	}
      
      
    }
  
}

XhdlSequential::~XhdlSequential()
{
  
}
