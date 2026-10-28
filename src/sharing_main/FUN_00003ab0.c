/* HSTMATCH module=hstp_trans_main.prx start=0x00003ab0 end=0x00003ae4 symbol=FUN_00003ab0 lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b021c;
extern u32 * FUN_00003ae4();

u32 * FUN_00003ab0(u32 *param_1)
{
  FUN_00003ae4();
  *param_1 = (unsigned int)(&DAT_003b021c);
  return param_1;
}
