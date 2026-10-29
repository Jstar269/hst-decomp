/* Block-map deque layouts: the circular map of block pointers, the deque around it and its position iterator. */
#ifndef HST_BLOCK_DEQUE_H
#define HST_BLOCK_DEQUE_H

#include "hst/types.h"

/* Circular map of block pointers. */
typedef struct BlockMap {
  int capacity;    /* 0x00, slots in the map */
  int count;       /* 0x04, slots in use */
  int head;        /* 0x08, index of the first used slot */
  void **blocks;   /* 0x0c */
} BlockMap;

/* Deque of elements stored in fixed-size blocks. */
typedef struct BlockDeque {
  BlockMap map;    /* 0x00 */
  int first;       /* 0x10, index of the first element inside the block run */
  int length;      /* 0x14, elements stored */
} BlockDeque;

/* Position inside a BlockDeque: map cursor plus the current block's element span. */
typedef struct BlockDequePos {
  void **map_cur;     /* 0x00, current map slot */
  void **map_begin;   /* 0x04 */
  void **map_head;    /* 0x08 */
  void **map_end;     /* 0x0c */
  char *elem;         /* 0x10, current element */
  char *block_end;    /* 0x14, end of the current block */
} BlockDequePos;

#endif
