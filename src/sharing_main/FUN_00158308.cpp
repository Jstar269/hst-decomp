/* HSTMATCH module=hstp_trans_main.prx start=0x00158308 end=0x001583b4 symbol=FUN_00158308 lang=c++ */
/* Clone of src/eboot/FUN_0014c820.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
extern void FUN_0015b32c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int FUN_00158308(int param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  u8 auStack_4 [4];
  u32 local_8;
  int local_c;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 8);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(u32 *)(param_1 + 8) = 0;
    }
    iVar2 = param_1 + 0x18;
    if (((iVar2 != 0) && (iVar2 != 0)) && (iVar2 != 0)) {
      local_c = param_1 + 0x1c;
      local_8 = *(u32 *)(param_1 + 0x20);
      FUN_0015b32c(auStack_4,iVar2,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
