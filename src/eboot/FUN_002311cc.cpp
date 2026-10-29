/* HSTMATCH module=EBOOT.BIN start=0x002311cc end=0x00231214 symbol=FUN_002311cc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/singleton_holder.h"

struct Target { virtual ~Target(); };

/* Destroy the holder's target and clear the pointer. */
extern "C" void FUN_002311cc(SingletonHolder *self)
{
  Target *target;
  
  target = (Target *)self->target;
  if (target != (Target *)0x0) {
    delete target;
    self->target = 0;
  }
}
