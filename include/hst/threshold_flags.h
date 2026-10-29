/* Per-slot threshold flag bytes: two banks of four, set when a gauge ratio crosses a limit. */
#ifndef HST_THRESHOLD_FLAGS_H
#define HST_THRESHOLD_FLAGS_H

#include "hst/types.h"

enum { THRESHOLD_SLOTS = 4 };

typedef struct ThresholdFlags {
  char pad00[0x95];
  u8 low[THRESHOLD_SLOTS];  /* 0x95 set once the ratio reaches the low limit */
  u8 high[THRESHOLD_SLOTS]; /* 0x99 set once the ratio reaches the high limit */
} ThresholdFlags;

#endif
