/* HSTMATCH module=hstp_trans_main.prx start=0x00188a38 end=0x00188a90 symbol=FUN_00188a38 lang=c99 */
/* Clone of src/eboot/can_enter_state_0017c344.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected the helper return type and short-circuit returns; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0020d018();
extern int FUN_0020d144();

int FUN_00188a38(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0020d144(param_1 + 0x2e4,*(u32 *)(param_1 + 4));
  if (iVar1 == 0) {
    iVar1 = FUN_0020d018(param_1 + 0x5c,*(u32 *)(param_1 + 4),0);
    if (iVar1 == 0) return 1;
  }
  return 0;
}
