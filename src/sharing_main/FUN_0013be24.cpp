/* HSTMATCH module=hstp_trans_main.prx start=0x0013be24 end=0x0013bf24 symbol=FUN_0013be24 lang=c++ */
/* Clone of src/eboot/FUN_0013086c.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b14bc;
extern u32 DAT_003e95c4;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern int * FUN_00064d08(...);
extern void FUN_0013bf24(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" u32 * FUN_0013be24(u32 *param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b14bc);
    DAT_003e95c4 = 0;
    FUN_0013bf24(param_1,0);
    piVar1 = (int *)param_1[0x1f];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x1f] = 0;
    }
    piVar1 = (int *)param_1[0x20];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x20] = 0;
    }
    piVar1 = (int *)param_1[0x21];
    if (piVar1 != (int *)0x0) {
      delete ((VC_2 *)(piVar1));
      param_1[0x21] = 0;
    }
    iVar2 = param_1[0x12];
    if (iVar2 != 0) {
      FUN_00064d08(iVar2,1);
      param_1[0x12] = 0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
