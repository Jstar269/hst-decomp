/* HSTMATCH module=EBOOT.BIN start=0x0004648c end=0x000464ec symbol=FUN_0004648c lang=c99 */
/* Clone of src/sharing_main/function_0004658c.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_000464ec as int and split the short-circuit checks into early guards; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002d0220;
extern u32 DAT_00311000;
extern u32 DAT_0034a678;
extern int FUN_000464ec();
extern void FUN_00060224();

void FUN_0004648c(void)
{
  if (FUN_000464ec() == 0) return;
  if (DAT_00311000 == 0) return;
  if (DAT_002d0220 == 0) return;
  if (DAT_0034a678 == 0x21) return;
  FUN_00060224(DAT_00311000,0);
}
