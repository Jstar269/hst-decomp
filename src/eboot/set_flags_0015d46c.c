/* HSTMATCH module=EBOOT.BIN start=0x0015d46c end=0x0015d4bc symbol=FUN_0015d46c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the first global is a byte store (undefined1), the FUN_0022cd60 result is typed as a struct pointer with byte members at 0xf0/0x13d; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern u32 DAT_002dcc1c;
extern u8 DAT_00340408;
extern char DAT_0034a678[];
extern ProfileData *FUN_0022cd60();
extern void FUN_00234158();

void FUN_0015d46c(void)
{
  ProfileData *profile;

  DAT_00340408 = 0;
  DAT_002dcc1c = 0x1f;
  profile = FUN_0022cd60();
  profile->flag_bits |= 4;
  profile->unk13d = 1;
  FUN_00234158(DAT_0034a678, 0x4b);
}
