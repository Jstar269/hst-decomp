/* HSTMATCH module=EBOOT.BIN start=0x002310d0 end=0x00231114 symbol=FUN_002310d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern SingletonHolder * DAT_0034a65c;  /* the singleton */
extern void FUN_00231168();
extern void FUN_00231248();

/* Constructor: register the holder as the singleton, create its target and set it pending. */
SingletonHolder * FUN_002310d0(SingletonHolder *self,u8 flag)
{
  self->target = 0;
  DAT_0034a65c = self;
  self->flag = flag;
  FUN_00231168();
  FUN_00231248(self,1);
  return self;
}
