/* HSTMATCH module=EBOOT.BIN start=0x00093c7c end=0x00093cc8 symbol=FUN_00093c7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the copied argument as a four-float record; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000944c8();

typedef struct { float x, y, z, w; } Float4;

void FUN_00093c7c(int param_1,Float4 *param_2)
{
  Float4 local;
  local = *param_2;
  FUN_000944c8(param_1 + 0xb0,&local,*(u32 *)(param_1 + 0x58));
}
