/* HSTMATCH module=hstp_trans_main.prx start=0x002bea30 end=0x002bea40 symbol=FUN_002bea30 lang=c99 */
/* Clone of src/eboot/FUN_002af1ac.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003eb004;

u32 FUN_002bea30(void)
{
  return *(u32 *)(DAT_003eb004 + 0x1054);
}
