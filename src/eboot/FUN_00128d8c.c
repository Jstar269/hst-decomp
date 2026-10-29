/* HSTMATCH module=EBOOT.BIN start=0x00128d8c end=0x00128e40 symbol=FUN_00128d8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed float vectors and arranged the copy and previous-value store to match the disassembly; readability pass; exact match verified; names and types await human review. */
#include "hst/avatar_move.h"

extern void FUN_00022434(Float4 *out, Float4 *a, Float4 *b); /* a - b */
extern void FUN_00022518(Float4 *out, Float4 *in); /* normalise */
extern float FUN_0000c6dc(float a, float b); /* heading from a horizontal direction */
extern void FUN_0012aa1c(AvatarMove *self);

/* Applies a pending heading update (towards the reference position), then the common follow-up step. */
void FUN_00128d8c(AvatarMove *self)
{
  Float4 reordered;
  Float4 result;
  Float4 difference;

  if (self->active != 0) {
    FUN_00022434(&difference, &self->ref_pos, &self->pos);
    reordered.x = difference.x;
    reordered.y = difference.y;
    reordered.z = difference.z;
    reordered.w = difference.w;
    self->prev_angle = self->angle;
    FUN_00022518(&result, &reordered);
    result.w = 0.0f;
    self->angle = FUN_0000c6dc(result.x, result.z);
    self->ref_pos.x = self->pos.x;
    self->ref_pos.y = self->pos.y;
    self->ref_pos.z = self->pos.z;
    self->ref_pos.w = self->pos.w;
    self->active = 0;
  }
  FUN_0012aa1c(self);
  self->prev_angle = self->angle;
}
