/* HSTMATCH module=EBOOT.BIN start=0x0021aa34 end=0x0021aa6c symbol=FUN_0021aa34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0021aabc();
extern void FUN_0021abe0();

u32 * FUN_0021aa34(u32 *param_1)
{
  *param_1 = 0;
  FUN_0021aabc();
  FUN_0021abe0(param_1,0xb);
  return param_1;
}
