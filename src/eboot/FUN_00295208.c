/* HSTMATCH module=EBOOT.BIN start=0x00295208 end=0x00295298 symbol=FUN_00295208 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00295208.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002cad8c[];
extern char DAT_002cada4[];
extern char DAT_002cadec[];
extern char DAT_002cae34[];
extern void FUN_00294684();
extern int FUN_002b78d8();
extern int FUN_002b7920();

void FUN_00295208(int param_1,u32 param_2)
{
  int iVar1;
  int local_4;
  u32 uVar2;
  
  iVar1 = FUN_002b7920(DAT_002cae34,param_2,0x29,0x4000,0,0);
  *(int *)(param_1 + 0x24) = iVar1;
  if (iVar1 < 0) {
    FUN_00294684(DAT_002cadec,iVar1);
  }
  local_4 = param_1;
  iVar1 = FUN_002b78d8(*(u32 *)(param_1 + 0x24),4,&local_4);
  if (iVar1 < 0) {
    FUN_00294684(DAT_002cada4,*(u32 *)(param_1 + 0x24));
    uVar2 = *(u32 *)(param_1 + 0x24);
  }
  else {
    uVar2 = *(u32 *)(param_1 + 0x24);
  }
  FUN_00294684(DAT_002cad8c,uVar2);
}
