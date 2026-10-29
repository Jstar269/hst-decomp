/* HSTMATCH module=hstp_trans_main.prx start=0x000ed168 end=0x000ed1c4 symbol=FUN_000ed168 lang=c99 */
/* Clone of src/eboot/FUN_000e8094.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/spin_obj.h"

enum { ANGLE_STEP = 10, FULL_TURN = 360 };

/* Per-tick update: timer counts down, angle advances (mod a full turn), scale and tick count grow. */
void FUN_000ed168(SpinObj *obj)
{
  int angle;
  
  obj->timer = obj->timer - 0.14285715f;
  angle = obj->angle + ANGLE_STEP;
  obj->angle = angle;
  obj->angle = angle % FULL_TURN;
  obj->scale = obj->scale + 0.2f;
  obj->ticks = obj->ticks + 1;
}
