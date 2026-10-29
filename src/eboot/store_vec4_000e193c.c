/* HSTMATCH module=EBOOT.BIN start=0x000e193c end=0x000e1984 symbol=FUN_000e193c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: replaced the four loose undefined4 locals with a float v[4] array the callee fills, and stored it as four indexed float member writes; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct VecOwner {
  char pad0[0x80];
  float vec[4];             /* 0x80 */
} VecOwner;

extern void FUN_0001d7e4(float *param_1, u32 param_2);

/* Looks up the vector for `key` and stores it in the owner. */
void FUN_000e193c(VecOwner *self, u32 key)
{
  float v[4];

  FUN_0001d7e4(v, key);
  self->vec[0] = v[0];
  self->vec[1] = v[1];
  self->vec[2] = v[2];
  self->vec[3] = v[3];
}
