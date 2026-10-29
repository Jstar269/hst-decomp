/* HSTMATCH module=EBOOT.BIN start=0x001ed1dc end=0x001ed27c symbol=FUN_001ed1dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: loop counter and indexed entry stores (store order in the loop); readability pass; exact match verified; names and types await human review. */

#include "hst/prize_camera.h"

extern unsigned char DAT_00309524;
extern void * FUN_00060e2c();

/* Constructor: base constructor, then clears the state and gives both settings entries their defaults. */
PrizeCamera * FUN_001ed1dc(PrizeCamera *cam)
{
  unsigned int i;
  
  FUN_00060e2c();
  cam->vtable = &DAT_00309524;
  cam->res = 0;
  cam->unke8 = 0;
  cam->unke9 = 0;
  cam->unk94 = 0;
  cam->unk98 = 0;
  i = 0;
  do {
    cam->ent[i].rot_speed = 0;
    cam->ent[i].tilt = 0;
    cam->ent[i].tilt_win = 0;
    cam->ent[i].distance = 5.0f;
    cam->ent[i].fov_x = 45.0f;
    cam->ent[i].offset_y = 0;
    cam->ent[i].near_plane = 0.2f;
    cam->ent[i].far_plane = 1000.0f;
    cam->ent[i].default_angle_y = 0;
    i = i + 1;
  } while (i < 2);
  cam->sel = 0;
  cam->unkea = 0;
  return cam;
}
