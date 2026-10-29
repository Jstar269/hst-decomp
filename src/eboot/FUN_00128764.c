/* HSTMATCH module=EBOOT.BIN start=0x00128764 end=0x0012883c symbol=FUN_00128764 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane cx5, unreviewed) corrected by hand: the w clamp is a ternary assignment followed by the z load (the if/else form duplicated the z load into both arms in the wrong order); readability pass; exact match verified; names and types await human review. */
#include "hst/avatar_move.h"

extern float DAT_002da3d4;
extern float DAT_002da3e4;
extern void FUN_00022418(Float4 *, Float4 *, Float4 *); /* a + b */

/* One physics step: adds the gravity step to the velocity, clamps it, and adds it to the position. */
void FUN_00128764(AvatarMove *self)
{
  Float4 gravity;
  float w, z, y, x, floor_y;
  gravity.x = 0.0f;
  gravity.y = DAT_002da3d4;
  gravity.z = 0.0f;
  gravity.w = 0.0f;
  FUN_00022418(&self->velocity, &self->velocity, &gravity);
  floor_y = -DAT_002da3e4;
  w = self->velocity.w;
  w = (w > 0.0f) ? w : 0.0f;
  z = self->velocity.z;
  z = (z > 0.0f) ? z : 0.0f;
  y = self->velocity.y;
  y = (y > floor_y) ? y : floor_y;
  x = self->velocity.x;
  x = (x > 0.0f) ? x : 0.0f;
  self->velocity.x = x;
  self->velocity.y = y;
  self->velocity.z = z;
  self->velocity.w = w;
  FUN_00022418(&self->pos, &self->pos, &self->velocity);
}
