/* HSTMATCH module=hstp_trans_main.prx start=0x000f4414 end=0x000f443c symbol=FUN_000f4414 lang=c99 */
/* Clone of src/eboot/FUN_000eea50.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

void FUN_000f4414(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_00108aec();
  }
}
