#ifndef NINJA_APIS_H
#define NINJA_APIS_H

#include "XhdlIp.h"
#include "XhdlSignal.h"

// get the count of inputs in the IP
int xhdl_get_inputs_cnt (const XhdlIp *ip);
int xhdl_get_outputs_cnt (const XhdlIp *ip);


bool is_input ( XhdlSignal *signal );
bool is_output ( XhdlSignal *signal );

#endif // NINJA_APIS_H
