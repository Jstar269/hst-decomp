/* HSTMATCH module=hstp_trans_main.prx start=0x001b2d9c end=0x001b2dd4 symbol=FUN_001b2d9c lang=c99 */
/* Clone of src/eboot/FUN_001a57d0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001bc4a0();
extern void FUN_001c8b70();

void FUN_001b2d9c(int param_1)
{
  if (0 < *(int *)(param_1 + 0x3c)) {
    FUN_001bc4a0(param_1 + 0x68);
    FUN_001c8b70(*(u32 *)(param_1 + 0x88));
  }
}
