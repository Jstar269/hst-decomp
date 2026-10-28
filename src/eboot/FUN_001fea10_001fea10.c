/* HSTMATCH module=EBOOT.BIN start=0x001fea10 end=0x001feac4 symbol=FUN_001fea10 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u8 * FUN_0018c9f4();

u8 * FUN_001fea10(u32 param_1,int param_2,int param_3)
{
  int iVar1;
  u8 *puVar2;
  int *piVar3;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar1 = (int)(FUN_0018c9f4());
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002c0e20;
  }
  else if ((param_2 < 0) || ((row_ok = param_2 < *(int *)(*(int *)(iVar1 + 8) + 8)) == 0)) {
    puVar2 = &DAT_002c0e1c;
  }
  else if ((param_3 < 0) ||
          (piVar3 = (int *)(row_offset = param_2 * 0xc, row_offset + *(int *)(iVar1 + 0xc)),
           (col_ok = param_3 < piVar3[1]) == 0)) {
    puVar2 = &DAT_002c0e18;
  }
  else {
    puVar2 = *(u8 **)(*piVar3 + param_3 * 4);
  }
  return puVar2;
}
