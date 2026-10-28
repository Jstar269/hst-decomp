/* HSTMATCH module=EBOOT.BIN start=0x002ab724 end=0x002ab8fc symbol=FUN_002ab724 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309efc;
extern u32 DAT_003415d4;
extern u32 DAT_0034179c;
extern void FUN_00000a00(...);
extern int FUN_00004138(...);
extern u32 * FUN_0001f0f0(...);
extern u32 * FUN_000462a0(...);
extern int FUN_00190830(u32);
extern int FUN_0019083c(...);
extern void FUN_001b338c(...);
extern void FUN_001b3e2c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };

extern "C" u32 * FUN_002ab724(u32 *param_1,short param_2)
{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309efc);
    FUN_001b3e2c(&DAT_0034179c);
    FUN_001b338c(&DAT_0034179c,4);
    piVar3 = (int *)param_1[0xf];
    if (piVar3 != (int *)0x0) {
      delete ((VC_0 *)(piVar3));
      param_1[0xf] = 0;
    }
    piVar3 = (int *)param_1[0x10];
    if (piVar3 != (int *)0x0) {
      delete ((VC_1 *)(piVar3));
      param_1[0x10] = 0;
    }
    piVar3 = (int *)param_1[0x11];
    if (piVar3 != (int *)0x0) {
      delete ((VC_2 *)(piVar3));
      param_1[0x11] = 0;
    }
    piVar3 = (int *)param_1[0x12];
    if (piVar3 != (int *)0x0) {
      delete ((VC_3 *)(piVar3));
      param_1[0x12] = 0;
    }
    if (DAT_003415d4 != 0) {
      iVar1 = FUN_00190830(DAT_003415d4);
      uVar2 = FUN_0019083c(DAT_003415d4);
      if (iVar1 != 0) {
        *(u32 *)(*(int *)(iVar1 + 0x70) + 0x24) = 0x3f;
        *(u32 *)(*(int *)(iVar1 + 0x70) + 0x28) = uVar2;
      }
    }
    piVar3 = (int *)param_1[0x23];
    if (piVar3 != (int *)0x0) {
      delete ((VC_4 *)(piVar3));
      param_1[0x23] = 0;
    }
    if ((char *)param_1 + 0x74 != (char *)0) {
      FUN_000462a0(param_1 + 0x20,0xffffffff);
      FUN_00004138(param_1 + 0x1d,0);
    }
    if ((char *)param_1 + 0x5c != (char *)0) {
      FUN_000462a0(param_1 + 0x1a,0xffffffff);
      FUN_00004138(param_1 + 0x17,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
