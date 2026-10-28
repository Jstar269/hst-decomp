/* HSTMATCH module=EBOOT.BIN start=0x001c352c end=0x001c35ec symbol=FUN_001c352c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte-check return and float/pointer helper arguments; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415ac;
extern u32 DAT_003415d4;
extern void *DAT_0034a114;
extern void FUN_00103628();
extern int FUN_001155c0();
extern u32 FUN_001156d4();
extern void FUN_001905b8();
extern void FUN_001c6cfc(float,void *,int);
extern void FUN_001ca8f0();
extern void FUN_001cd3d8();
extern void FUN_001cd88c();

void FUN_001c352c(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001155c0(DAT_003415ac);
  if (iVar1 != 0) {
    FUN_00103628(DAT_003415ac,1);
    iVar1 = FUN_001156d4(DAT_003415ac);
    if (iVar1 == 0) {
      FUN_001ca8f0(*(u32 *)(param_1 + 0x18));
      *(u32 *)(param_1 + 0xe8) = 1;
      *(u8 *)(param_1 + 0xf0) = 0;
      FUN_001905b8(DAT_003415d4,3);
      FUN_001cd88c(param_1,8,1);
      FUN_001cd3d8(*(u32 *)(param_1 + 0x18));
    }
    else {
      FUN_001cd88c(param_1,0,1);
      FUN_001c6cfc(1.0f,DAT_0034a114,1);
    }
  }
}
