/* HSTMATCH module=hstp_trans_main.prx start=0x001087a8 end=0x001088b4 symbol=FUN_001087a8 lang=c++ */
/* Clone of src/eboot/FUN_00102ea4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b0de4;
extern void FUN_00000a00(...);
extern int * FUN_0005514c(...);
extern int * FUN_000c7840(...);
extern void FUN_001088b4(...);
extern int * FUN_0010d1b0(...);
extern int * FUN_0010d26c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_001087a8(u32 *param_1,short param_2)
{
  int *piVar1;
  u32 *puVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0de4);
    FUN_001088b4();
    piVar1 = (int *)param_1[7];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[7] = 0;
    }
    puVar2 = param_1 + 0x10;
    if ((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) {
      FUN_000c7840(puVar2,0);
    }
    puVar2 = param_1 + 0xd;
    if ((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) {
      FUN_0005514c(puVar2,0);
    }
    puVar2 = param_1 + 10;
    if ((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) {
      FUN_0010d26c(puVar2,0);
    }
    puVar2 = param_1 + 4;
    if ((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) {
      FUN_0010d1b0(puVar2,0);
    }
    puVar2 = param_1 + 1;
    if ((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) {
      FUN_0010d1b0(puVar2,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
