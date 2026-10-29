/* HSTMATCH module=hstp_trans_main.prx start=0x0022697c end=0x002269b8 symbol=FUN_0022697c lang=c99 */
/* Clone of src/eboot/FUN_002178d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

extern void FUN_002269b8();
extern void FUN_002269c4();
extern void FUN_002269d0();
extern void FUN_002269dc();

/* Stop all four blocks. */
void FUN_0022697c(Animator *self)
{
  FUN_002269b8();
  FUN_002269c4(self);
  FUN_002269d0(self);
  FUN_002269dc(self);
}
