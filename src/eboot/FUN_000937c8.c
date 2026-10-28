/* HSTMATCH module=EBOOT.BIN start=0x000937c8 end=0x000937f0 symbol=FUN_000937c8 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00057b08();

void FUN_000937c8(int param_1,u32 *param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00057b08(*(int *)(param_1 + 0x58),param_2);
  }
}
