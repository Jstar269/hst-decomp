/* HSTMATCH module=EBOOT.BIN start=0x0012c7b4 end=0x0012c7d8 symbol=FUN_0012c7b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/avatar_route.h"

/* Sets the route's current position from four floats. */
void FUN_0012c7b4(Route *route,float *pos)
{
  route->pos.x = pos[0];
  route->pos.y = pos[1];
  route->pos.z = pos[2];
  route->pos.w = pos[3];
  return;
}
