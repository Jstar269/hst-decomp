/* HSTMATCH module=EBOOT.BIN start=0x0014c214 end=0x0014c274 symbol=FUN_0014c214 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0014c794();
extern int FUN_0014c820();
extern u32 * FUN_0014c914();
extern u32 * FUN_0014f528();

u32 FUN_0014c214(int param_1,int *param_2,int param_3)
{
  u8 auStack_24 [36];
  
  FUN_0014c794(auStack_24,param_2,*(u32 *)(*param_2 + param_3 * 8 + 4));
  *(u32 *)(param_1 + 8) = 0;
  FUN_0014f528(param_1 + 0x18);
  FUN_0014c914(param_1,auStack_24);
  FUN_0014c820(auStack_24,0xffffffff);
  return 0;
}
