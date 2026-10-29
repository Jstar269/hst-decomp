/* Object holding a four-float position at 0x30 and an int at 0x40 (range and item check sources). */
#ifndef HST_RANGE_OBJ_H
#define HST_RANGE_OBJ_H

typedef struct RangeObj {
  char pad00[0x30];
  float pos[4];     /* 0x30 */
  int unk40;        /* 0x40 */
} RangeObj;

#endif
