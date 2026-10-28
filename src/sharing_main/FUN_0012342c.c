/* HSTMATCH module=hstp_trans_main.prx start=0x0012342c end=0x00123480 symbol=FUN_0012342c lang=c99 */
/* Clone of src/eboot/FUN_00118258.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b12c8;
extern u32 DAT_003e47a0;
extern u32 * FUN_0001ec44();
extern u32 FUN_00123530();
extern u32 FUN_001235f8();
extern void FUN_0012376c();

u32 * FUN_0012342c(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b12c8);
  FUN_001235f8(param_1 + 0xb8);
  FUN_00123530(param_1 + 0xbe);
  DAT_003e47a0 = (unsigned int)(param_1);
  FUN_0012376c(param_1);
  return param_1;
}
