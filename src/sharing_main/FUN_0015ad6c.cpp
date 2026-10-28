/* HSTMATCH module=hstp_trans_main.prx start=0x0015ad6c end=0x0015ae44 symbol=FUN_0015ad6c lang=c++ */
/* Clone of src/eboot/FUN_0014ed64.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b1614;
extern u8 DAT_003b1698;
extern void FUN_00000a00(...);
extern void FUN_0015b32c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_0015ad6c(u32 *param_1,short param_2)
{
  int *piVar1;
  u32 *puVar2;
  u8 auStack_4 [4];
  u32 local_8;
  u32 *local_c;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1614);
    if ((char *)param_1 + 0x4 != (char *)0) {
      piVar1 = (int *)param_1[3];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        param_1[3] = 0;
      }
      puVar2 = param_1 + 7;
      if (((puVar2 != (u32 *)0x0) && (puVar2 != (u32 *)0x0)) &&
         (puVar2 != (u32 *)0x0)) {
        local_c = param_1 + 8;
        local_8 = param_1[9];
        FUN_0015b32c(auStack_4,puVar2,&local_8,&local_c);
      }
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b1698);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
