#ifndef XHDL_SIGNAL_EDITOR_H
#define XHDL_SIGNAL_EDITOR_H

#include "XhdlSignal.h"

const char* get_signal_name (XhdlSignal* signal);
void set_signal_name (XhdlSignal* signal, const char* new_name);

const char* get_signal_type (XhdlSignal* signal);
void get_signal_type (XhdlSignal* signal, const char* type);

const char* get_signal_direction (XhdlSignal* signal);
void get_signal_direction (XhdlSignal* signal, const char* direction);

int get_signal_high_val (XhdlSignal* signal);
void get_signal_high_val (XhdlSignal* signal, int high_val);

bool signal_is_a_bit (XhdlSignal* signal);
void set_signal_as_bit (XhdlSignal* signal);
void unset_signal_as_bit (XhdlSignal* signal);

bool signal_is_a_reset (XhdlSignal* signal);
void set_signal_as_reset (XhdlSignal* signal);
void unset_signal_as_reset (XhdlSignal* signal);

bool signal_is_a_clock (XhdlSignal* signal);
void set_signal_as_clock (XhdlSignal* signal);
void unset_signal_as_clock (XhdlSignal* signal);

const char* get_signal_initial_val (XhdlSignal* signal);
void set_signal_initial_val (XhdlSignal* signal, const char* new_initial_val);

bool signal_is_a_flipflop (XhdlSignal* signal);
void set_signal_as_flipflop (XhdlSignal* signal);
void unset_signal_as_flipflop (XhdlSignal* signal);

const char* get_signal_reset (XhdlSignal* signal);
void set_signal_reset (XhdlSignal* signal, const char* new_reset);

const char* get_signal_clock (XhdlSignal* signal);
void set_signal_clock (XhdlSignal* signal, const char* new_clock);

const char* get_signal_reference (XhdlSignal* signal);
void set_signal_reference (XhdlSignal* signal, const char* new_reference);

const char* get_signal_comment (XhdlSignal* signal);
void set_signal_comment (XhdlSignal* signal, const char* new_comment);

#endif
