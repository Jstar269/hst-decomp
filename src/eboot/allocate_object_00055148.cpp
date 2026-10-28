/* HSTMATCH module=EBOOT.BIN start=0x00055148 end=0x00055204 symbol=FUN_00055148 lang=c++ */
/* Clone of src/sharing_main/allocate_object_00055c68.cpp (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: modeled the indirect dispatch as a typed virtual call and shared the allocation result store across both paths; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" int FUN_00000bcc(int);
extern "C" int FUN_00053670(int,int,int,int,int,int,int);

struct VC_00055148 { virtual ~VC_00055148(); virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); };

extern "C" bool FUN_00055148(int *param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  int iVar1;
  
  ((VC_00055148 *)param_1)->s2();
  iVar1 = FUN_00000bcc(0x30);
  if (iVar1 != 0) {
    iVar1 = FUN_00053670(iVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  param_1[0x23] = iVar1;
  *(u8 *)(param_1 + 0x24) = 1;
  return *(int *)(param_1[0x23] + 8) != 0;
}
