/* HSTMATCH module=EBOOT.BIN start=0x001ca8f0 end=0x001ca92c symbol=FUN_001ca8f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001ca92c();
extern u32 * FUN_0022a744();
extern int FUN_0022a930();

void FUN_001ca8f0(void)
{
  char *iVar1;
  u32 *puVar2;
  u32 auStack_1250 [1172];
  
  iVar1 = (char *)(FUN_0022a930());
  puVar2 = FUN_0022a744(auStack_1250);
  FUN_001ca92c((u32 *)(iVar1 + 0xa210),puVar2);
}
