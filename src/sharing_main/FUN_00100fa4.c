/* HSTMATCH module=hstp_trans_main.prx start=0x00100fa4 end=0x00100fb0 symbol=FUN_00100fa4 lang=c99 */
/* Clone of src/eboot/FUN_000fb868.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0020ac00();

void FUN_00100fa4(int param_1)
{
  FUN_0020ac00(*(u32 *)(param_1 + 0x40),0);
}
