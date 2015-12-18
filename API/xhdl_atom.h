#ifndef XHDL_ATOM_H
#define XHDL_ATOM_H
#include "ninja_defines.h"
#include <string>


using namespace std;

class xhdl_atom
{
public:
    xhdl_atom();

    string getFull_name() const;
    void setFull_name(const string &value);

    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

    string getRTL_ID() const;
    void setRTL_ID(const string &value);

private :
    string full_name;
    string CLASS_TAG;
    string RTL_ID;

};

#endif // XHDL_ATOM_H
