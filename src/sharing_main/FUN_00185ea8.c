/* HSTMATCH module=hstp_trans_main.prx start=0x00185ea8 end=0x00185ef0 symbol=FUN_00185ea8 lang=c99 */
/* Clone of src/eboot/FUN_001797b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern void FUN_00189578();
extern void FUN_0018d5d0();

void FUN_00185ea8(int param_1)
{
  u32 uVar1;
  
  if (0 < *(int *)(param_1 + 0x6c)) {
    uVar1 = (**(code **)(param_1 + 0x558))();
    FUN_0018d5d0(*(u32 *)(param_1 + 0x174),uVar1);
    FUN_00189578(*(u32 *)(param_1 + 0x178));
  }
}
