/* HSTMATCH module=hstp_trans_main.prx start=0x0023044c end=0x00230474 symbol=FUN_0023044c lang=c99 */
/* Clone of src/eboot/FUN_000eea50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

void FUN_0023044c(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_00108aec();
  }
}
