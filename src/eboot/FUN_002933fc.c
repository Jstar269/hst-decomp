/* HSTMATCH module=EBOOT.BIN start=0x002933fc end=0x0029343c symbol=FUN_002933fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002933fc(int param_1)
{
  u32 uVar1;
  
  uVar1 = 0;
  if (((*(u8 *)(param_1 + 0x4d) != '\0') && (*(u8 *)(param_1 + 0x40) == '\0')) &&
     (*(float *)(param_1 + 0x38) <= 31.0f)) {
    uVar1 = 1;
  }
  return uVar1;
}
