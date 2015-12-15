
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
#include "xhdl_simple_instruction.h"
#include "ninja_defines.h"

xhdl_simple_instruction::xhdl_simple_instruction(xhdl_instruction* instruction)
{
  parent_instruction = instruction;
  is_root = true;
}


xhdl_simple_instruction::xhdl_simple_instruction(xhdl_simple_instruction* simple_instruction)
{
  parent_simple_instruction = simple_instruction;
  parent_instruction = simple_instruction->parent_instruction;
  is_root = false;
}


xhdl_simple_instruction::~xhdl_simple_instruction()
{
}




/*!
  \fn xhdl_simple_instruction::fillObject(XmlReader *xr)
*/
void xhdl_simple_instruction::fillObject(XmlReader *xr)
{
  /// @todo implement me
  xr->moveTofirstChild();
  if ( xr->getTagName() == "simple_instruction" ) 
    {
      type = XHDL_SIMPLE_INSTRUCTION_COMBINED;
      combined_instruction = new xhdl_combined_instruction;
      combined_instruction->simple_instruction1 = 
	new xhdl_simple_instruction(this);
      XmlReader *xr2 = new XmlReader(xr);
      combined_instruction->simple_instruction1->fillObject(xr2);
      
      xr->moveToNextSibling();
      xr->moveTofirstChild();
      combined_instruction->op = xr->getTextData();
      xr->moveToParent();
      
      xr->moveToNextSibling();
      //signal =  xr->getTagName();
      XmlReader *xr3 = new XmlReader(xr);
      combined_instruction->simple_instruction2 = 
	new xhdl_simple_instruction(this);
      combined_instruction->simple_instruction2->fillObject(xr3);
    }
  
  if ( xr->getTagName() == "null" ) 
    {
      xr->moveTofirstChild();
      type = XHDL_SIMPLE_INSTRUCTION_NULL;
      this->null=  xr->getTextData() ;
      xr->moveToParent();
      xr->moveToNextSibling();
    }
  
  if ( xr->getTagName() == "number" ) 
    {
      xr->moveTofirstChild();
      type = XHDL_SIMPLE_INSTRUCTION_NUMBER;
      this->number=  xr->getTextData() ;
      xr->moveToParent();
      xr->moveToNextSibling();
    }
  
  if ( xr->getTagName() == "sig_name" ) 
    {
      xr->moveTofirstChild();
      type = XHDL_SIMPLE_INSTRUCTION_SIGNAL;
      this->signal=  xr->getTextData() ;
    }
}

xhdl_instruction * xhdl_simple_instruction::get_parent_instruction()
{
  return parent_instruction;
}
