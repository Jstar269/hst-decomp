/* HSTMATCH module=EBOOT.BIN start=0x001916a4 end=0x001916e4 symbol=FUN_001916a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_001916e4();
extern u32 FUN_00191818();

/* Sets up the object through two helpers (the second gets arg) and returns it. */
u32 FUN_001916a4(u32 self,u32 unused,u32 arg)
{
  FUN_00191818(self);
  FUN_001916e4(self,arg);
  return self;
}
