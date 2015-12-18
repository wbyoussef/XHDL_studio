// Xhdl_body.h: interface for the Xhdl_body class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLBODY_H
#define XHDLBODY_H


// #include<qdom.h>

#include "XhdlPortMap.h"
#include "XhdlStatic.h"
#include "XhdlProcess.h"
#include "XhdlPlain.h"
#include "XmlReader.h"
#include <string>
#include <vector>
using namespace std;
class XhdlArch;
class XhdlStatic; 
class XhdlBody   : public xhdl_atom
{
public:
   XhdlBody(XhdlArch* arch );
   virtual ~XhdlBody();

   // Localisation 
   XhdlArch* parent;    
   
   // members 
   vector<XhdlPortMap*> list_maps;
   vector<XhdlStatic*> list_stat;
   vector<XhdlProcess*> list_process;
   vector<XhdlPlain*>  list_plain;

   // deserialization
   void fillObject(XmlReader *xr);

  
   
   
   string getFull_name() const;
   void setFull_name(const string &value);

   string getCLASS_TAG() const;
   void setCLASS_TAG(const string &value);

private :
   string full_name;
private :
   string CLASS_TAG;

};

#endif 
