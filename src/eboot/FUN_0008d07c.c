/* HSTMATCH module=EBOOT.BIN start=0x0008d07c end=0x0008d0cc symbol=FUN_0008d07c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_000d7e30(void *, int);

/* Deleting destructor: runs the base destructor, frees the object when flags > 0. */
void *FUN_0008d07c(void *self, short flags)
{
  if ((self != 0) && (FUN_000d7e30(self, -1), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
