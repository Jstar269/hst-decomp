/* HSTMATCH module=EBOOT.BIN start=0x001916a4 end=0x001916e4 symbol=FUN_001916a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_001916e4();
extern u32 FUN_00191818();

u32 FUN_001916a4(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00191818(param_1);
  FUN_001916e4(param_1,param_3);
  return param_1;
}
