/* HSTMATCH module=EBOOT.BIN start=0x00031b40 end=0x00031b48 symbol=FUN_00031b40 lang=c99 */
/* Clone of src/eboot/FUN_001d0608.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u16 FUN_00031b40(int param_1)
{
  return *(u16 *)(param_1 + 6);
}
