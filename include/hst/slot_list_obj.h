/* Object with a base part, a float pair, owned sub-objects and a table of seven owned slots. */
#ifndef HST_SLOT_LIST_OBJ_H
#define HST_SLOT_LIST_OBJ_H

#include "hst/types.h"

#define SLOT_LIST_COUNT 7 /* length of the owned slot table */

typedef struct SlotListObj {
  u32 vtable;                      /* 0x00 */
  u32 unk04;                       /* 0x04 bit pattern of 30.0f after reset */
  u32 unk08;                       /* 0x08 bit pattern of 30.0f after reset */
  void *ownedA;                    /* 0x0c owned sub-object, deleted by the destructor */
  void *ownedB;                    /* 0x10 owned sub-object, freed by a helper */
  char pad14[4];
  void *slots[SLOT_LIST_COUNT];    /* 0x18 owned slot objects */
  char pad34[4];
  float unk38;                     /* 0x38 */
  char pad3c[4];
  u8 unk40;                        /* 0x40 */
  char pad41[0xb];
  u8 unk4c;                        /* 0x4c */
  u8 unk4d;                        /* 0x4d */
  u8 unk4e;                        /* 0x4e */
  char pad4f;
  u32 unk50;                       /* 0x50 */
  u8 unk54;                        /* 0x54 */
} SlotListObj;

#endif
