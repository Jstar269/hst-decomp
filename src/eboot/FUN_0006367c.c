/* HSTMATCH module=EBOOT.BIN start=0x0006367c end=0x000636c4 symbol=FUN_0006367c lang=c99 */
/* Clone of src/sharing_main/FUN_00064540.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030709c;
extern u32 * FUN_00062f68();

u32 * FUN_0006367c(u32 *param_1)
{
  FUN_00062f68();
  *param_1 = (unsigned int)(&DAT_0030709c);
  *(u8 *)(param_1 + 0x14) = 0;
  *(u8 *)((int)param_1 + 0x51) = 0;
  *(u8 *)((int)param_1 + 0x52) = 0;
  *(u8 *)((int)param_1 + 0x53) = 0;
  param_1[0x15] = 0;
  return param_1;
}
