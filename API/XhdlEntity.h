#ifndef XHDLENTITY_H
#define XHDLENTITY_H


#include<string>
#include<vector>

#include "xhdl_atom.h"
using namespace std;
class XhdlIp;
class XhdlSignal; 
class XmlReader; 

class XhdlEntity  : public xhdl_atom
{
  
  
  
 public:
  
  XhdlEntity();
  XhdlEntity(XhdlIp* ip);
  virtual ~XhdlEntity();

  void fillObject(XmlReader *xr);

  string name;
  vector<string>      list_params;
  vector<XhdlSignal*> list_bus;
  XhdlSignal* reset;
  XhdlSignal* clk;
  XhdlIp* parent;
  
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
