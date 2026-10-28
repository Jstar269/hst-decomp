/* HSTMATCH module=EBOOT.BIN start=0x000db788 end=0x000db7f4 symbol=FUN_000db788 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a3); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00338b48;
extern u8 DAT_003417bb;
extern u8 DAT_0034189b;
extern u8 DAT_003419bb;
extern void FUN_000db7f4();
extern void FUN_000db868();

void FUN_000db788(int param_1)
{
  if (DAT_00338b48 != '\0') {
    DAT_003417bb = 0;
    DAT_0034189b = 2;
    DAT_003419bb = 1;
    *(u32 *)(param_1 + 0xb4) = 1;
    *(u32 *)(param_1 + 0xc0) = 9;
  }
  FUN_000db7f4(param_1);
  FUN_000db868(param_1);
  *(u8 *)(param_1 + 0xb0) = 0;
}
