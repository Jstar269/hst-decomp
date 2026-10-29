/* HSTMATCH module=EBOOT.BIN start=0x000550c8 end=0x000550ec symbol=FUN_000550c8 lang=c99 */
/* Clone of src/eboot/FUN_0012c7b4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/avatar_route.h"

/* Sets the route's current position from four floats. */
void FUN_000550c8(Route *route,float *pos)
{
  route->pos.x = pos[0];
  route->pos.y = pos[1];
  route->pos.z = pos[2];
  route->pos.w = pos[3];
  return;
}
