/* Host object of the mode-transition sources and the control record it points to. */
#ifndef HST_MODE_HOST_H
#define HST_MODE_HOST_H

#include "hst/types.h"

/* Control record: only the word at +0x1c is named. */
typedef struct ModeCtl {
  char pad00[0x1c];
  int unk1c;        /* 0x1c cleared before a transition */
} ModeCtl;

typedef struct ModeHost {
  char pad00[0x14c0];
  ModeCtl *ctl;     /* 0x14c0 */
} ModeHost;

#endif
