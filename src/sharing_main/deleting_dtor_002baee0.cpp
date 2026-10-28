/* HSTMATCH module=hstp_trans_main.prx start=0x002baee0 end=0x002bb0b8 symbol=FUN_002baee0 lang=c++ */
/* Clone of src/eboot/deleting_dtor_002ab724.cpp (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b31c8;
extern u32 DAT_003ea914;
extern u32 DAT_003eaad8;
extern void FUN_00000a00(...);
extern int FUN_00004138(...);
extern u32 * FUN_0001ed28(...);
extern u32 * FUN_000463a0(...);
extern int FUN_0019d040(u32);
extern int FUN_0019d04c(...);
extern void FUN_001c170c(...);
extern void FUN_001c20b8(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };

extern "C" u32 * FUN_002baee0(u32 *param_1,short param_2)
{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b31c8);
    FUN_001c20b8(&DAT_003eaad8);
    FUN_001c170c(&DAT_003eaad8,4);
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
    if (DAT_003ea914 != 0) {
      iVar1 = FUN_0019d040(DAT_003ea914);
      uVar2 = FUN_0019d04c(DAT_003ea914);
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
      FUN_000463a0(param_1 + 0x20,0xffffffff);
      FUN_00004138(param_1 + 0x1d,0);
    }
    if ((char *)param_1 + 0x5c != (char *)0) {
      FUN_000463a0(param_1 + 0x1a,0xffffffff);
      FUN_00004138(param_1 + 0x17,0);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
