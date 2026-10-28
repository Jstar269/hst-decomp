/* HSTMATCH module=hstp_trans_main.prx start=0x00094c5c end=0x00094cb0 symbol=FUN_00094c5c lang=c99 */
/* Clone of src/eboot/cleanup_00092dc8.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: test the first field directly before loading the second; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000569f4();
extern void FUN_00057fa0();

void FUN_00094c5c(int param_1)
{
  int iVar1;

  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00057fa0(*(int *)(param_1 + 0x58));
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != 0) {
    FUN_000569f4(iVar1,1);
    *(u32 *)(param_1 + 0x6c) = 0;
  }
  *(u32 *)(param_1 + 0x68) = 0xffffffff;
}
