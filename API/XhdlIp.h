// XhdlIp.h: interface for the Xhdl_ip class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLIP_H
#define XHDLIP_H




// STL libs 
#include <string>
#include <vector>

using namespace std;

// imported classes 
class XhdlEntity;
class XhdlPackage  ;
class XhdlArch  ;
class XmlReader  ;

class XhdlIp  
{
public:
	XhdlIp();
	virtual ~XhdlIp();

	void fillObject(XmlReader *xr);
	void openXmlDoc (string fileName);
	char *getDocumentation( );
	void setDocumentation( char* d);
	void setIp();
	char* genVhdl(string destinationFile); // obsolete 
        void openXmlStream(char* xml_stream);
        void set_ip_name (const char* name);
        const char* get_ip_name ();


	// IP Sw members 
	string xmlFile;
	string targetFile;
	bool fileOpened ; //for Xml file look if it's opened
	bool fileGen ; //for the genrated file


	// Xhdl members 
	vector<XhdlArch*> list_arch;
	string documentation;
	string version;
	XhdlEntity *entity;
	XhdlPackage *package;
	string project_man;


private:
	XmlReader *xmlrd;
};

#endif 


