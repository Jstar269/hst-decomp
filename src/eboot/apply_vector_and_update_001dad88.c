/* HSTMATCH module=EBOOT.BIN start=0x001dad88 end=0x001dadf4 symbol=FUN_001dad88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the float vector and helper argument order; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_003386b0;
extern int FUN_0008882c(u32);
extern float *FUN_00093838(int);
extern void FUN_001daeb4(float, void *, const float *);
extern void FUN_001db1ec(void *);
void FUN_001dad88(void *param_1)
{
  int value = FUN_0008882c(DAT_003386b0);
  float *source = FUN_00093838(*(int *)(value + 0x5bc));
  float local[4];
  local[0] = source[0];
  local[1] = source[1];
  local[2] = source[2];
  local[3] = source[3];
  FUN_001daeb4(0.0f, param_1, local);
  FUN_001db1ec(param_1);
}

