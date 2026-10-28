/* HSTMATCH module=hstp_trans_main.prx start=0x00096fb0 end=0x00096fec symbol=FUN_00096fb0 lang=c99 */
/* Clone of src/eboot/FUN_00094fa4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0544;
extern u32 * FUN_000577ec();
extern void FUN_00097048();

u32 * FUN_00096fb0(u32 *param_1)
{
  FUN_000577ec();
  *param_1 = (unsigned int)(&DAT_003b0544);
  FUN_00097048(param_1);
  return param_1;
}
