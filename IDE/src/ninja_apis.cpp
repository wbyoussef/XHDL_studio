
#include "ninja_apis.h"
#include "XhdlSignal.h"
#include "XhdlEntity.h"

// get the count of inputs in the IP
int xhdl_get_inputs_cnt (const XhdlIp *ip)
{

    int in_cnt = 0;
    vector <XhdlSignal*>::const_iterator p_it;
    for ( p_it = ip->entity->list_bus.begin() ; p_it != ip->entity->list_bus.end () ; p_it ++ )
      {
        in_cnt ++;
        XhdlSignal* x;
        if (is_input (*p_it))
        {
            in_cnt ++;
        }
      }
    return in_cnt;

}


// get the count of outputs in the IP
int xhdl_get_outputs_cnt (const XhdlIp *ip)
{

    int out_cnt = 0;
    vector <XhdlSignal*>::const_iterator p_it;
    for ( p_it = ip->entity->list_bus.begin() ; p_it != ip->entity->list_bus.end () ; p_it ++ )
      {
        out_cnt ++;
        XhdlSignal* x;
        if (is_output (*p_it))
        {
            out_cnt ++;
        }
      }
    return out_cnt;

}




bool is_input ( XhdlSignal *signal )
{
      if ( ((signal)->direction.find ( "in" , 0 ) != string::npos )|
           ((signal)->direction.find ( "In" , 0 ) != string::npos )|
           ((signal)->direction.find ( "iN" , 0 ) != string::npos )|
           ((signal)->direction.find ( "IN" , 0 ) != string::npos ))
        return true ;
}

bool is_output ( XhdlSignal *signal )
{
        if ( ((signal)->direction.find ( "out" , 0 ) != string::npos )|
             ((signal)->direction.find ( "Out" , 0 ) != string::npos )|
             ((signal)->direction.find ( "OUt" , 0 ) != string::npos )|
             ((signal)->direction.find ( "OUT" , 0 ) != string::npos )|
             ((signal)->direction.find ( "oUT" , 0 ) != string::npos ))
        return true ;
}

