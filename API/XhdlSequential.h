// XhdlSequential.h: interface for the XhdlSequential class.
//
//////////////////////////////////////////////////////////////////////

#if !defined XHDLSEQUENTIAL_H
#define XHDLSEQUENTIAL_H

class XhdlAffectation; 
#include "XhdlAffectation.h"
#include "XhdlExpression.h"

class XhdlSequential   : public xhdl_atom
{
  public :
	struct node{
		string cond;
		int seq_number;
	};typedef struct node Node;
public:
	XhdlSequential();
	void fillObject (XmlReader *xr);
	virtual ~XhdlSequential();
	
	int type;
	//type 1 affectation instruction
	XhdlAffectation *aff;

	//type2  if instruction

	vector <Node> cond_list;
	vector <XhdlSequential*> seq_list;
	vector <XhdlSequential*> else_inst;
	bool else_found;

	//type 3 case instruction
	XhdlExpression *expr;
	vector <Node> val_list;
	vector <XhdlSequential*> case_seq_list;
	vector <XhdlSequential*> default_inst;
	bool default_found;

	//type 4 {41 42} for instruction
	string param_name ;
	string low_val;
	string high_val;
	string litteral;
	string startfrom ; //attribute default is low
	vector <XhdlSequential*> for_seq_list;
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
