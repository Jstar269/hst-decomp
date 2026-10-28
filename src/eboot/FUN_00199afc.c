/* HSTMATCH module=EBOOT.BIN start=0x00199afc end=0x00199b40 symbol=FUN_00199afc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034a678;
extern void FUN_00199398();
extern void FUN_002345f8();

void FUN_00199afc(int param_1)
{
  FUN_00199398(*(u32 *)(param_1 + 0x3c));
  if (*(u8 *)(*(int *)(param_1 + 0x3c) + 0x24) != '\0') {
    FUN_002345f8(&DAT_0034a678);
  }
}
