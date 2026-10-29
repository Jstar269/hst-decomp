/* HSTMATCH module=hstp_trans_main.prx start=0x001c5ee4 end=0x001c5f20 symbol=FUN_001c5ee4 lang=c99 */
/* Clone of src/eboot/FUN_001b8224.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern int FUN_001bfc3c();

typedef struct TimerObj {
  char pad00[0x8c];
  int timer;                  /* 0x8c frames left, counted down to zero */
} TimerObj;

enum { SOUND_TIMER_DONE = 0x45 };

/* Counts the timer down and plays the sound when it runs out. */
void FUN_001c5ee4(TimerObj *self)
{
  int remaining;
  
  if ((0 < self->timer) &&
     (remaining = self->timer + -1, self->timer = remaining, remaining < 1)) {
    FUN_001bfc3c((int *)&DAT_003eaad8,SOUND_TIMER_DONE);
  }
}
