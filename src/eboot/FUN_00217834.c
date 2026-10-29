/* HSTMATCH module=EBOOT.BIN start=0x00217834 end=0x002178ac symbol=FUN_00217834 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Start the colour block: unpack the byte channels of the two packed colours, duration `duration`. */
void FUN_00217834(Animator *self,u32 from,u32 to,int duration)
{
  self->color.head.active = 1;
  self->color.head.done = 0;
  self->color.head.duration = duration;
  self->color.from[0] = (u16)from & 0xff;
  self->color.from[1] = (u8)(from >> 8);
  self->color.from[2] = (u8)(from >> 0x10);
  self->color.from[3] = (u8)(from >> 0x18);
  self->color.to[0] = (u16)to & 0xff;
  self->color.to[1] = (u8)(to >> 8);
  self->color.to[2] = (u8)(to >> 0x10);
  self->color.to[3] = (u8)(to >> 0x18);
  self->color.head.counter = 0;
  self->color.cur[0] = self->color.from[0];
  self->color.cur[1] = self->color.from[1];
  self->color.cur[2] = self->color.from[2];
  self->color.cur[3] = self->color.from[3];
  return;
}
