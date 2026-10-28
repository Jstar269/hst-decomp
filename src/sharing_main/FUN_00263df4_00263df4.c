/* HSTMATCH module=hstp_trans_main.prx start=0x00263df4 end=0x00263ee8 symbol=FUN_00263df4 lang=c99 */
/* Clone of src/eboot/FUN_00253974_00253974.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused the loaded count as the range predicate and materialized the row offset before base addition; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d10cc;
extern u8 DAT_002d10d0;
extern u8 DAT_002d10d4;
extern u8 DAT_002dac84;
extern u8 DAT_002dac80;
extern u8 * FUN_001991d4();

u8 * FUN_00263df4(int param_1,int param_2)
{
  int iVar1;
  u8 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  switch (param_1) {
    case 5:
    case 6:
      param_2 = param_2 + 1;
      break;
  }
  iVar4 = *(int *)(&DAT_002dac84 + param_1 * 8);
  iVar1 = (int)(FUN_001991d4(*(u32 *)(param_1 * 8 + (int)&DAT_002dac80)));
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002d10d4;
  }
  else if ((iVar4 < 0) || (iVar6 = *(int *)(*(int *)(iVar1 + 8) + 8), (iVar6 = iVar4 < iVar6) == 0)) {
    puVar2 = &DAT_002d10d0;
  }
  else if ((param_2 < 0) ||
          (iVar5 = iVar4 * 0xc, piVar3 = (int *)(iVar5 + *(int *)(iVar1 + 0xc)), iVar6 = piVar3[1], iVar6 = param_2 < iVar6, iVar6 == 0)) {
    puVar2 = &DAT_002d10cc;
  }
  else {
    puVar2 = *(u8 **)(*piVar3 + param_2 * 4);
  }
  return puVar2;
}

