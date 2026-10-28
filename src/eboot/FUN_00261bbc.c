/* HSTMATCH module=EBOOT.BIN start=0x00261bbc end=0x00261c24 symbol=FUN_00261bbc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ffc70();

void FUN_00261bbc(int param_1,int param_2)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)(param_1 + param_2 * 0xf0);
  FUN_000ffc70(*puVar1,0x80808080);
  FUN_000ffc70(puVar1[3],0x80808080);
  FUN_000ffc70(puVar1[4],puVar1[6]);
  FUN_000ffc70(puVar1[5],0x80808080);
}
