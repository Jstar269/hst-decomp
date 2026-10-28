/* HSTMATCH module=EBOOT.BIN start=0x00101590 end=0x00101630 symbol=FUN_00101590 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00101798(int *param_1,int param_2,int param_3,u32 param_4,u32 param_5, u32 param_6,u32 param_7);
extern void FUN_00107174(int *param_1,u32 param_2);

void FUN_00101590(int param_1,u32 *param_2,u32 param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(u32 *)(param_1 + 0x18) < param_3)) {
    FUN_00107174((int *)(param_1 + 0x10),(u32)(param_3));
  }
  iVar1 = 0;
  if (0 < (int)param_3) {
    do {
      FUN_00101798((int *)(param_1),(int)(*param_2),(int)(param_2[1]),(u32)((int)*(short *)(param_2 + 2)),(u32)((int)*(short *)((int)param_2 + 10)),(u32)((int)*(short *)(param_2 + 3)),(u32)(param_2[4]));
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 5;
    } while (iVar1 < (int)param_3);
  }
}
