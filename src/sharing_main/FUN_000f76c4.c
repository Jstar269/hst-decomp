/* HSTMATCH module=hstp_trans_main.prx start=0x000f76c4 end=0x000f76ec symbol=FUN_000f76c4 lang=c99 */
/* Clone of src/eboot/FUN_000f1ffc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

void FUN_000f76c4(int param_1)
{
  if (*(u8 *)(param_1 + 0x78) == '\0') {
    FUN_00108aec();
  }
}
