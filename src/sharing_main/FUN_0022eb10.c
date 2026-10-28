/* HSTMATCH module=hstp_trans_main.prx start=0x0022eb10 end=0x0022eb38 symbol=FUN_0022eb10 lang=c99 */
/* Clone of src/eboot/FUN_000eea50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

void FUN_0022eb10(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_00108aec();
  }
}
