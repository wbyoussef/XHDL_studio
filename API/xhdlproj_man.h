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

/**
@author walid
*/
class XhdlProj_man{
public:
    XhdlProj_man();
    ~XhdlProj_man();
    
    void fillObject (XmlReader *xr);

};

#endif
