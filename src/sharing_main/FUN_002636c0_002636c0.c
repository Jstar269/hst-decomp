/* HSTMATCH module=hstp_trans_main.prx start=0x002636c0 end=0x00263794 symbol=FUN_002636c0 lang=c99 */
/* Clone of src/eboot/FUN_0025336c_0025336c.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d10cc;
extern u8 DAT_002d10d0;
extern u8 DAT_002d10d4;
extern u32 DAT_003e1a08;
extern u32 FUN_0008f170();
extern void FUN_0011988c();
extern u8 * FUN_001991d4();

void FUN_002636c0(int param_1,int param_2)
{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  u8 *puVar4;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar1 = (int)(FUN_001991d4(0x12));
  if (*(int *)(iVar1 + 4) == 0) {
    puVar4 = &DAT_002d10d4;
  }
  else if ((param_1 < 0) || ((row_ok = param_1 < *(int *)(*(int *)(iVar1 + 8) + 8)) == 0)) {
    puVar4 = &DAT_002d10d0;
  }
  else if ((param_2 < 0) ||
          (piVar3 = (int *)(row_offset = param_1 * 0xc, row_offset + *(int *)(iVar1 + 0xc)),
           (col_ok = param_2 < piVar3[1]) == 0)) {
    puVar4 = &DAT_002d10cc;
  }
  else {
    puVar4 = *(u8 **)(*piVar3 + param_2 * 4);
  }
  uVar2 = FUN_0008f170(DAT_003e1a08);
  FUN_0011988c(uVar2,puVar4,0);
}
