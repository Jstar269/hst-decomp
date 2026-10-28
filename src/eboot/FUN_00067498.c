/* HSTMATCH module=EBOOT.BIN start=0x00067498 end=0x00067500 symbol=FUN_00067498 lang=c99 */
/* Clone of src/sharing_main/FUN_000688ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030716c;
extern u32 * FUN_0001f06c();
extern void FUN_0006792c();
extern u32 * FUN_00067b28();

u32 * FUN_00067498(u32 *param_1)
{
  u8 auStack_4 [4];
  u32 local_8;
  u32 *local_c;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_0030716c);
  FUN_00067b28(param_1 + 0xf);
  local_c = param_1 + 0x10;
  local_8 = param_1[0x11];
  FUN_0006792c(auStack_4,param_1 + 0xf,&local_8,&local_c);
  param_1[0x12] = 0x3f800000;
  return param_1;
}
