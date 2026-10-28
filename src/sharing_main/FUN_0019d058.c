/* HSTMATCH module=hstp_trans_main.prx start=0x0019d058 end=0x0019d090 symbol=FUN_0019d058 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();

void FUN_0019d058(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 0x578) != 0) {
    FUN_000009e4(*(int *)(iVar1 + 0x578));
    *(u32 *)(iVar1 + 0x578) = 0;
  }
}
