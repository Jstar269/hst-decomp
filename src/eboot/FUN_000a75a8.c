/* HSTMATCH module=EBOOT.BIN start=0x000a75a8 end=0x000a7664 symbol=FUN_000a75a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: copied the four float fields through a typed array, aligned the vector result buffer, and typed the matrix-member argument to preserve the call setup; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Unit {
  char pad0[0x144];
  u32 unk144;         /* 0x144 compared (xor 1) with the other unit's field */
  char pad148[8];
  int unk150;         /* 0x150 */
  char pad154[0x580 - 0x154];
  float pos[4];       /* 0x580 */
  char pad590[0x5a0 - 0x590];
  float matrix[4];    /* 0x5a0 */
} Unit;

typedef struct OtherUnit {
  char pad0[0x230];
  u32 unk230;         /* 0x230 */
  char pad234[0x26c - 0x234];
  char unk26c[1];     /* 0x26c passed by address */
} OtherUnit;

extern int FUN_000a7664();
extern void FUN_00022450(float *, void *, float *);

bool FUN_000a75a8(Unit *self, OtherUnit *other) {
  bool result;
  u8 prod_a[16];
  u8 prod_b[16];
  float pos[4];
  float scaled[4] __attribute__((aligned(16)));
  if ((self->unk144 ^ 1) == other->unk230) {
    pos[0] = self->pos[0];
    pos[1] = self->pos[1];
    pos[2] = self->pos[2];
    pos[3] = self->pos[3];
    if (FUN_000a7664(self, prod_b, other->unk26c, pos, 1, 0, 0) != 0) {
      FUN_00022450(scaled, prod_a, self->matrix);
      bool mode = self->unk150 == 0;
      bool inside = self->pos[0] <= scaled[0];
      result = mode == inside;
    } else {
      result = 1;
    }
  } else {
    result = 1;
  }
  return result;
}
