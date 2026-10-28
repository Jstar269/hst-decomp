/* HSTMATCH module=hstp_trans_main.prx start=0x0020dd24 end=0x0020dd74 symbol=FUN_0020dd24 lang=c99 */
/* Clone of src/eboot/FUN_001ff554.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: made the positive early return explicit and restored the tested global pointer as the helper argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1a08;
extern u32 DAT_003e1e04;
extern int FUN_000c1e54(u32 param_1);

int FUN_0020dd24(void)
{
  if (DAT_003e1a08 != 0 && DAT_003e1e04 != 0 &&
      FUN_000c1e54(DAT_003e1e04) != 0)
    return 1;
  return 0;
}
