/* Animator object (four timed blocks at +0x24/+0x3c/+0x54/+0x78) and the step counter used by the 0x217000 sources. */
#ifndef HST_ANIMATOR_H
#define HST_ANIMATOR_H

#include "hst/types.h"
#include "hst/mode_parts.h"

/* Start of every timed block. */
typedef struct AnimHead {
  u8 active;    /* 0x00 */
  u8 done;      /* 0x01 */
  char pad02[2];
  int duration; /* 0x04 */
  int counter;  /* 0x08 */
} AnimHead;     /* size 0xc */

typedef struct AnimPos {
  AnimHead head;
  short to[4];  /* 0x0c */
  short cur[2]; /* 0x14 */
} AnimPos;      /* size 0x18 */

typedef struct AnimColor {
  AnimHead head;
  short from[4]; /* 0x0c one channel per word */
  short to[4];   /* 0x14 */
  short cur[4];  /* 0x1c */
} AnimColor;    /* size 0x24 */

typedef struct AnimPair {
  AnimHead head;
  short to[2];  /* 0x0c */
  short cur;    /* 0x10 */
  char pad12[2];
} AnimPair;     /* size 0x14 */

typedef struct Animator {
  int src;            /* 0x00 */
  ModeNode *node;     /* 0x04 placed node whose x/y seed the position */
  short x;            /* 0x08 */
  short y;            /* 0x0a */
  u16 unk0c;          /* 0x0c */
  char pad0e[2];
  int unk10;          /* 0x10 */
  char pad14[0x10];
  AnimPos pos;        /* 0x24 */
  AnimHead block3c;   /* 0x3c only cleared here */
  char pad48[0xc];
  AnimColor color;    /* 0x54 */
  AnimPair pair;      /* 0x78 */
} Animator;           /* size 0x8c */

/* Counter that eases `value` towards base + unit * steps over `limit` ticks. */
typedef struct StepCounter {
  const void *vtbl; /* 0x00 */
  int unk04;        /* 0x04 */
  int unit;         /* 0x08 */
  char pad0c[0x10];
  int value;        /* 0x1c */
  u8 running;       /* 0x20 */
  u8 finished;      /* 0x21 */
  char pad22[2];
  int steps;        /* 0x24 */
  int base;         /* 0x28 */
  int counter;      /* 0x2c */
  int limit;        /* 0x30 */
} StepCounter;

#endif
