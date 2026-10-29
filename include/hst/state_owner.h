/* Object with a state id at +0x1b0 and a mode/previous-mode pair, plus the global flag block that gates mode requests. */
#ifndef HST_STATE_OWNER_H
#define HST_STATE_OWNER_H

#include "hst/types.h"

#define OWNER_STATE_LOCKED 5 /* mode requests are ignored in this state */

typedef struct StateOwner {
  char pad000[0x1b0];
  int state;              /* 0x1b0 */
  char pad1b4[4];
  int mode;               /* 0x1b8 current mode */
  int unk1bc;             /* 0x1bc cleared on every mode change */
  int prevMode;           /* 0x1c0 mode before the last change */
} StateOwner;

enum {
  MODE_REQUESTED_0 = 1,   /* flag: mode 0 was requested once */
  MODE_REQUESTED_1 = 2    /* flag: mode 1 was requested once */
};

/* Global block reached through the setup pointer; only the request flags are used here. */
typedef struct RequestFlags {
  char pad00[0x86d10];
  u32 flags;              /* 0x86d10 MODE_REQUESTED_* bits */
} RequestFlags;

#endif
