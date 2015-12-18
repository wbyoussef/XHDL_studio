// XhdlAffectation.cpp: implementation of the XhdlAffectation class.
//
//////////////////////////////////////////////////////////////////////

#include "XhdlAffectation.h"
#include "XhdlClasses.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


XhdlAffectation::XhdlAffectation()
{
	this->setCLASS_TAG("XhdlAffectation");
  
}




void XhdlAffectation::fillObject (XmlReader *xr)
{
  xr->moveTofirstChild ();
  //----------output------------------------
  if ( xr->getTagName () =="output")
    {
      xr->moveTofirstChild ();                
      output = xr->getTextData ();
      
      xr->moveToParent ();
    }
  xr->moveToNextSibling ();
  
  
  if ( xr->getTagName () =="default_expr")
    {
      default_expr = new  XhdlExpression();
      XmlReader *xr1 = new XmlReader( xr );
      xr1->moveTofirstChild ();
      default_expr->fillObject ( xr1);
      xr->moveToNextSibling ();
      delete ( xr1);
    } 
  
  while ( xr->getTagName () =="cond_expr")
    {
      cond_expr* tmp_cond = new cond_expr;
      tmp_cond->expr      = new XhdlExpression();
      tmp_cond->condition = new XhdlExpression();
      
      XmlReader *xr1 = new XmlReader( xr );
      xr1->moveTofirstChild ();
      tmp_cond->expr->fillObject ( xr1);
      
      
      XmlReader *xr2 = new XmlReader( xr);
      xr2->moveTofirstChild ();
      xr2->moveToNextSibling (); 
      tmp_cond->condition->fillObject ( xr2);
      
      cond_expressions.push_back(tmp_cond);
      delete (xr1);
      delete (xr2);
      xr->moveToNextSibling (); 
    } 
  
  
  //----------input list ----------------------
  /*
    if ( xr->getTagName () =="expr" )
    {
    XmlReader *xr1 = new XmlReader( xr );
    xr1->moveToNextSibling ();
    
    if ( xr1->getTagName () == "cond")
    {
    ce =new cond_expr ;
    while ( xr->getTagName () =="expr" )
    {
    XhdlExpression *expr = new XhdlExpression();
    xr1 = new XmlReader (xr);
    expr->fillObject ( xr1);
    
    xr->moveToNextSibling ();
    
    
    if (xr->getTagName () =="cond")
    {
    string cond;
    xr->moveTofirstChild ();
    cond = xr->getTextData ();
    xr->moveToParent ();
    node1 temp;
    temp.cond = cond ;
    temp.expr =expr;
    ce->cond_affect.push_back (temp );
    xr->moveToNextSibling ();
    }
    }
    if ( xr->getTagName () =="default_expr")
    {
    xr->moveTofirstChild ();
    if (xr->getTagName () =="expr")
    {
    XhdlExpression *expr = new XhdlExpression();
    xr1 = new XmlReader (xr);
    expr->fillObject ( xr1);
    ce->default_expr = expr ;       
    type = 1 ;
    }
    return ;
    }
    delete ( xr1);
    type = 1 ;
    return ;
    }
    //else
    xr1 = new XmlReader (xr);
    expr1 = new XhdlExpression();
    expr1->fillObject ( xr1);
    type = 2 ;
    }
    
    
    
  */
}
string XhdlAffectation::getCLASS_TAG() const
{
    return CLASS_TAG;
}

void XhdlAffectation::setCLASS_TAG(const string &value)
{
    CLASS_TAG = value;
}
string XhdlAffectation::getCLASS_NAME() const
{
    return CLASS_NAME;
}

void XhdlAffectation::setCLASS_NAME(const string &value)
{
    CLASS_NAME = value;
}





XhdlAffectation::~XhdlAffectation()
{
    
}

