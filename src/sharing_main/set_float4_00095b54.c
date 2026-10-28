/* HSTMATCH module=hstp_trans_main.prx start=0x00095b54 end=0x00095ba0 symbol=FUN_00095b54 lang=c99 */
/* Clone of src/eboot/set_float4_00093c30.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the copied argument as a four-float record; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000963ec();

typedef struct { float x, y, z, w; } Float4;

void FUN_00095b54(int param_1,Float4 *param_2)
{
  Float4 local;
  local = *param_2;
  FUN_000963ec(param_1 + 0x80,&local,*(u32 *)(param_1 + 0x58));
}
