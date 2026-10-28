/* HSTMATCH module=hstp_trans_main.prx start=0x0008ec34 end=0x0008ec84 symbol=FUN_0008ec34 lang=c99 */
/* Clone of src/eboot/FUN_0008d07c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_000dbb20(void *, int);

/* Deleting destructor: runs the base destructor, frees the object when flags > 0. */
void *FUN_0008ec34(void *self, short flags)
{
  if ((self != 0) && (FUN_000dbb20(self, -1), 0 < flags)) {
    FUN_00000a00(self);
  }
  return self;
}
