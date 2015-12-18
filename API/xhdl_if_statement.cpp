//
// C++ Implementation: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "xhdl_if_statement.h"
#include "XhdlExpression.h"
#include "xhdl_instruction.h"

xhdl_if_statement::xhdl_if_statement()
{
	this->setCLASS_TAG("xhdl_if_statement");

} 


xhdl_if_statement::~xhdl_if_statement()
{
}




/*!
  \fn xhdl_if_statement::fillObject(XmlReader *xr)
*/
void xhdl_if_statement::fillObject(XmlReader *xr)
{
  /// @todo implement me
  xr->moveTofirstChild();
  if ( xr->getTagName() == "condition" ) 
    {
      condition = new XhdlExpression();
      XmlReader *xr2 = new XmlReader(xr);
      condition->fillObject(xr2);
      xr->moveToNextSibling();
    }
  while( xr->getTagName() == "true_inst" )
    {
      xhdl_instruction *tmp_instruction = new xhdl_instruction(this);
      XmlReader *xr3 = new XmlReader(xr);
      tmp_instruction->fillObject(xr3);
      true_instruntion.push_back(tmp_instruction);
      xr->moveToNextSibling();
    }
  while( xr->getTagName() == "false_inst" )
    {
      xhdl_instruction *tmp_instruction = new xhdl_instruction(this);
      XmlReader *xr4 = new XmlReader(xr);
      tmp_instruction->fillObject(xr4);
      false_instruntion.push_back(tmp_instruction);
      xr->moveToNextSibling();
    }
}
string xhdl_if_statement::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void xhdl_if_statement::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}

