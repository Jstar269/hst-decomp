/* HSTMATCH module=EBOOT.BIN start=0x001a57d0 end=0x001a5808 symbol=FUN_001a57d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001aedc8();
extern void FUN_001bae28();

void FUN_001a57d0(int param_1)
{
  if (0 < *(int *)(param_1 + 0x3c)) {
    FUN_001aedc8(param_1 + 0x68);
    FUN_001bae28(*(u32 *)(param_1 + 0x88));
  }
}
