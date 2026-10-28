/* HSTMATCH module=hstp_trans_main.prx start=0x00051a2c end=0x00051ad8 symbol=FUN_00051a2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_00051d38 as taking a float and passed 2000.0f; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051d38(float);
extern void FUN_00051d40();
extern void FUN_00051d84();
extern void FUN_00051d8c();
extern void FUN_00051d94();
extern void FUN_00051d9c();

void FUN_00051a2c(int param_1)
{
  *(u32 *)(param_1 + 4) = 0xffffffff;
  *(u32 *)(param_1 + 8) = 0;
  *(u32 *)(param_1 + 0xc) = 0;
  *(u32 *)(param_1 + 0x10) = 0x3f800000;
  *(u32 *)(param_1 + 0x14) = 0x3f800000;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x2c) = 0;
  *(u32 *)(param_1 + 0x30) = 0;
  *(u32 *)(param_1 + 0x34) = 0;
  *(u32 *)(param_1 + 0x38) = 0;
  FUN_00051d38(2000.0f);
  FUN_00051d40(param_1,0);
  *(u8 *)(param_1 + 0x21) = 1;
  FUN_00051d9c(param_1,0);
  *(u8 *)(param_1 + 0x22) = 1;
  FUN_00051d84(param_1,0);
  FUN_00051d8c(param_1,0);
  FUN_00051d94(param_1,0);
}
