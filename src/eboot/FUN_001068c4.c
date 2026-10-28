/* HSTMATCH module=EBOOT.BIN start=0x001068c4 end=0x001068d8 symbol=FUN_001068c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0027fc70();

void FUN_001068c4(char *param_1)
{
  FUN_0027fc70((u32 *)(param_1 + 0xd0),(u32 *)**(u32 **)(param_1 + 0x10),1);
}
