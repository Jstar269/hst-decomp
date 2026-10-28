/* HSTMATCH module=EBOOT.BIN start=0x0006531c end=0x00065364 symbol=FUN_0006531c lang=c99 */
/* CSV table reader: FindRowByKey; see docs/DATA-TABLES.md */
/* Clone of src/sharing_main/FUN_000663b8.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper arguments, used pointer arithmetic for the object subobject, and reversed the comparison arms; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00065c60(int *,u32 *,u32 *);

u32 FUN_0006531c(int param_1,u32 param_2)
{
  u32 uVar1;
  int local_8 [2];
  u32 local_c;
  
  local_c = param_2;
  FUN_00065c60(local_8,(u32 *)param_1 + 4,&local_c);
  if (local_8[0] != param_1 + 0x14) {
    uVar1 = *(u32 *)(local_8[0] + 0x10);
  } else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}
