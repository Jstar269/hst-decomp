/* HSTMATCH module=EBOOT.BIN start=0x001cb860 end=0x001cb980 symbol=FUN_001cb860 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u8 DAT_002ea308;
extern void FUN_0018a950();
extern u8 * FUN_0018c9f4();
extern void FUN_001cd88c();
extern u32 FUN_0022977c();

void FUN_001cb860(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  u8 *puVar2;
  int *piVar3;
  int iVar4;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar4 = *(int *)(param_1 + 0x15c);
  if (param_4 < 0) {
    iVar1 = *(int *)(iVar4 + 0x24);
  }
  else {
    iVar1 = (int)(FUN_0018c9f4(param_4));
  }
  *(u8 *)(iVar4 + 99) = 0;
  *(u8 *)(iVar4 + 100) = 0;
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
  *(u8 **)(iVar4 + 0x68) = puVar2;
  *(u32 *)(iVar4 + 0x6c) = 0;
  *(u32 *)(iVar4 + 0x70) = 0;
  FUN_0018a950(*(u32 *)(iVar4 + 0x20),&DAT_002ea308);
  FUN_001cd88c(iVar4,2,1);
  *(u32 *)(iVar4 + 0x74) = 0xffffffff;
  *(u32 *)(iVar4 + 0x78) = 0xffffffff;
  FUN_0022977c(iVar4 + 0x34,param_2,param_3);
}
