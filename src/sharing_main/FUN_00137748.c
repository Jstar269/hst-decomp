/* HSTMATCH module=hstp_trans_main.prx start=0x00137748 end=0x001377d0 symbol=FUN_00137748 lang=c99 */
/* Clone of src/eboot/FUN_0012c2dc.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_route.h"

extern u8 DAT_002d10e0;
extern void FUN_00137eb8();

/* Route constructor: empty point and tangent lists with room reserved, speed 1.0 and spline mode off.
   The address is kept as an int and the stores stay raw: a typed pointer parameter changes the schedule. */
int FUN_00137748(int route)
{
  *(u8 **)(route + 0x40) = &DAT_002d10e0;                    /* unk40 */
  *(u32 *)(route + 0x70) = 0;                                /* pts.data */
  *(u32 *)(route + 0x74) = 0;                                /* pts.size */
  *(u32 *)(route + 0x78) = 0;                                /* pts.capacity */
  *(u32 *)(route + 0x84) = 0;                                /* tangents.data */
  *(u32 *)(route + 0x88) = 0;                                /* tangents.size */
  *(u32 *)(route + 0x8c) = 0;                                /* tangents.capacity */
  if (((Route *)route)->pts.capacity < ROUTE_INITIAL_CAPACITY) {
    FUN_00137eb8(&((Route *)route)->pts,ROUTE_INITIAL_CAPACITY);
  }
  if (((Route *)route)->tangents.capacity < ROUTE_INITIAL_CAPACITY) {
    FUN_00137eb8(&((Route *)route)->tangents,ROUTE_INITIAL_CAPACITY);
  }
  *(u32 *)(route + 0x90) = 0x3f800000;                       /* speed = 1.0f */
  *(u8 *)(route + 0x94) = 0;                                 /* flag */
  return route;
}
