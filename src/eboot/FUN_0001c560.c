/* HSTMATCH module=EBOOT.BIN start=0x0001c560 end=0x0001c604 symbol=FUN_0001c560 lang=c99 */
/* Clone of src/sharing_main/FUN_0001c090.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: positive-path guard, retained intermediate pointer store, and u8-offset expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0001c204();

u32 FUN_0001c560(int *param_1)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_0001c204();
  if (iVar1 >= 0) {
    if (iVar1 < param_1[1]) {
      iVar1 = *param_1 + iVar1 * 8;
      param_1[2] = iVar1 + 8;
      param_1[2] = param_1[2] + 4;
      param_1[5] = *(int *)(iVar1 + 8);
      uVar2 = *(u32 *)param_1[2];
      param_1[8] = uVar2;
      param_1[2] = (int)((char *)*param_1 + ((uVar2 & 0xfffffff) << 2));
      param_1[8] = (u32)param_1[8] >> 0x1c;
      return 1;
    }
  }
  param_1[2] = 0;
  param_1[5] = 0;
  return 0;
}
