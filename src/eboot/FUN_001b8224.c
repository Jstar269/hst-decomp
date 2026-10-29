/* HSTMATCH module=EBOOT.BIN start=0x001b8224 end=0x001b8260 symbol=FUN_001b8224 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern int FUN_001b1c44();

typedef struct TimerObj {
  char pad00[0x8c];
  int timer;                  /* 0x8c frames left, counted down to zero */
} TimerObj;

enum { SOUND_TIMER_DONE = 0x45 };

/* Counts the timer down and plays the sound when it runs out. */
void FUN_001b8224(TimerObj *self)
{
  int remaining;
  
  if ((0 < self->timer) &&
     (remaining = self->timer + -1, self->timer = remaining, remaining < 1)) {
    FUN_001b1c44((int *)&DAT_0034179c,SOUND_TIMER_DONE);
  }
}
