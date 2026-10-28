/* HSTMATCH module=hstp_trans_main.prx start=0x000c77a0 end=0x000c77ec symbol=FUN_000c77a0 lang=c99 */
/* Clone of src/eboot/copy_float4_output_000c3f38.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a four-float temporary and float field copies; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct { float x, y, z, w; } Float4;

extern void FUN_00022540(Float4 *);

void FUN_000c77a0(Float4 *param_1)
{
  Float4 local;
  FUN_00022540(&local);
  *(u32 *)&local.w = 0;
  param_1->x = local.x;
  param_1->y = local.y;
  param_1->z = local.z;
  param_1->w = local.w;
}
