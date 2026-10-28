/* HSTMATCH module=hstp_trans_main.prx start=0x000aab70 end=0x000aaba8 symbol=FUN_000aab70 lang=c99 */
/* Clone of src/eboot/FUN_000a817c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e84;
extern void FUN_000e0924();
extern void FUN_000e0a10();

void FUN_000aab70(int param_1)
{
  FUN_000e0a10(DAT_003e1e84,*(u32 *)(param_1 + 0x144),*(u32 *)(param_1 + 0x148));
  FUN_000e0924(DAT_003e1e84);
}
