/* Timed ramp object: a duration/remaining pair and two 4-float values (start and end) blended by progress. */
#ifndef HST_RAMP_OBJ_H
#define HST_RAMP_OBJ_H

/* Limit used when the caller passes a negative one. */
#define RAMP_DEFAULT_LIMIT 4000.0f

typedef struct RampVec4 {
  float x, y, z, w;
} RampVec4;

typedef struct RampObj {
  char pad00[4];
  void *handle;              /* 0x04 object whose mode is set by the setup functions */
  float duration;            /* 0x08 */
  float remaining;           /* 0x0c starts equal to duration */
  float unk10;               /* 0x10 set to -1.0f by setup */
  char pad14[0xc];
  RampVec4 from;             /* 0x20 */
  RampVec4 to;               /* 0x30 */
  unsigned char unk40;       /* 0x40 */
  unsigned char unk41;       /* 0x41 */
  char pad42[2];
  float limit;               /* 0x44 */
  char pad48[8];
  unsigned char unk50;       /* 0x50 */
  unsigned char unk51;       /* 0x51 */
  unsigned char unk52;       /* 0x52 */
  unsigned char unk53;       /* 0x53 */
  float unk54;               /* 0x54 */
} RampObj;

#endif
