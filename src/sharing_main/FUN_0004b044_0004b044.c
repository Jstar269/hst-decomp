/* HSTMATCH module=hstp_trans_main.prx start=0x0004b044 end=0x0004b13c symbol=FUN_0004b044 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: reversed the status arms to preserve the retail logger branch; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037607c;
extern u8 DAT_003ba4b0;
extern char DAT_00376060[];
extern bool FUN_0002b824();
extern u32 FUN_0002b8f4();
extern void FUN_00048fb8();
extern void FUN_00049020();
extern void FUN_0004b13c();
extern void FUN_0004b1bc();
extern void FUN_0004b2d4();
extern u32 FUN_0004cd8c();
extern void FUN_0004f864();

u32 FUN_0004b044(int *param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  int iVar1;
  
  FUN_0004b13c(param_1);
  iVar1 = FUN_0004cd8c(param_2,0,0x10,1);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_00048fb8();
    iVar1 = FUN_0002b8f4(*param_1);
    FUN_00049020();
    if (iVar1 != 0) {
      FUN_0004f864((int)&DAT_003ba4b0,iVar1,DAT_00376060,0x158,&DAT_0037607c);
    } else {
      FUN_0002b824(*param_1,1);
      FUN_0004b1bc(param_1,param_3);
      FUN_0004b2d4(param_1,param_4,param_5);
      return 1;
    }
  }
  FUN_0004b13c(param_1);
  return 0;
}
