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
#include "xhdl_instruction.h"
#include "ninja_defines.h"
#include "xhdl_simple_instruction.h"
#include "xhdl_if_statement.h"

xhdl_instruction::xhdl_instruction(XhdlProcess* parent)
{
  this->parent_process = parent;
  is_root = true;
  this->setCLASS_TAG("xhdl_instruction");

}


xhdl_instruction::xhdl_instruction(xhdl_if_statement* parent)
{
  this->parent_if_statement = parent;
  is_root = false;
  this->setCLASS_TAG("xhdl_instruction");

}

xhdl_instruction::~xhdl_instruction()
{
}




/*!
  \fn xhdl_instruction::fillObject(XmlReader *xr)
*/
void xhdl_instruction::fillObject(XmlReader *xr)
{
  type = XHDL_INSTRUCTION_TYPE_SIMPLE;
  /// @todo implement me
  xr->moveTofirstChild();
  string tag_name;
  tag_name= xr->getTagName();
  // output = tag_name;
  if ( tag_name == "sig_name" )
    {
      xr->moveTofirstChild();
      type = XHDL_INSTRUCTION_TYPE_SIMPLE;
      output = xr->getTextData();
      xr->moveToParent();
      xr->moveToNextSibling();
    }
  
  {
    //type = XHDL_INSTRUCTION_TYPE_SIMPLE;
    simple_instruction = new xhdl_simple_instruction(this);
    XmlReader *xr2 = new XmlReader(xr);
    simple_instruction->fillObject(xr2);
  }
  /* else if (xr->getTagName() == "conditional_inst" )
     {
     type = XHDL_INSTRUCTION_TYPE_IF;
     if_statement = new xhdl_if_statement();
     XmlReader *xr3 = new XmlReader(xr);
     if_statement->fillObject(xr3);
     }
  */
}
string xhdl_instruction::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void xhdl_instruction::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}


XhdlProcess* xhdl_instruction::get_parent_process()
{
    return parent_process;
}
