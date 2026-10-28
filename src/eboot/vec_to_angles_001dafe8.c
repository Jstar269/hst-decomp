/* HSTMATCH module=EBOOT.BIN start=0x001dafe8 end=0x001db05c symbol=FUN_001dafe8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the two products are formed in the order they are used (x * F(yaw) first, then z * G(yaw)) instead of Ghidra's hoisted locals; exact match verified; names and types await human review. */
#include "hst/types.h"

extern float FUN_0000bc34(float param_1);
extern float FUN_0000bf34(float param_1);
extern float FUN_0000c6dc(float param_1,float param_2);

void FUN_001dafe8(u32 param_1,float *param_2,float *param_3)
{
  float t;
  float u;
  param_2[0] = FUN_0000c6dc(param_3[0], param_3[2]);
  t = param_3[0] * FUN_0000bf34(param_2[0]);
  u = param_3[2] * FUN_0000bc34(param_2[0]);
  param_2[1] = FUN_0000c6dc(param_3[1], t + u);
}
