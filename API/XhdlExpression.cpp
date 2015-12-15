// XhdlExpression.cpp: implementation of the XhdlExpression class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlExpression.h"
#include "ninja_defines.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XhdlExpression::XhdlExpression()
{
  
  
}

void XhdlExpression::fillObject (XmlReader *xr)
{
  
  xr->moveTofirstChild();
  
  if ( xr->getTagName () == "sig_name" )
    {
      xr->moveTofirstChild ();
      sig_name = xr->getTextData();
      type = XHDLEXPRESSION_TYPE_SIG_NAME ;
      return ;
    }
  
  if ( xr->getTagName () == "litteral" )
    {
      xr->moveTofirstChild ();
      litteral = xr->getTextData();
      type = XHDLEXPRESSION_TYPE_LITTERAL ;
      return ;
    }
  
  if ( xr->getTagName () == "number" )
    {
      xr->moveTofirstChild ();
      number = xr->getTextData();
      type = XHDLEXPRESSION_TYPE_NUMBER;
      return ;
    }
  
  //*check if expr= (op , expr1)
  
  if ( xr->getTagName () == "op" )
    {
      xr->moveTofirstChild ();
      op = xr->getTextData ();
      
      xr->moveToParent () ;
      xr->moveToNextSibling ();
      if ( xr->getTagName () == "expr")
	{
	  this->expr1 = new XhdlExpression();
	  XmlReader *xr1 = new XmlReader (xr);
	  expr1->fillObject (xr1);
	  type = XHDLEXPRESSION_TYPE_OP_EXPR;
	  delete (xr1);
	}
      return;
      //TODO generate error
    }
  
  
  //check if expr = (expr2 , op , expr3)
  
  if ( xr->getTagName () == "expr" )
    {
      
      this->expr2 = new XhdlExpression () ;
      XmlReader *xr2 = new XmlReader (xr);
      expr2->fillObject (xr2);
      delete (xr2);
      
      xr->moveToNextSibling ();
      
      if ( xr->getTagName () == "op" )
	{
	  xr->moveTofirstChild ();
	  op = xr->getTextData ();
	  xr->moveToParent () ;
	}
      
      xr->moveToNextSibling ();
      
      if ( xr->getTagName () =="expr")
	{
	  this->expr3 = new XhdlExpression() ;
	  XmlReader *xr2 = new XmlReader (xr);
	  expr3->fillObject (xr2);
	  delete (xr2) ;
	  
	}
      
      type = XHDLEXPRESSION_TYPE_EXPR ;
      
      
      
    }
  
}

XhdlExpression::~XhdlExpression()
{
  
}
