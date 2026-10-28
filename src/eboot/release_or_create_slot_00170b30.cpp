/* HSTMATCH module=EBOOT.BIN start=0x00170b30 end=0x00170c24 symbol=FUN_00170b30 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6, variant v17) corrected by hand: flag byte typed unsigned char (lbu) and the new-then-construct store shared (p = alloc; if (p) p = ctor(p); *slot = p); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_0034b340;
extern int FUN_00000bcc(...);
extern u32 * FUN_00091830(...);
extern void FUN_0009191c(...);
extern void FUN_00091c48(...);
extern void FUN_00092ff8(...);
extern u32 FUN_0017c344(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_00170b30(int param_1,int param_2)
{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  int *piVar4;
  int *piVar5;
  
  if (*(unsigned char *)(param_1 + 0x4d) != 0) {
    uVar1 = FUN_0017c344(*(int *)(param_1 + 0x178));
    if ((uVar1 & 0xff) == 0) {
      piVar4 = (int *)(&DAT_0034b340 + param_2 * 4);
      piVar5 = (int *)*piVar4;
      if (piVar5 != (int *)0x0) {
        delete ((VC_0 *)(piVar5));
        *piVar4 = 0;
      }
    }
    else {
      piVar5 = (int *)(&DAT_0034b340 + param_2 * 4);
      if (*piVar5 == 0) {
        puVar3 = (u32 *)FUN_00000bcc(0xe0);
        if (puVar3 != (u32 *)0x0) {
          puVar3 = FUN_00091830(puVar3);
        }
        *piVar5 = (int)puVar3;
      }
      iVar2 = *(int *)(param_1 + 0x178);
      FUN_0009191c(*piVar5,*(int *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 4) * 4) + 0x10);
      FUN_00091c48(*piVar5,0);
      FUN_00092ff8(*piVar5);
    }
  }
}
