/* HSTMATCH module=EBOOT.BIN start=0x0026c470 end=0x0026c47c symbol=FUN_0026c470 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0026c470(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x58) + 0xdc);
}
