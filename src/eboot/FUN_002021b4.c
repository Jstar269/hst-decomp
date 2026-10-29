/* HSTMATCH module=EBOOT.BIN start=0x002021b4 end=0x002021d4 symbol=FUN_002021b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ActiveTimer {
  u8 active;      /* 0x00 */
  char pad1[0x13];
  float timer;    /* 0x14 */
} ActiveTimer;

/* Adds dt to the timer while the object is active. */
void FUN_002021b4(float dt,ActiveTimer *obj)
{
  if (obj->active != '\0') {
    obj->timer = obj->timer + dt;
  }
}
