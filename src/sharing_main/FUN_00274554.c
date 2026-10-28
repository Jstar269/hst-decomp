/* HSTMATCH module=hstp_trans_main.prx start=0x00274554 end=0x00274588 symbol=FUN_00274554 lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2d70;
extern u32 * FUN_000688ec();

u32 * FUN_00274554(u32 *param_1)
{
  FUN_000688ec();
  *param_1 = (unsigned int)(&DAT_003b2d70);
  return param_1;
}
