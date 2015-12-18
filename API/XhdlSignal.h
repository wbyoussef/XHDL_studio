// Xhdl_signal.h: interface for the Xhdl_signal class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLSIGNAL_H
#define XHDLSIGNAL_H
// #include<qdom.h>

#include "XmlReader.h"
#include "xhdl_atom.h"

#include<string>
using namespace std;

class XhdlIp  ;
class XhdlSignal   : public xhdl_atom 
{
public:
        
        //XhdlSignal();
        XhdlSignal(XhdlIp *ip);
        XhdlSignal (const XhdlSignal *sig , string ext);
        virtual ~XhdlSignal();
        
        XhdlIp *parent;
        string name;
        string type ; // for  enum and predefined type
        string direction;
        int high_val;
        int low_val;
        bool is_bit;
        bool is_reset;
        bool is_clock;
        string initial_val;
        bool is_flipflop;
        string reset;
        string clock;
        string reference;
        string comment;
private :
        string full_name;
        string CLASS_TAG;
public:
        void fillObject(XmlReader *xr);
        void set_params ( string name
                          ,string type
                          ,string direction
                          ,int high_val
                          ,int low_val
                          ,bool is_bit
                          ,bool is_reset
                          ,bool is_clock
                          ,string initial_val
                          ,bool is_flipflop
                          ,string reset
                          ,string clock
                          ,string reference
                          ,string comment
                        );

        string getFull_name() const;
        void setFull_name(const string &value);
        string getCLASS_TAG() const;
        void setCLASS_TAG(const string &value);
};

#endif 
