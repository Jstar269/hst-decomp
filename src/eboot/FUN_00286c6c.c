/* HSTMATCH module=EBOOT.BIN start=0x00286c6c end=0x00286cb8 symbol=FUN_00286c6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0014c794();
extern int FUN_0014c820();
extern u32 * FUN_0014c914();

void FUN_00286c6c(int param_1)
{
  u8 auStack_24 [36];
  
  FUN_0014c794(auStack_24,0,0,0);
  FUN_0014c914(*(u32 *)(param_1 + 8),auStack_24);
  FUN_0014c820(auStack_24,0xffffffff);
}
