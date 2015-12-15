#ifndef XHDLENTITY_H
#define XHDLENTITY_H


#include<string>
#include<vector>

using namespace std;
class XhdlIp;
class XhdlSignal; 
class XmlReader; 

class XhdlEntity
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
  
  
  
  
};
#endif
