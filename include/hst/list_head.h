/* Header of a doubly linked list: element count followed by the sentinel's links (empty = both point at the sentinel). */
#ifndef HST_LIST_HEAD_H
#define HST_LIST_HEAD_H

#include "hst/types.h"

typedef struct DListLinks {
  struct DListLinks *prev;  /* 0x00 */
  struct DListLinks *next;  /* 0x04 */
} DListLinks;

typedef struct DListHead {
  u32 size;                /* 0x00 number of elements */
  DListLinks sentinel;      /* 0x04 end marker node */
} DListHead;                /* size 0x0c */

#endif
