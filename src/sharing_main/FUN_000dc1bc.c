/* HSTMATCH module=hstp_trans_main.prx start=0x000dc1bc end=0x000dc20c symbol=FUN_000dc1bc lang=c99 */
/* Clone of src/eboot/FUN_000d83b8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b08ac;
extern void FUN_000007f4();
extern void FUN_000dc20c();
extern void FUN_000dc264();

u32 * FUN_000dc1bc(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b08ac);
  FUN_000007f4((int)(param_1 + 1),FUN_000dc264,FUN_000dc20c,0xc,6);
  return param_1;
}
