/* HSTMATCH module=EBOOT.BIN start=0x000650e0 end=0x000650e8 symbol=FUN_000650e0 lang=c99 */
/* CSV table reader: row count (this+8); see docs/DATA-TABLES.md */
/* Clone of src/eboot/FUN_0027edb4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000650e0(int param_1)
{
  return *(u32 *)(param_1 + 8);
}
