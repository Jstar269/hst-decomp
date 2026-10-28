/* HSTMATCH module=EBOOT.BIN start=0x001a49dc end=0x001a49f4 symbol=FUN_001a49dc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001a49dc(int param_1,int param_2)
{
  return **(u32 **)(*(int *)(param_1 + 0x378) + param_2 * 4);
}
