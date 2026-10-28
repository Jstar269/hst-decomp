/* HSTMATCH module=EBOOT.BIN start=0x00295068 end=0x002951a0 symbol=FUN_00295068 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass the stored status to the variadic error formatter. */
#include "hst/types.h"

extern char DAT_002cb0f8[];
extern char DAT_002cb148[];
extern char DAT_002cb154[];
extern char DAT_002cb160[];
extern char DAT_002cb1ac[];
extern char DAT_002cb1f4[];
extern char DAT_002cb200[];
extern char DAT_002cb250[];
extern char DAT_002cb298[];
extern char DAT_002cb2a4[];
extern u32 FUN_000fe448();
extern void FUN_00294684(const char *, ...);
extern int FUN_00296d60();
extern int FUN_00296ff8();
extern int FUN_002973a4();
extern int FUN_002b79b0();

u32 FUN_00295068(u32 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  iVar1 = FUN_000fe448(DAT_002cb2a4,DAT_002cb298,
                       *(u32 *)(iVar3 + 4),0x200000);
  if (iVar1 < 0) {
    FUN_00294684(DAT_002cb250,*(u32 *)(iVar3 + 0x1c));
    *(u32 *)(iVar3 + 0x1c) = 0xffffffff;
  }
  else {
    iVar2 = FUN_00296d60();
    *(int *)(iVar3 + 0x1c) = iVar2;
    if (iVar2 < 0) {
      FUN_00294684(DAT_002cb200,iVar2);
      goto LAB_00295140;
    }
    iVar1 = FUN_002973a4(DAT_002cb1f4,*(u32 *)(iVar3 + 4),iVar1);
    *(int *)(iVar3 + 0x1c) = iVar1;
    if (iVar1 < 0) {
      FUN_00294684(DAT_002cb1ac,iVar1);
    }
    else {
      iVar1 = FUN_00296ff8();
      *(int *)(iVar3 + 0x1c) = iVar1;
      if (iVar1 < 0) {
        FUN_00294684(DAT_002cb160,iVar1);
      }
    }
  }
LAB_00295140:
  if (*(int *)(iVar3 + 0x1c) >= 0) {
    FUN_00294684(DAT_002cb154);
  } else {
    FUN_00294684(DAT_002cb148,*(int *)(iVar3 + 0x1c));
  }
  iVar1 = FUN_002b79b0(0);
  if (iVar1 < 0) {
    FUN_00294684(DAT_002cb0f8,iVar1);
  }
  return 0;
}
