/* HSTMATCH module=hstp_trans_main.prx start=0x000688ec end=0x00068954 symbol=FUN_000688ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0438;
extern u32 * FUN_0001ec44();
extern void FUN_00068d80();
extern u32 * FUN_00068f7c();

u32 * FUN_000688ec(u32 *param_1)
{
  u8 auStack_4 [4];
  u32 local_8;
  u32 *local_c;
  
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b0438);
  FUN_00068f7c(param_1 + 0xf);
  local_c = param_1 + 0x10;
  local_8 = param_1[0x11];
  FUN_00068d80(auStack_4,param_1 + 0xf,&local_8,&local_c);
  param_1[0x12] = 0x3f800000;
  return param_1;
}
