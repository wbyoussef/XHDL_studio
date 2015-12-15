// Xhdl_signal.h: interface for the Xhdl_signal class.
//
//////////////////////////////////////////////////////////////////////

#ifndef XHDLSIGNAL_H
#define XHDLSIGNAL_H
// #include<qdom.h>

#include "XmlReader.h"

#include<string>
using namespace std;

class XhdlIp  ;
class XhdlSignal  
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
};

#endif 
