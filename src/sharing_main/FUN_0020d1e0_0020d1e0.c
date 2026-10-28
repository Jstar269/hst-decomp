/* HSTMATCH module=hstp_trans_main.prx start=0x0020d1e0 end=0x0020d294 symbol=FUN_0020d1e0 lang=c99 */
/* Clone of src/eboot/FUN_001fea10_001fea10.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d10cc;
extern u8 DAT_002d10d0;
extern u8 DAT_002d10d4;
extern u8 * FUN_001991d4();

u8 * FUN_0020d1e0(u32 param_1,int param_2,int param_3)
{
  int iVar1;
  u8 *puVar2;
  int *piVar3;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar1 = (int)(FUN_001991d4());
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002d10d4;
  }
  else if ((param_2 < 0) || ((row_ok = param_2 < *(int *)(*(int *)(iVar1 + 8) + 8)) == 0)) {
    puVar2 = &DAT_002d10d0;
  }
  else if ((param_3 < 0) ||
          (piVar3 = (int *)(row_offset = param_2 * 0xc, row_offset + *(int *)(iVar1 + 0xc)),
           (col_ok = param_3 < piVar3[1]) == 0)) {
    puVar2 = &DAT_002d10cc;
  }
  else {
    puVar2 = *(u8 **)(*piVar3 + param_3 * 4);
  }
  return puVar2;
}
