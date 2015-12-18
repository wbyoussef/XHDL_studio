// XhdlAffectation.h: interface for the XhdlAffectation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLAFFECTATION_H
#define		 XHDLAFFECTATION_H

//#include "XhdlClasses.h"
#include <string>
#include <iostream>
#include <vector>
#include "xhdl_atom.h"

class XhdlExpression; 
class XmlReader;

using namespace std;


class XhdlAffectation   : public xhdl_atom
{

  public :

	struct node2 {
	XhdlExpression*  expr;
        XhdlExpression*  condition;
	};
	typedef node2 cond_expr ;

public:

	XhdlAffectation();
	virtual ~XhdlAffectation();
	void fillObject (XmlReader *xr);

	string output ;
	XhdlExpression *default_expr;
        
	vector <cond_expr*> cond_expressions;

	int type;
    string getCLASS_TAG() const;
    void setCLASS_TAG(const string &value);

    string getCLASS_NAME() const;
    void setCLASS_NAME(const string &value);

private :
    string CLASS_TAG;
    string CLASS_NAME;

};

#endif 
