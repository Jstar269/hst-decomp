/* HSTMATCH module=EBOOT.BIN start=0x002021b4 end=0x002021d4 symbol=FUN_002021b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002021b4(float param_1,u8 *param_2)
{
  if (*param_2 != '\0') {
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) + param_1;
  }
}
