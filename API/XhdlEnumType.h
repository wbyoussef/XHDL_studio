// XhdlEnumType.h: interface for the XhdlEnumType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLENUMTYPE_H
#define XHDLENUMTYPE_H

#include "XmlReader.h"

#include <string>
#include <vector>

using namespace std;

class XhdlEnumType  
{

public:
	XhdlEnumType();
	virtual ~XhdlEnumType();
	void fillObject ( XmlReader *xr ) ;

	string name ; // name of the enumerated type 
	vector <string> enumlist ; //list of possible occurence



};

#endif 
