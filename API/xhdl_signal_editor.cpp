
#include "XhdlSignal.h"
#include "xhdl_signal_editor.h" 

// {{{ name

const char* get_signal_name (XhdlSignal* signal)
{
  return signal->name.c_str();
};

void set_signal_name (XhdlSignal* signal, const char* new_name)
{
  signal->name =  string (new_name);
};

// }}}

// {{{ type

const char* get_signal_type (XhdlSignal* signal)
{
  return signal->type.c_str();; 
};

void get_signal_type (XhdlSignal* signal, const char* type)
{
  signal->type = string (type) ;
};

// }}}

// {{{ direction

const char* get_signal_direction (XhdlSignal* signal)
{
  return signal->direction.c_str();; 
};

void get_signal_direction (XhdlSignal* signal, const char* direction)
{
  signal->direction = string (direction); 
};

// }}}

// {{{ high_val

int get_signal_high_val (XhdlSignal* signal)
{
  return signal->high_val; 
};

void get_signal_high_val (XhdlSignal* signal, int high_val)
{
  signal->high_val = high_val; 
};

// }}}

// {{{ is_bit

bool signal_is_a_bit (XhdlSignal* signal)
{
  return signal->is_bit;
};

void set_signal_as_bit (XhdlSignal* signal)
{
  signal->is_bit= true;
}

void unset_signal_as_bit (XhdlSignal* signal)
{
  signal->is_bit= false;
}

// }}}

// {{{ 	is_reset 
bool signal_is_a_reset (XhdlSignal* signal)
{
  return signal->is_reset;
};

void set_signal_as_reset (XhdlSignal* signal)
{
  signal->is_reset= true;
}

void unset_signal_as_reset (XhdlSignal* signal)
{
  signal->is_reset= false;
}

// }}}

// {{{ is_clock

bool signal_is_a_clock (XhdlSignal* signal)
{
  return signal->is_clock;
};

void set_signal_as_clock (XhdlSignal* signal)
{
  signal->is_clock= true;
}

void unset_signal_as_clock (XhdlSignal* signal)
{
  signal->is_clock= false;
}


// }}}

// {{{ initial_val

const char* get_signal_initial_val (XhdlSignal* signal)
{
  return signal->initial_val.c_str();
};

void set_signal_initial_val (XhdlSignal* signal, const char* new_initial_val)
{
  signal->initial_val =  string (new_initial_val);
};

// }}}

// {{{ is_flipflop

bool signal_is_a_flipflop (XhdlSignal* signal)
{
  return signal->is_flipflop;
};

void set_signal_as_flipflop (XhdlSignal* signal)
{
  signal->is_flipflop= true;
}

void unset_signal_as_flipflop (XhdlSignal* signal)
{
  signal->is_flipflop= false;
}



// }}}

// {{{ reset

const char* get_signal_reset (XhdlSignal* signal)
{
  return signal->reset.c_str();
};

void set_signal_reset (XhdlSignal* signal, const char* new_reset)
{
  signal->reset =  string (new_reset);
};


// }}}

// {{{ clock

const char* get_signal_clock (XhdlSignal* signal)
{
  return signal->clock.c_str();
};

void set_signal_clock (XhdlSignal* signal, const char* new_clock)
{
  signal->clock =  string (new_clock);
};


// }}}

// {{{ reference
const char* get_signal_reference (XhdlSignal* signal)
{
  return signal->reference.c_str();
};

void set_signal_reference (XhdlSignal* signal, const char* new_reference)
{
  signal->reference =  string (new_reference);
};


// }}}

// {{{ comment
const char* get_signal_comment (XhdlSignal* signal)
{
  return signal->comment.c_str();
};

void set_signal_comment (XhdlSignal* signal, const char* new_comment)
{
  signal->comment =  string (new_comment);
};


// }}}

