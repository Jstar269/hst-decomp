/* HSTMATCH module=EBOOT.BIN start=0x00053670 end=0x00053718 symbol=FUN_00053670 lang=c99 */
/* Clone of src/sharing_main/FUN_00054130.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000537a0();
extern u32 FUN_000537bc();

int FUN_00053670(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  *(u32 *)(param_1 + 0x18) = 0;
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x20) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x2c) = 0;
  FUN_000537a0();
  FUN_000537bc(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return param_1;
}
