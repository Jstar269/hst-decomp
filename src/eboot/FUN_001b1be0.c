/* HSTMATCH module=EBOOT.BIN start=0x001b1be0 end=0x001b1c44 symbol=FUN_001b1be0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the handle tested first is FUN_00062a6c's argument (Ghidra dropped it, so retail loads it into a0); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000628e4();
extern int FUN_00062a6c(int);
extern u32 FUN_00062b3c();

struct State_001b1be0 { char pad[2000]; int handle; };

void FUN_001b1be0(int *param_1)
{
  int handle;
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  handle = ((struct State_001b1be0 *)iVar2)->handle;
  if (handle <= 0) {
    return;
  }
  iVar1 = FUN_00062a6c(handle);
  if (iVar1 == 0) {
    *(u32 *)(iVar2 + 2000) = 0xffffffff;
  }
  else {
    iVar1 = FUN_00062b3c(*(u32 *)(iVar2 + 2000));
    if (iVar1 < 1) {
      FUN_000628e4(*(u32 *)(iVar2 + 2000),1);
    }
  }
}
