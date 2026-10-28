/* HSTMATCH module=EBOOT.BIN start=0x00253630 end=0x002536f0 symbol=FUN_00253630 lang=c99 */
/* IromonoRuleList ctor: data/common/rule/Rule_Iromono.txt; see docs/DATA-TABLES.md */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00253630.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002fcc70;
extern char DAT_002fcc4c[];
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern u32 FUN_00064bf4();
extern u32 FUN_000650e0();
extern int FUN_00065104();

u32 * FUN_00253630(u32 *param_1)
{
  int iVar1;
  int iVar2;
  u8 auStack_10 [16];
  
  *param_1 = 0;
  FUN_000649c0(auStack_10);
  FUN_00064bf4(auStack_10,DAT_002fcc4c,0,&DAT_002fcc70);
  param_1[6] = 0;
  iVar2 = 0;
  iVar1 = FUN_000650e0(auStack_10);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_00065104(auStack_10,iVar2,3);
      if (iVar1 != 0) {
        iVar1 = param_1[6];
        param_1[6] = iVar1 + 1;
        param_1[iVar1 + 7] = iVar2;
      }
      iVar2 = 1 + iVar2;
      iVar1 = FUN_000650e0(auStack_10);
    } while (iVar2 < iVar1);
  }
  FUN_00064a08(auStack_10,0xffffffff);
  return param_1;
}
