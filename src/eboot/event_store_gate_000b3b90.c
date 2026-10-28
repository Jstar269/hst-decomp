/* HSTMATCH module=EBOOT.BIN start=0x000b3b90 end=0x000b3c68 symbol=FUN_000b3b90 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003386b8 and the flag at +0x1b4 typed as bytes, the gate split into bVar1 = DAT != 0 then bVar1 = (flag != 0) ^ 1 with an int flag; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u8 *DAT_003386b0;
extern u8 DAT_003386b8;
extern u8 *DAT_00338af0;
extern int FUN_000c4ba0();
extern int FUN_001b55a0();

void FUN_000b3b90(int param_1,int param_2,u32 param_3)
{
  int bVar1;
  int iVar2;

  if ((param_2 != 0xd0) &&
     (FUN_001b55a0(*(u32 *)(DAT_003386b0 + 0xa8),*(u32 *)(param_1 + 0x148),param_2,
                   param_3), *(int *)(param_1 + 0x3c) != 7)) {
    *(int *)(param_1 + 0x5b4) = param_2;
    *(char *)(param_1 + 0x5b8) = (char)param_3;
    bVar1 = DAT_003386b8 != 0;
    if (bVar1) {
      bVar1 = (*(unsigned char *)(param_1 + 0x1b4) != 0) ^ 1;
    }
    if (((bVar1) && (DAT_00338af0 != 0)) && (param_2 != 0xd0)) {
      iVar2 = FUN_000c4ba0(DAT_00338af0,*(u32 *)(param_1 + 0x148));
      *(u32 *)(iVar2 + 0x70) = *(u32 *)(DAT_00338af0 + 0x780);
      *(int *)(iVar2 + 0x68) = param_2;
      *(char *)(iVar2 + 0x6c) = (char)param_3;
    }
  }
}
