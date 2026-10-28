/* HSTMATCH module=hstp_trans_main.prx start=0x001a8658 end=0x001a8688 symbol=FUN_001a8658 lang=c99 */
/* Clone of src/eboot/FUN_0019b460.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011177c();

void FUN_001a8658(int param_1)
{
  FUN_0011177c();
  *(u32 *)(param_1 + 0x138) = 0;
  *(u32 *)(param_1 + 0x130) = 0;
  *(u32 *)(param_1 + 0x134) = 0;
}
