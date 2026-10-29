/* Small state-switch object: current and previous state ids, with virtual hooks run on each change. */
#ifndef HST_STATE_SWITCH_H
#define HST_STATE_SWITCH_H

#define STATE_SWITCH_NONE (-1) /* state id before the first change */

typedef struct StateSwitch {
  void *vtable;          /* 0x00 */
  int state;             /* 0x04 current state id */
  int unk08;             /* 0x08 reset to 0 on each change, -1 after a timed-out request */
  int duration;          /* 0x0c reset to 0 on each change, set to the requested length otherwise */
  int next_state;        /* 0x10 requested next state id */
  int prev_state;        /* 0x14 state id before the last change */
} StateSwitch;

#endif
