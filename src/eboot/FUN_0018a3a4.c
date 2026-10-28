/* HSTMATCH module=EBOOT.BIN start=0x0018a3a4 end=0x0018a468 symbol=FUN_0018a3a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u8 DAT_002e0974;
extern u8 DAT_0030779c;
extern u8 DAT_003090e0;
extern u8 DAT_00309124;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();
extern u32 * FUN_00217440();

u32 * FUN_0018a3a4(u32 *param_1)
{
  FUN_000fc0a0();
  FUN_00056098(param_1 + 0xc);
  *param_1 = (unsigned int)(&DAT_0030779c);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  FUN_00056098(param_1 + 0x20);
  param_1[0x30] = (unsigned int)(&DAT_002e0974);
  FUN_000fc00c(param_1,&DAT_002bc410);
  FUN_000fbf84(param_1 + 0x20,&DAT_002bc410);
  FUN_00217440(param_1 + 0x34);
  *param_1 = (unsigned int)(&DAT_003090e0);
  param_1[0x34] = (unsigned int)(&DAT_00309124);
  param_1[0x41] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  return param_1;
}
