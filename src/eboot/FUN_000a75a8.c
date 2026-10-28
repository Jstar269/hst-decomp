/* HSTMATCH module=EBOOT.BIN start=0x000a75a8 end=0x000a7664 symbol=FUN_000a75a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: copied the four float fields through a typed array, aligned the vector result buffer, and typed the matrix-member argument to preserve the call setup; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct { char pad[0x5a0]; float matrix[4]; } MatrixOwner;
extern int FUN_000a7664();
extern void FUN_00022450(float *, void *, float *);
bool FUN_000a75a8(int self, int other) {
  bool result;
  u8 auStack_10[16];
  u8 auStack_20[16];
  float fields[4];
  float local_40[4] __attribute__((aligned(16)));
  if ((*(u32 *)(self + 0x144) ^ 1) == *(u32 *)(other + 0x230)) {
    fields[0] = *(float *)(self + 0x580);
    fields[1] = *(float *)(self + 0x584);
    fields[2] = *(float *)(self + 0x588);
    fields[3] = *(float *)(self + 0x58c);
    if (FUN_000a7664(self, auStack_20, other + 0x26c, fields, 1, 0, 0) != 0) {
      FUN_00022450(local_40, auStack_10, ((MatrixOwner *)self)->matrix);
      bool mode = *(int *)(self + 0x150) == 0;
      bool inside = *(float *)(self + 0x580) <= local_40[0];
      result = mode == inside;
    } else {
      result = 1;
    }
  } else {
    result = 1;
  }
  return result;
}

