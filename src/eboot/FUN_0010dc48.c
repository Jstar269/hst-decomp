/* HSTMATCH module=EBOOT.BIN start=0x0010dc48 end=0x0010dcf4 symbol=FUN_0010dc48 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u8 DAT_0030779c;
extern u8 DAT_00307e38;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();

u32 * FUN_0010dc48(u32 *param_1,u32 param_2)
{
  FUN_000fc0a0(param_1);
  FUN_00056098(param_1 + 0xc);
  *param_1 = (unsigned int)(&DAT_0030779c);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  FUN_00056098(param_1 + 0x20);
  param_1[0x30] = param_2;
  FUN_000fc00c(param_1,&DAT_002bc410);
  FUN_000fbf84(param_1 + 0x20,&DAT_002bc410);
  *param_1 = (unsigned int)(&DAT_00307e38);
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  return param_1;
}
