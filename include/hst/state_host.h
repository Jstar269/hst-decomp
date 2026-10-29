/* Object that owns a target record (flag byte at 0x90a) and a value at 0x80 it restores around a state call. */
#ifndef HST_STATE_HOST_H
#define HST_STATE_HOST_H

#include "hst/types.h"

typedef struct StateFlagTarget {
  char pad00[0x90a];
  u8 unk90a;       /* 0x90a flag set or cleared by the callers */
} StateFlagTarget;

typedef struct StateHost {
  char pad00[0x54];
  StateFlagTarget *target; /* 0x54 */
  char pad58[0x28];
  u32 unk80;       /* 0x80 value kept across the state call */
} StateHost;

#endif
