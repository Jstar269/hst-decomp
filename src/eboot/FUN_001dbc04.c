/* HSTMATCH module=EBOOT.BIN start=0x001dbc04 end=0x001dbc40 symbol=FUN_001dbc04 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338714;
extern void FUN_0005f1e8();

void FUN_001dbc04(int param_1)
{
  if ((*(int *)(param_1 + 0x3c) != 0) && (*(u8 *)(param_1 + 0xcc) != '\0')) {
    FUN_0005f1e8(*(int *)(param_1 + 0x3c),DAT_00338714);
  }
}
