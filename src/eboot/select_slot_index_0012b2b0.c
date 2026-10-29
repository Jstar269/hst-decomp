/* HSTMATCH module=EBOOT.BIN start=0x0012b2b0 end=0x0012b360 symbol=FUN_0012b2b0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/avatar_obj.h"

extern int FUN_0012b72c(Avatar *p0, int p1, int p2);
extern void FUN_0012ad54(Avatar *p1, int p2, int p3, int p4, void *p5, void *p6, float p7);
extern int DAT_0033b4b0;

/* Starts an animation: the current one when set, otherwise the table entry for the avatar's slot. */
void FUN_0012b2b0(Avatar *self, void *arg4, void *arg5, float speed)
{
  int i;
  int idx;

  /* matching idiom: the helper FUN_0012b72c takes the object as its first
     argument (it is left in a0), and the table index has to be computed
     BEFORE the >= 0 test so that the plain bltz branch can carry the
     add in its delay slot. */
  i = FUN_0012b72c(self, self->unk35c, 0);
  idx = self->unk354 + i * 2;
  if (self->unk334 >= 0) {
    FUN_0012ad54(self, self->unk334, 1, 0, arg4, arg5, speed);
  } else {
    FUN_0012ad54(self, DAT_0033b4b0 + idx, 1, 0, arg4, arg5, speed);
  }
}
