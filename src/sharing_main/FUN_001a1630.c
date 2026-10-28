/* HSTMATCH module=hstp_trans_main.prx start=0x001a1630 end=0x001a1644 symbol=FUN_001a1630 lang=c99 */
/* Clone of src/eboot/FUN_00194e20.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003eb004;
extern void FUN_001a13b4();

void FUN_001a1630(u32 param_1)
{
  FUN_001a13b4(param_1,*(u16 *)(DAT_003eb004 + 0x1034),0x20);
}
