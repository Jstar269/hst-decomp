/* HSTMATCH module=EBOOT.BIN start=0x0029ff1c end=0x002a0058 symbol=FUN_0029ff1c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass the saved status as the variadic error argument. */
#include "hst/types.h"

extern char DAT_002cbdc0[];
extern char DAT_002cbe10[];
extern char DAT_002cbe1c[];
extern char DAT_002cbe28[];
extern char DAT_002cbe74[];
extern char DAT_002cbebc[];
extern char DAT_002cbec8[];
extern char DAT_002cbf18[];
extern char DAT_002cbf60[];
extern char DAT_002cbf6c[];
extern u32 FUN_000fe448();
extern int FUN_00296d60();
extern int FUN_00296ff8();
extern int FUN_002973a4();
extern void FUN_0029e3cc(const char *, ...);
extern int FUN_002b79b0();

u32 FUN_0029ff1c(u32 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  iVar1 = FUN_000fe448(DAT_002cbf6c,DAT_002cbf60,
                       *(u32 *)(iVar3 + 8),0x218000);
  if (iVar1 < 0) {
    FUN_0029e3cc(DAT_002cbf18,*(u32 *)(iVar3 + 0x20));
    *(u32 *)(iVar3 + 0x20) = 0xffffffff;
  }
  else {
    iVar2 = FUN_00296d60();
    *(int *)(iVar3 + 0x20) = iVar2;
    if (iVar2 < 0) {
      FUN_0029e3cc(DAT_002cbec8,iVar2);
      goto LAB_0029fff8;
    }
    iVar1 = FUN_002973a4(DAT_002cbebc,*(u32 *)(iVar3 + 8),iVar1);
    *(int *)(iVar3 + 0x20) = iVar1;
    if (iVar1 < 0) {
      FUN_0029e3cc(DAT_002cbe74,iVar1);
    }
    else {
      iVar1 = FUN_00296ff8();
      *(int *)(iVar3 + 0x20) = iVar1;
      if (iVar1 < 0) {
        FUN_0029e3cc(DAT_002cbe28,iVar1);
      }
    }
  }
LAB_0029fff8:
  iVar1 = *(int *)(iVar3 + 0x20);
  if (iVar1 >= 0) {
    FUN_0029e3cc(DAT_002cbe1c);
  } else {
    FUN_0029e3cc(DAT_002cbe10,iVar1);
  }
  iVar1 = FUN_002b79b0(0);
  if (iVar1 < 0) {
    FUN_0029e3cc(DAT_002cbdc0,iVar1);
  }
  return 0;
}
