/* HSTMATCH module=hstp_trans_main.prx start=0x001d18b8 end=0x001d1978 symbol=FUN_001d18b8 lang=c99 */
/* Clone of src/eboot/FUN_001c352c_001c352c.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the u8-check return and float/pointer helper arguments; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8ec;
extern u32 DAT_003ea914;
extern void *DAT_003f344c;
extern void FUN_00108f54();
extern int FUN_001204dc();
extern u32 FUN_001205f0();
extern void FUN_0019cdc8();
extern void FUN_001d5124(float,void *,int);
extern void FUN_001d8ec4();
extern void FUN_001dbab4();
extern void FUN_001dbf68();

void FUN_001d18b8(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001204dc(DAT_003ea8ec);
  if (iVar1 != 0) {
    FUN_00108f54(DAT_003ea8ec,1);
    iVar1 = FUN_001205f0(DAT_003ea8ec);
    if (iVar1 == 0) {
      FUN_001d8ec4(*(u32 *)(param_1 + 0x18));
      *(u32 *)(param_1 + 0xe8) = 1;
      *(u8 *)(param_1 + 0xf0) = 0;
      FUN_0019cdc8(DAT_003ea914,3);
      FUN_001dbf68(param_1,8,1);
      FUN_001dbab4(*(u32 *)(param_1 + 0x18));
    }
    else {
      FUN_001dbf68(param_1,0,1);
      FUN_001d5124(1.0f,DAT_003f344c,1);
    }
  }
}
