/* HSTMATCH module=hstp_trans_main.prx start=0x0008e25c end=0x0008e2b0 symbol=FUN_0008e25c lang=c99 */
/* Clone of src/eboot/FUN_0008cb14_0008cb14.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: update guard and old-state reload; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003787a8;
extern u32 DAT_003e1a04;
extern void FUN_0011988c();

struct OldStateView { char pad[0x9c0]; int state; };

void FUN_0008e25c(int param_1,int param_2,int param_3)
{
  int old = *(int *)(param_1 + 0x9c0);
  if (old == param_2 && param_3 == 0) {
    return;
  }
  old = ((struct OldStateView *)param_1)->state;
  *(int *)(param_1 + 0x9c4) = old;
  *(int *)(param_1 + 0x9c0) = param_2;
  *(u8 *)(param_1 + 0x9c8) = 1;
  FUN_0011988c(DAT_003e1a04,&DAT_003787a8,0);
}
