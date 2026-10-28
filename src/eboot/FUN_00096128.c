/* HSTMATCH module=EBOOT.BIN start=0x00096128 end=0x00096178 symbol=FUN_00096128 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00096128.c) corrected by hand: materialized the state test as an int and initialized the return local from it before the conditional call; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338c20;
extern u8 * DAT_003415ac;
extern u32 FUN_000fb7b8();

int FUN_00096128(void)
{
  int has_state = ((*(u16 *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0);
  int result = has_state;
  if (has_state != 0) {
    int iVar2 = FUN_000fb7b8(DAT_00338c20);
    result = (iVar2 != 0) ^ 1;
  }
  return result;
}
