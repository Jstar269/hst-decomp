/* HSTMATCH module=EBOOT.BIN start=0x001ff554 end=0x001ff5a4 symbol=FUN_001ff554 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: made the positive early return explicit and restored the tested global pointer as the helper argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386c8;
extern u32 DAT_00338ac4;
extern int FUN_000be7b4(u32 param_1);

int FUN_001ff554(void)
{
  if (DAT_003386c8 != 0 && DAT_00338ac4 != 0 &&
      FUN_000be7b4(DAT_00338ac4) != 0)
    return 1;
  return 0;
}
