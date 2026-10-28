/* HSTMATCH module=EBOOT.BIN start=0x002ada5c end=0x002ada80 symbol=FUN_002ada5c lang=c99 */
/* Prize score table: data/prize/score.csv; see docs/DATA-TABLES.md */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00302c6c;
extern u8 DAT_0034b5a0;
extern char DAT_00302c54[];
extern u32 FUN_000651b8();

void FUN_002ada5c(void)
{
  FUN_000651b8((int *)&DAT_0034b5a0,DAT_00302c54,1,0,&DAT_00302c6c);
}
