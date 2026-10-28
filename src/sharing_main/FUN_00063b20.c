/* HSTMATCH module=hstp_trans_main.prx start=0x00063b20 end=0x00063b78 symbol=FUN_00063b20 lang=c99 */
/* Clone of src/eboot/FUN_00062c5c.c (hstclone.py tag u1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: default MWCC profile, s0 >= 0 and nested if; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00077968(int, u32, u32);
extern void FUN_00078edc(int, int);
extern int FUN_00078f74(int);

int FUN_00063b20(u32 param_1, u32 param_2)
{
  int iVar1 = FUN_00077968(0xffffffff, param_1, param_2);
  if (iVar1 >= 0) {
    if (FUN_00078f74(iVar1) == 0) {
      FUN_00078edc(iVar1, 2);
    }
  }
  return iVar1;
}
