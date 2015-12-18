#include "xhdl_atom.h"

xhdl_atom::xhdl_atom()
{

}
string xhdl_atom::getFull_name() const
{
    return full_name;
}

void xhdl_atom::setFull_name(const string &value)
{
    full_name = value;
}
string xhdl_atom::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void xhdl_atom::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}
string xhdl_atom::getRTL_ID() const
{
    return RTL_ID;
}

void xhdl_atom::setRTL_ID(const string &value)
{
    RTL_ID = value;
}




