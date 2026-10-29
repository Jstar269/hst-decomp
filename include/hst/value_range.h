/* A clamped float value with its limits, and the owner object that points at it. */
#ifndef HST_VALUE_RANGE_H
#define HST_VALUE_RANGE_H

typedef struct ValueRange {
  char pad00[0x18];
  float value;     /* 0x18 current value, kept within [lo, hi] */
  float lo;        /* 0x1c */
  float hi;        /* 0x20 */
} ValueRange;

typedef struct RangeOwner {
  char pad00[0x64];
  ValueRange *range; /* 0x64 */
} RangeOwner;

#endif
