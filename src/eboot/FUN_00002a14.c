/* HSTMATCH module=EBOOT.BIN start=0x00002a14 end=0x00002a64 symbol=FUN_00002a14 lang=c99 */
/* Clone of src/eboot/FUN_0008d07c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_00002b04(void *, int);

/* Deleting destructor: runs the base destructor, frees the object when flags > 0. */
void *FUN_00002a14(void *self, short flags)
{
  if ((self != 0) && (FUN_00002b04(self, -1), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
