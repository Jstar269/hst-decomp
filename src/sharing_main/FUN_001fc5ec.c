/* HSTMATCH module=hstp_trans_main.prx start=0x001fc5ec end=0x001fc5fc symbol=FUN_001fc5ec lang=c99 */
/* Clone of src/eboot/FUN_001ee224.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern u32 FUN_001fd6dc();

void FUN_001fc5ec(void)
{
  FUN_001fd6dc(*(u32 *)(DAT_003e19f0 + 0xa0));
}
