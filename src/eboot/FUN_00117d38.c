/* HSTMATCH module=EBOOT.BIN start=0x00117d38 end=0x00117d70 symbol=FUN_00117d38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_0001f558();
extern void FUN_0008ac88();

/* Calls the first helper on the global object, then the second with 0x16 and two zeros. */
void FUN_00117d38(void)
{
  FUN_0008ac88(DAT_003386b0);
  FUN_0001f558(DAT_003386b0,0x16,0,0);
}
