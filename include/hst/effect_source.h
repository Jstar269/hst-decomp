/* Effect source object of the 0x28a000 sources: two model holders, a record vector and an effect handle. */
#ifndef HST_EFFECT_SOURCE_H
#define HST_EFFECT_SOURCE_H

#include "hst/model_holder.h"

#define EFFECT_NONE (-1)      /* effect handle value when no effect is bound */

/* Constructor argument block. */
typedef struct EffectInit {
  I3rStream *stream0;         /* 0x00 attached to the first holder */
  I3rStream *stream1;         /* 0x04 attached to the second holder */
  I3rStream *stream2;         /* 0x08 preferred over stream0 as the object's own stream */
  int unk0c;                  /* 0x0c */
} EffectInit;

/* One 0x1c-byte record of the vector at +0xe0. */
typedef struct EffectRec {
  char pad00[4];
  short unk4;                 /* 0x04 */
  short pos;                  /* 0x06 compared with the holder's [unk104, unk104 + unk100) range */
  short nodeId;               /* 0x08 matrix index passed to the matrix getter */
  char pada[2];
  float unkc;                 /* 0x0c */
  char pad10[0x1c - 0x10];
} EffectRec;

typedef struct EffectRecVec {
  EffectRec *data;            /* 0x0 */
  int count;                  /* 0x4 */
  int cap;                    /* 0x8 */
} EffectRecVec;

typedef struct EffectSource {
  void *vtable;               /* 0x00 */
  char pad04[0x54 - 4];
  unsigned char waiting;      /* 0x54 cleared once every track is ready */
  char pad55[0x70 - 0x55];
  I3rStream *stream;          /* 0x70 */
  ModelHolder *modelA;        /* 0x74 owned */
  ModelHolder *modelB;        /* 0x78 owned */
  int unk7c;                  /* 0x7c */
  char unk80[8];              /* 0x80 */
  int unk88;                  /* 0x88 */
  char pad8c[0xa8 - 0x8c];
  int unka8;                  /* 0xa8 */
  unsigned char unkac;        /* 0xac */
  char padad;
  char name[0xe0 - 0xae];     /* 0xae text */
  EffectRecVec recs;          /* 0xe0 */
  unsigned char started;      /* 0xec */
  char padED[3];
  int effect;                 /* 0xf0 effect handle, EFFECT_NONE when none */
} EffectSource;

#endif
