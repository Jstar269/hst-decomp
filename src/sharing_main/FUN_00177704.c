/* HSTMATCH module=hstp_trans_main.prx start=0x00177704 end=0x00177714 symbol=FUN_00177704 lang=c99 */
/* Clone of src/eboot/FUN_0016b540.c (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eb046;

bool FUN_00177704(void)
{
  return DAT_003eb046 != '\0';
}
