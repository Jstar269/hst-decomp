/* Save/load style screen object: a state id, a worker sub-object and six message buffers. */
#ifndef HST_SAVEDATA_SCREEN_H
#define HST_SAVEDATA_SCREEN_H

#include "hst/types.h"

#define SAVE_TEXT_COUNT 6    /* message buffers */
#define SAVE_TEXT_SIZE 0x180 /* bytes per message buffer */

enum {
  SAVE_STATE_IDLE = 0,    /* not started */
  SAVE_STATE_MESSAGE = 1, /* shows one message */
  SAVE_STATE_RUN = 2,     /* runs the operation with its message set */
  SAVE_STATE_DONE = 3
};

typedef struct SaveScreen {
  void *vtbl;             /* 0x00 */
  char pad04[0x3c];
  char worker[0x5d0 - 0x40]; /* 0x40 sub-object driven by the RUN state */
  int state;              /* 0x5d0 one of SAVE_STATE_* */
  int unk5d4;             /* 0x5d4 cleared when the operation could not be started */
  char text[SAVE_TEXT_COUNT][SAVE_TEXT_SIZE]; /* 0x5d8 message buffers */
} SaveScreen;

#endif
