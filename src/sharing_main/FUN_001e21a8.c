/* HSTMATCH module=hstp_trans_main.prx start=0x001e21a8 end=0x001e21b8 symbol=FUN_001e21a8 lang=c99 */
/* Clone of src/eboot/FUN_001d43a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001e21a8(int param_1)
{
  return (*(u16 *)(param_1 + 0xe) & 3) != 0;
}
