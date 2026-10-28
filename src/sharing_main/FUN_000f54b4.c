/* HSTMATCH module=hstp_trans_main.prx start=0x000f54b4 end=0x000f54f0 symbol=FUN_000f54b4 lang=c99 */
/* Clone of src/eboot/FUN_000efdec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005ffd8();
extern void FUN_00108aec();

void FUN_000f54b4(int param_1)
{
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    FUN_00108aec();
    FUN_0005ffd8(*(u32 *)(param_1 + 0x90),*(u32 *)(param_1 + 0x9c));
  }
}
