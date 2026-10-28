/* HSTMATCH module=EBOOT.BIN start=0x0024d808 end=0x0024d8dc symbol=FUN_0024d808 lang=c99 */
/* AityakuTable ctor: data/common/aityaku/aityaku.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002fbdbc;
extern u8 DAT_003070bc;
extern u32 DAT_0034a77c;
extern char DAT_002fbd9c[];
extern char DAT_002fbdc0[];
extern char DAT_002fbddc[];
extern char DAT_002fbde8[];
extern u64 FUN_00020f5c(float);
extern int * FUN_000649c0();
extern u32 FUN_000651b8();
extern u32 * FUN_0008c230();
extern void FUN_0024d8dc();
extern void FUN_0024d908();

u32 * FUN_0024d808(u32 *param_1)
{
  int iVar2;
  u32 *puVar1;
  u64 uVar3;
  
  FUN_000649c0();
  *param_1 = (unsigned int)(&DAT_003070bc);
  FUN_0008c230(param_1 + 4);
  FUN_0008c230(param_1 + 8);
  DAT_0034a77c = (unsigned int)(param_1);
  FUN_000651b8(param_1,DAT_002fbd9c,1,0,&DAT_002fbdbc);
  FUN_0024d908(param_1);
  FUN_0024d8dc(DAT_002fbdc0);
  FUN_0024d8dc(DAT_002fbddc);
  iVar2 = 0;
  puVar1 = param_1;
  do {
    uVar3 = FUN_00020f5c(*(float *)((char *)puVar1 + 0x30));
    FUN_0024d8dc(DAT_002fbde8,iVar2 + 1,(int)uVar3,(int)((u64)uVar3 >> 0x20));
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 9);
  return param_1;
}
