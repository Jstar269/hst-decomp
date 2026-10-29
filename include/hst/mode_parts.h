/* Mode object (vtable + part set at +0x3c) and its 13-part set built by the 0x225000 sources. */
#ifndef HST_MODE_PARTS_H
#define HST_MODE_PARTS_H

#include "hst/types.h"

#define MODE_PART_COUNT 13

#define MODE_NODE_MAX 14
#define MODE_POS_MAX 16

struct ModePart18; /* layout is defined by the sources that use it */

/* A placed object with a 2D position at +0x60. */
typedef struct ModeNode {
  char pad00[0x60];
  float x; /* 0x60 */
  float y; /* 0x64 */
} ModeNode;

/* The part at +0x24: a list of nodes plus their base positions. */
typedef struct ModePart24 {
  char pad00[0x5c];
  ModeNode *nodes[MODE_NODE_MAX]; /* 0x5c */
  int node_count;                 /* 0x94 highest used index + 1 */
  float xs[MODE_POS_MAX];         /* 0x98 */
  float ys[MODE_POS_MAX];         /* 0xd8 */
} ModePart24;

/* The part at +0x20: the resets write three of its words. */
typedef struct ModePart20 {
  char pad00[0x78];
  int unk78; /* 0x78 reset to -1 */
  int unk7c; /* 0x7c reset to 0 */
  int unk80; /* 0x80 reset to 0 */
} ModePart20;

/* Part set; the pointers are owned (deleted by the mode object's destructor). */
typedef struct ModeParts {
  void *part00;             /* 0x00 */
  void *part04;             /* 0x04 */
  void *part08;             /* 0x08 */
  void *part0c;             /* 0x0c */
  void *part10;             /* 0x10 */
  void *part14;             /* 0x14 never filled in */
  struct ModePart18 *part18; /* 0x18 */
  void *part1c;             /* 0x1c */
  ModePart20 *part20;       /* 0x20 */
  ModePart24 *part24;       /* 0x24 */
  void *part28;             /* 0x28 */
  void *part2c;             /* 0x2c */
  void *part30;             /* 0x30 */
  char pad34[8];
} ModeParts; /* size 0x3c */

typedef struct ModeObj {
  const void *vtbl; /* 0x00 */
  char pad04[0x38];
  ModeParts *parts; /* 0x3c */
} ModeObj;

#endif
