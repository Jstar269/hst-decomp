/* Container of 12-byte tagged elements (heap-backed when bit 0 of the tag word is set) and its element type. */
#ifndef HST_TAGGED_DEQUE_H
#define HST_TAGGED_DEQUE_H

#include "hst/types.h"

#define TAGGED_ON_HEAP 1 /* bit of TaggedElem.flags: the contents live in a separate heap block */

/* Element: a tag word, a length and a pointer to the heap block. */
typedef struct TaggedElem {
  u32 flags;     /* 0x00 */
  int len;       /* 0x04 contents length (heap form) */
  char *data;    /* 0x08 heap block (heap form) */
} TaggedElem;

/* Container: element storage with a first-element offset and a count. */
typedef struct TaggedDeque {
  TaggedElem *buf;   /* 0x00 storage block */
  int size;          /* 0x04 elements in use */
  char pad08[8];
  int start;         /* 0x10 index of the first element in the block */
} TaggedDeque;

#endif
