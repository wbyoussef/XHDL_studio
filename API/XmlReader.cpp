// XmlReader.cpp: implementation of the XmlReader class.
//
//////////////////////////////////////////////////////////////////////
#include <string>
#include <string.h>
using namespace std;

#include "XmlReader.h"


// {{{ const char* get_xml_element_type (xmlElementType type)

const char* get_xml_element_type (xmlElementType type)
{
  switch (type)
    {
    case XML_ELEMENT_NODE : return "XML_ELEMENT_NODE ";
    case XML_ATTRIBUTE_NODE : return "XML_ATTRIBUTE_NODE"; 
    case XML_TEXT_NODE : return "XML_TEXT_NODE " ;
    case XML_CDATA_SECTION_NODE : return "XML_ATTRIBUTE_NODE";
    case XML_ENTITY_REF_NODE : return "XML_ENTITY_REF_NODE" ;
    case XML_ENTITY_NODE : return "XML_ENTITY_NODE" ;
    case XML_PI_NODE : return "XML_PI_NODE" ;
    case XML_COMMENT_NODE : return "XML_COMMENT_NODE" ;
    case XML_DOCUMENT_NODE : return "XML_DOCUMENT_NODE" ;
    case XML_DOCUMENT_TYPE_NODE : return "XML_DOCUMENT_TYPE_NODE" ;
    case XML_DOCUMENT_FRAG_NODE : return "XML_DOCUMENT_FRAG_NODE" ;
    case XML_NOTATION_NODE : return "XML_NOTATION_NODE" ;
    case XML_HTML_DOCUMENT_NODE : return "XML_HTML_DOCUMENT_NODE" ;
    case XML_DTD_NODE : return "XML_DTD_NODE" ;
    case XML_ELEMENT_DECL : return "XML_ELEMENT_DECL" ;
    case XML_ATTRIBUTE_DECL : return "XML_ATTRIBUTE_DECL" ;
    case XML_ENTITY_DECL : return "XML_ENTITY_DECL" ;
    case XML_NAMESPACE_DECL : return "XML_NAMESPACE_DECL" ;
    case XML_XINCLUDE_START : return "XML_XINCLUDE_START" ;
    case XML_XINCLUDE_END : return "XML_XINCLUDE_END" ;
    case XML_DOCB_DOCUMENT_NODE : return "XML_DOCB_DOCUMENT_NODE" ;
    }
  return "";
}

// }}}


// {{{ XmlReader::XmlReader()

XmlReader::XmlReader()
{
  fileOpened=false;
}

// }}}

// {{{ XmlReader::XmlReader(const XmlReader *brother)

XmlReader::XmlReader(const XmlReader *brother)
{
  doc         = brother->doc        ;
  currentNode = brother->currentNode;
  fileOpened  = fileOpened          ;
  
}

// }}}

// {{{ XmlReader::~XmlReader()

XmlReader::~XmlReader()
{
  
}

// }}}

// {{{ const char* XmlReader::report ()

const char* XmlReader::report ()
{
  string return_tmp = "\n ------------- XML READER REPORT ------------\n";
  
  const unsigned char* tmp_xml_char = new unsigned char; 
  tmp_xml_char = currentNode->name;
  return_tmp  += get_xml_element_type(currentNode->type); 
  return_tmp  += "\t : "; 
  return_tmp  += reinterpret_cast<const char*> (tmp_xml_char) ;
  return_tmp  += "\n ------------- class methods results --------\n";
  return_tmp  += "\ngetTagName      : ";
  return_tmp  += getTagName();
  return_tmp  += "\ngetTextData     : ";
  return_tmp  += getTextData();
  return_tmp  += "\n";
  
  return_tmp  += "Pointers :\n ";
  
  return_tmp  += "\nname       \t";
  if (currentNode->name != NULL ) return_tmp += "X";
  
  return_tmp  += "\nchildren   \t";
  if (currentNode->children != NULL ) return_tmp += "X";
  
  return_tmp  += "\nlast       \t";
  if (currentNode->last != NULL ) return_tmp += "X";
  
  return_tmp  += "\nparent     \t";
  if (currentNode->parent != NULL ) return_tmp += "X";
  
  return_tmp  += "\nnext       \t";
  if (currentNode->next != NULL ) return_tmp += "X";
  
  return_tmp  += "\nprev       \t";
  if (currentNode->prev != NULL ) return_tmp += "X";
  
  return_tmp  += "\ndoc        \t";
  if (currentNode->doc != NULL ) return_tmp += "X";
  
  return_tmp  += "\ncontent    \t";
  if (currentNode->content != NULL ) return_tmp += "X";
  
  return_tmp  += "\nproperties \t";
  if (currentNode->properties != NULL ) return_tmp += "X";
  
  
  
  
  return_tmp  += "\n ------------- attributes ---------- --------\n";
  
  xmlAttr *attributes_list = currentNode->properties;
  while (attributes_list != NULL)
    {
      return_tmp  += reinterpret_cast<const char*>(attributes_list->name);
      return_tmp  += " : \t\t\t";
      return_tmp  += reinterpret_cast<const char*>(attributes_list->children->content);
      return_tmp  += "\n";
      attributes_list = attributes_list->next;
    }
  
  return_tmp  += "\n ------------- XML READER REPORT ------------\n";
  return  return_tmp.c_str();
}

