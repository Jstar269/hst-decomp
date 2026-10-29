/* Owner object whose +0x40 pointer reaches a block holding four 0x458-byte entries. */
#ifndef HST_UNIT_BLOCK_H
#define HST_UNIT_BLOCK_H

#include "hst/types.h"

#define UNIT_ENTRY_COUNT 4

typedef struct UnitEntry {
  char pad00[0x2c];
  int key;                /* 0x2c compared with a looked-up key */
  char pad30[0x458 - 0x30];
} UnitEntry;              /* size 0x458 */

typedef struct UnitBlock {
  char pad0000[0x1bac];
  UnitEntry entry[UNIT_ENTRY_COUNT]; /* 0x1bac */
} UnitBlock;

typedef struct UnitOwner {
  char pad00[0x40];
  UnitBlock *block;       /* 0x40 */
} UnitOwner;

#endif
