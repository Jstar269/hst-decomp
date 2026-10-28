/* HSTMATCH module=EBOOT.BIN start=0x00091830 end=0x000918ac symbol=FUN_00091830 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307264;
extern void FUN_00091af4();
extern void FUN_00091cbc();
extern u32 * FUN_0009444c();

u32 * FUN_00091830(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00307264);
  FUN_0009444c(param_1 + 0x20);
  FUN_0009444c(param_1 + 0x2c);
  param_1[10] = 0;
  param_1[0xc] = 0xbf800000;
  param_1[0xd] = 0xbf800000;
  param_1[0xe] = 0xbf800000;
  param_1[0xf] = 0xbf800000;
  param_1[0x10] = 0;
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  FUN_00091af4(param_1);
  FUN_00091cbc(param_1);
  return param_1;
}
