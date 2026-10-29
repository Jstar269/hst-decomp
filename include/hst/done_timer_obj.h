/* Object with a done flag and a timer at +0x60, finished/started by two small methods. */
#ifndef HST_DONE_TIMER_OBJ_H
#define HST_DONE_TIMER_OBJ_H

#include "hst/types.h"

typedef struct DoneTimerObj {
  char pad00[0x54];
  u8 done;          /* 0x54 set to 1 when finished, 0 when started */
  char pad55[0xb];
  int timer;        /* 0x60 set to -1 when finished */
} DoneTimerObj;

#endif
