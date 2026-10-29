/* HSTMATCH module=hstp_trans_main.prx start=0x00122d88 end=0x00122dc0 symbol=FUN_00122d88 lang=c99 */
/* Clone of src/eboot/FUN_00117d38.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern void FUN_0001f4a0();
extern void FUN_0008c348();

/* Calls the first helper on the global object, then the second with 0x16 and two zeros. */
void FUN_00122d88(void)
{
  FUN_0008c348(DAT_003e19f0);
  FUN_0001f4a0(DAT_003e19f0,0x16,0,0);
}
