/* HSTMATCH module=EBOOT.BIN start=0x00231114 end=0x00231168 symbol=FUN_00231114 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern SingletonHolder * DAT_0034a65c;  /* the singleton */
extern void FUN_00000a00();
extern void FUN_002311cc();

/* Deleting destructor: clear the singleton, destroy the target, free the holder when flags > 0. */
SingletonHolder * FUN_00231114(SingletonHolder *self,short flags)
{
  if (self != 0) {
    DAT_0034a65c = 0;
    FUN_002311cc();
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
