/* HSTMATCH module=EBOOT.BIN start=0x0005eaa8 end=0x0005eafc symbol=FUN_0005eaa8 lang=c99 */
/* Clone of src/sharing_main/FUN_0005f898.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030704c;
extern u32 * FUN_00054ed4();
extern void FUN_0005eb98();

u32 * FUN_0005eaa8(u32 *param_1)
{
  FUN_00054ed4();
  *param_1 = (unsigned int)(&DAT_0030704c);
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  FUN_0005eb98(param_1);
  return param_1;
}
