/* Sorted map used by the 0x229000 sources: the tree object holds the root and its own end sentinel. */
#ifndef HST_TREE_MAP_H
#define HST_TREE_MAP_H

#include "hst/types.h"

typedef struct TreeNode {
  char pad00[0xc];
  u32 key;                  /* 0x0c */
  int value;                /* 0x10 */
} TreeNode;

/* Tree object (0x10 bytes); the address of root doubles as the end iterator. */
typedef struct TreeMap {
  u32 unk00;                /* 0x00 cleared together with the root */
  TreeNode *root;           /* 0x04 */
  u32 unk08;                /* 0x08 */
  TreeNode *first;          /* 0x0c leftmost node, the begin iterator */
} TreeMap;

/* Two trees side by side: names to ids, and (id, sub-key) pairs to values. */
typedef struct TreePair {
  TreeMap names;            /* 0x00 */
  TreeMap pairs;            /* 0x10 */
} TreePair;

/* Key of the second tree: id in the high half, sub-key in the low half. */
#define PAIR_KEY(id, sub) ((((id) << 16) & 0xffff0000) | ((sub) & 0xffff))

#endif
