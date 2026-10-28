/* HSTMATCH module=EBOOT.BIN start=0x0008d4e0 end=0x0008d530 symbol=FUN_0008d4e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_000d7e30(void *, int);

/* Deleting destructor: runs the base destructor, frees the object when flags > 0. */
void *FUN_0008d4e0(void *self, short flags)
{
  if ((self != 0) && (FUN_000d7e30(self, -1), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
