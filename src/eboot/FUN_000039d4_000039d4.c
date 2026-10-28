/* HSTMATCH module=EBOOT.BIN start=0x000039d4 end=0x000039e8 symbol=FUN_000039d4 lang=c99 */
/* Clone of src/sharing_main/FUN_000039d4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000039d4(int param_1,int param_2)
{
  return ~(param_2 - 1U) & param_1 + (param_2 - 1U);
}
