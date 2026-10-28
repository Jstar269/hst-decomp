/* HSTMATCH module=EBOOT.BIN start=0x0025336c end=0x00253440 symbol=FUN_0025336c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u32 DAT_003386c8;
extern u32 FUN_0008d994();
extern void FUN_00110a78();
extern u8 * FUN_0018c9f4();

void FUN_0025336c(int param_1,int param_2)
{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  u8 *puVar4;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar1 = (int)(FUN_0018c9f4(0x12));
  if (*(int *)(iVar1 + 4) == 0) {
    puVar4 = &DAT_002c0e20;
  }
  else if ((param_1 < 0) || ((row_ok = param_1 < *(int *)(*(int *)(iVar1 + 8) + 8)) == 0)) {
    puVar4 = &DAT_002c0e1c;
  }
  else if ((param_2 < 0) ||
          (piVar3 = (int *)(row_offset = param_1 * 0xc, row_offset + *(int *)(iVar1 + 0xc)),
           (col_ok = param_2 < piVar3[1]) == 0)) {
    puVar4 = &DAT_002c0e18;
  }
  else {
    puVar4 = *(u8 **)(*piVar3 + param_2 * 4);
  }
  uVar2 = FUN_0008d994(DAT_003386c8);
  FUN_00110a78(uVar2,puVar4,0);
}
