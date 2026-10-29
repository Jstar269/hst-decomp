/* HSTMATCH module=hstp_trans_main.prx start=0x00210984 end=0x002109a4 symbol=FUN_00210984 lang=c99 */
/* Clone of src/eboot/FUN_002021b4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ActiveTimer {
  u8 active;      /* 0x00 */
  char pad1[0x13];
  float timer;    /* 0x14 */
} ActiveTimer;

/* Adds dt to the timer while the object is active. */
void FUN_00210984(float dt,ActiveTimer *obj)
{
  if (obj->active != '\0') {
    obj->timer = obj->timer + dt;
  }
}
