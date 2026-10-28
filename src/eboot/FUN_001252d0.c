/* HSTMATCH module=EBOOT.BIN start=0x001252d0 end=0x001252fc symbol=FUN_001252d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340284;
extern int FUN_00131a78();

float FUN_001252d0(void)
{
  int iVar1;
  
  iVar1 = FUN_00131a78(DAT_00340284,6);
  return (float)iVar1;
}
