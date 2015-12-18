//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef XHDLPROJ_MAN_H
#define XHDLPROJ_MAN_H
#include "XmlReader.h"
#include "xhdl_atom.h"

/**
@author walid
*/
class XhdlProj_man  : public xhdl_atom{
public:
    XhdlProj_man();
    ~XhdlProj_man();
    
    void fillObject (XmlReader *xr);

};

#endif
