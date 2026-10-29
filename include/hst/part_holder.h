/* Holder object with four owned parts (A to D) and a mode switch; shared by its constructor, destructor, creator and mode sources. */
#ifndef HST_PART_HOLDER_H
#define HST_PART_HOLDER_H

#include "hst/types.h"

/* Values of PartHolder.mode set by the mode switch. */
enum {
  HOLDER_MODE_SYNC = 0,   /* widgets follow the enabled flag */
  HOLDER_MODE_OFF = 1,    /* disabled look */
  HOLDER_MODE_ON = 2,     /* enabled look */
  HOLDER_MODE_SHOW = 3,   /* global overlay shown */
  HOLDER_MODE_HIDE = 4,   /* global overlay hidden */
  HOLDER_MODE_NONE = 5    /* initial state, also used while part C does not exist */
};

typedef struct PartA {
  char pad00[0x5c];
  u8 enabled;             /* 0x5c */
  char pad5d[3];
} PartA;                  /* size 0x60 */

typedef struct PartB {
  void *vtbl;             /* 0x00 */
  char pad04[0x60];
  void *widget64;         /* 0x64 */
  void *widget68;         /* 0x68 */
  char pad6c[4];
  void *widget70;         /* 0x70 */
  void *widget74;         /* 0x74 */
  u32 *unk78;             /* 0x78 */
  void *widget7c;         /* 0x7c */
  void *slot[3];          /* 0x80 */
  int cur;                /* 0x8c index into slot, reset by the mode switch */
  u8 enabled;             /* 0x90 */
  char pad91[3];
} PartB;                  /* size 0x94 */

typedef struct PartC {
  char pad00[0x60];
  void *widget[6];        /* 0x60 */
  char pad78[4];
  u8 unk7c;               /* 0x7c */
  u8 unk7d;               /* 0x7d */
  char pad7e[2];
} PartC;                  /* size 0x80 */

typedef struct PartD {
  char pad00[0x470];
} PartD;                  /* size 0x470 */

typedef struct PartHolder {
  void *vtbl;             /* 0x00 */
  char pad04[0x38];
  PartB *partB;           /* 0x3c */
  PartC *partC;           /* 0x40 */
  PartA *partA;           /* 0x44 */
  PartD *partD;           /* 0x48 */
  int mode;               /* 0x4c HOLDER_MODE_* */
  int timer;              /* 0x50 */
  u8 enabled;             /* 0x54 */
  char pad55[3];
} PartHolder;             /* size 0x58 */

#endif
