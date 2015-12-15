// XmlReader.h: interface for the XmlReader class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XMLREADER_H
#define XMLREADER_H

#include <string>
#include <libxml/xmlreader.h>

using namespace std;

class XmlReader  
{
public:
	XmlReader();
	XmlReader(const XmlReader *brother);
	virtual ~XmlReader();

    bool openDoc(const  char* fileName);
        bool open_stream(char* doc_stream);
	bool moveTofirstChild();
	void moveToNextSibling();
	void moveToParent();
	string getTagName();
	string getTextData();
	const char* getAttribute(const char * attName);
	bool fileOpened;
	const char * report ();


private:
        xmlNodePtr      currentNode;
        xmlDocPtr       doc;
};

#endif 
