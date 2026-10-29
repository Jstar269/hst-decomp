/* Scene-node item: a vtable object holding an owned helper, a node pointer and several embedded members. */
#ifndef HST_NODE_ITEM_H
#define HST_NODE_ITEM_H

#include "hst/types.h"

#define NODE_ITEM_LIMIT_BITS 0x47c35000 /* bit pattern stored in the limit word at construction */

typedef struct NodeItem {
  const void *vtable; /* 0x00 */
  u32 unk04;          /* 0x04 first embedded member (3 words), torn down by the destructor */
  u32 unk08;          /* 0x08 */
  u32 unk0c;          /* 0x0c */
  u32 unk10;          /* 0x10 second embedded member (3 words) */
  u32 unk14;          /* 0x14 */
  u32 unk18;          /* 0x18 */
  void *unk1c;        /* 0x1c owned, deleted through its virtual destructor */
  void *node;         /* 0x20 node the item is attached to */
  u8 unk24;           /* 0x24 */
  char pad25[3];
  u32 unk28;          /* 0x28 third embedded member (3 words) */
  u32 unk2c;          /* 0x2c */
  u32 unk30;          /* 0x30 */
  u32 unk34;          /* 0x34 fourth embedded member (3 words) */
  u32 unk38;          /* 0x38 */
  u32 unk3c;          /* 0x3c */
  u32 unk40;          /* 0x40 fifth embedded member (3 words) */
  u32 unk44;          /* 0x44 */
  u32 unk48;          /* 0x48 */
  u32 limit;          /* 0x4c */
  u8 unk50;           /* 0x50 */
} NodeItem;

#endif
