/* HSTMATCH module=EBOOT.BIN start=0x001dafe8 end=0x001db05c symbol=FUN_001dafe8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the two products are formed in the order they are used (x * F(yaw) first, then z * G(yaw)) instead of Ghidra's hoisted locals; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern float FUN_0000bc34(float param_1);
extern float FUN_0000bf34(float param_1);
extern float FUN_0000c6dc(float param_1,float param_2);

/* Convert the direction dir[0..2] into two angles: angles[0] from (x, z), angles[1] from y and the combined x/z term. */
void FUN_001dafe8(u32 unused,float *angles,float *dir)
{
  float x_term;
  float z_term;
  angles[0] = FUN_0000c6dc(dir[0], dir[2]);
  x_term = dir[0] * FUN_0000bf34(angles[0]);
  z_term = dir[2] * FUN_0000bc34(angles[0]);
  angles[1] = FUN_0000c6dc(dir[1], x_term + z_term);
}
