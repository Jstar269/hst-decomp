/* HSTMATCH module=EBOOT.BIN start=0x0027d17c end=0x0027d34c symbol=FUN_0027d17c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s27d17c) corrected by hand: the null arm stores the pointer value
   instead of 0 (`param_1[0xf] = iVar1; uVar2 = iVar1;`), which keeps the zero already live in v0 so
   MWCC needs no `move v0,zero` and can share the store in the beqzl delay slot; the two loop
   counters are declared iVar3 before iVar1; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c60;
extern u32 DAT_0034a7e0;
extern u8 * DAT_0034a7e4;
extern int FUN_00000a90();
extern int FUN_00000bcc();
extern u32 * FUN_0001f06c();
extern void FUN_0001f1fc();
extern void FUN_0001f21c();
extern u32 * FUN_0027b8cc();

u32 * FUN_0027d17c(u32 *param_1)
{
  int iVar3;
  u32 uVar2;
  int iVar1;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309c60);
  param_1[0xf] = 0;
  DAT_0034a7e0 = (unsigned int)(param_1);
  DAT_0034a7e4 = (unsigned char *)(FUN_00000a90(0x2000));
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar3 = iVar3 + 1;
    *(u32 *)(DAT_0034a7e4 + iVar1) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 4) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 8) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0xc) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x10) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x14) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x18) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x1c) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x20) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x24) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x28) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x2c) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x30) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x34) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x38) = 0;
    *(u32 *)(DAT_0034a7e4 + iVar1 + 0x3c) = 1;
    iVar1 = iVar1 + 0x40;
  } while (iVar3 < 0x80);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  iVar1 = FUN_00000bcc(0x80);
  if (iVar1 != 0) {
    uVar2 = (unsigned int)(FUN_0027b8cc(iVar1));
    param_1[0xf] = uVar2;
  }
  else {
    uVar2 = (unsigned int)(iVar1);
    param_1[0xf] = iVar1;
  }
  FUN_0001f21c(param_1,uVar2);
  FUN_0001f1fc(param_1[0xf],0);
  return param_1;
}
