/* HSTMATCH module=hstp_trans_main.prx start=0x00185a08 end=0x00185adc symbol=FUN_00185a08 lang=c99 rodata=0x002d2488 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_00387a88[];
extern char DAT_00387ac4[];
extern char DAT_00387c04[];
extern void FUN_00177f38();

u32 FUN_00185a08(int param_1,u32 param_2,int param_3)
{
  u32 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    uVar1 = **(u32 **)(*(int *)(param_1 + 0x1e4) + param_3 * 4);
    break;
  case 2:
    uVar1 = **(u32 **)(*(int *)(param_1 + 0x1fc) + param_3 * 4);
    break;
  case 3:
  case 4:
    uVar1 = **(u32 **)(*(int *)(param_1 + 0x208) + param_3 * 4);
    break;
  case 5:
    if (*(int **)(param_1 + 0x1d4) == (int *)0x0) {
      FUN_00177f38(DAT_00387a88,DAT_00387c04,
                   DAT_00387ac4,0x1e39);
      do {
                    
      } while( true );
    }
    uVar1 = **(u32 **)(**(int **)(param_1 + 0x1d4) + param_3 * 4);
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}
