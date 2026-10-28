/* HSTMATCH module=hstp_trans_main.prx start=0x00228668 end=0x0022869c symbol=FUN_00228668 lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b28a4;
extern u32 * FUN_0005b6bc();

u32 * FUN_00228668(u32 *param_1)
{
  FUN_0005b6bc();
  *param_1 = (unsigned int)(&DAT_003b28a4);
  return param_1;
}
