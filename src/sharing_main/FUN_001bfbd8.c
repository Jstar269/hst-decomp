/* HSTMATCH module=hstp_trans_main.prx start=0x001bfbd8 end=0x001bfc3c symbol=FUN_001bfbd8 lang=c99 */
/* Clone of src/eboot/FUN_001b1be0.c (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the handle tested first is FUN_00063930's argument (Ghidra dropped it, so retail loads it into a0); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000637a8();
extern int FUN_00063930(int);
extern u32 FUN_00063a00();

struct State_001bfbd8 { char pad[2000]; int handle; };

void FUN_001bfbd8(int *param_1)
{
  int handle;
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  handle = ((struct State_001bfbd8 *)iVar2)->handle;
  if (handle <= 0) {
    return;
  }
  iVar1 = FUN_00063930(handle);
  if (iVar1 == 0) {
    *(u32 *)(iVar2 + 2000) = 0xffffffff;
  }
  else {
    iVar1 = FUN_00063a00(*(u32 *)(iVar2 + 2000));
    if (iVar1 < 1) {
      FUN_000637a8(*(u32 *)(iVar2 + 2000),1);
    }
  }
}
