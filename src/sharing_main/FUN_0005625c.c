/* HSTMATCH module=hstp_trans_main.prx start=0x0005625c end=0x000562d0 symbol=FUN_0005625c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000224c0(float, int, int);
extern void FUN_00054b5c();

void FUN_0005625c(int param_1,int param_2)
{
  float fVar1;
  
  FUN_00054b5c(*(u32 *)(param_1 + 0x8c));
  fVar1 = *(float *)(param_1 + 0x88) / *(float *)(param_1 + 0x84);
  FUN_000224c0((float)(fVar1),(int)(param_2),(int)(param_2));
  FUN_000224c0((float)(fVar1),(int)(param_2 + 0x10),(int)(param_2 + 0x10));
  *(float *)(param_2 + 0x1c) = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc);
}
