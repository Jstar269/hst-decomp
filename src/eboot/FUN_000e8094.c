/* HSTMATCH module=EBOOT.BIN start=0x000e8094 end=0x000e80f0 symbol=FUN_000e8094 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/spin_obj.h"

enum { ANGLE_STEP = 10, FULL_TURN = 360 };

/* Per-tick update: timer counts down, angle advances (mod a full turn), scale and tick count grow. */
void FUN_000e8094(SpinObj *obj)
{
  int angle;
  
  obj->timer = obj->timer - 0.14285715f;
  angle = obj->angle + ANGLE_STEP;
  obj->angle = angle;
  obj->angle = angle % FULL_TURN;
  obj->scale = obj->scale + 0.2f;
  obj->ticks = obj->ticks + 1;
}
