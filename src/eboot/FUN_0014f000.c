/* HSTMATCH module=EBOOT.BIN start=0x0014f000 end=0x0014f014 symbol=FUN_0014f000 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

int FUN_0014f000(u32 *param_1)
{
  char cVar1;
  
  cVar1 = *(char *)*param_1;
  *param_1 = (unsigned int)((char *)*param_1 + 1);
  return (int)cVar1;
}