// }}}


// {{{ bool XmlReader::openDoc( char* filename)

bool XmlReader::openDoc( const char* filename)
{

  // Open XML file
  doc = xmlParseFile (filename);
  if (doc == NULL )
    {
      fileOpened = false ;
      return fileOpened ;
    }
  currentNode = xmlDocGetRootElement (doc);
  moveTofirstChild();  // root's text
  // moveToNextSibling(); // first element 
  fileOpened = true;  
  return fileOpened;
}

// }}}

// {{{ bool XmlReader::open_stream(char* doc_stream)

bool XmlReader::open_stream(char* doc_stream)
{
  unsigned char * xmlchat_tmp = reinterpret_cast<unsigned char*> (doc_stream);
//  doc = xmlParseDoc (xmlchat_tmp);
  doc = xmlParseDoc (reinterpret_cast<const xmlChar*> ("w:/derfault_ip.xml"));
  currentNode = xmlDocGetRootElement (doc);
  moveTofirstChild();  // root's text
  // moveTofirstChild();  // root's text
  fileOpened = true;
  return true; 
}

// }}}

// {{{ string XmlReader::getTagName()

string XmlReader::getTagName()
{
  if (currentNode->type == XML_ELEMENT_NODE)
    {
      return string (reinterpret_cast<const char*>(currentNode->name));
    } else
      {
	return string ("");
      }
}

// }}}

// {{{ string XmlReader::getTextData()

string XmlReader::getTextData()
{
  string return_tmp;
  if (currentNode->content != NULL)
    {
      return_tmp = (reinterpret_cast<const char*>(currentNode->content));
    } else 
      {
	return_tmp = "N/A";
      }
  return return_tmp;
}

// }}}



// {{{ void XmlReader::moveTofirstChild()

bool XmlReader::moveTofirstChild()
{
  if (currentNode->children != NULL)
    {
      currentNode = currentNode->children;
      if (currentNode->type == XML_TEXT_NODE)
	{
	  moveToNextSibling();
	}
      return true;
    } else {
      return  false ;
    }
}

// }}}

// {{{ void XmlReader::moveToNextSibling()

void XmlReader::moveToNextSibling()
{
  if (currentNode->next != NULL)
    {
      currentNode = currentNode->next;
      if (currentNode->type == XML_TEXT_NODE)
	moveToNextSibling();
    } 
}

// }}}

// {{{ void XmlReader::moveToParent()

void XmlReader::moveToParent()
{
  if (currentNode->parent != NULL)
    {
      currentNode = currentNode->parent;
    } 
}

// }}}

// {{{ const char * XmlReader::getAttribute(const char * attName)

const char * XmlReader::getAttribute(const char * attName)
{
  xmlAttr *attributes_list = currentNode->properties;
  while (attributes_list != NULL)
    {
      if (strcmp(reinterpret_cast<const char*>(attributes_list->name),attName) == 0 )
	return reinterpret_cast<const char*>(attributes_list->children->content);
      else 
        attributes_list = attributes_list->next;
    }
  return "NULL";
}

// }}}

