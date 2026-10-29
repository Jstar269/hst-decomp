/* HSTMATCH module=EBOOT.BIN start=0x00128c94 end=0x00128d0c symbol=FUN_00128c94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a/v2) corrected by hand: used a four-word float output local with an explicit pad; readability pass; exact match verified; names and types await human review. */
#include "hst/avatar_move.h"

extern float FUN_0000c6dc(float x, float z); /* heading from a horizontal direction */
extern void FUN_00022518(Float4 *, Float4 *); /* normalise */

/* Updates the heading from a movement direction; with reset == 0 the reference position is refreshed as well. */
void FUN_00128c94(AvatarMove *self,Float4 *direction,int reset)
{
  float heading;
  Float4 unit;
  
  self->prev_angle = self->angle;
  FUN_00022518(&unit,direction);
  unit.w = 0;
  heading = FUN_0000c6dc(unit.x,unit.z);
  self->angle = heading;
  if (reset == 0) {
    self->ref_pos.x = self->pos.x;
    self->ref_pos.y = self->pos.y;
    self->ref_pos.z = self->pos.z;
    self->ref_pos.w = self->pos.w;
    self->active = 0;
  }
  return;
}
