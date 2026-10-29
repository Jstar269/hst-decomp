/* Object stepping through queued 12-byte entries held in an owner's block deque. */
#ifndef HST_TICK_OBJ_H
#define HST_TICK_OBJ_H

#include "hst/types.h"
#include "hst/deque_owner.h"

#define TICK_BLOCK_ELEMS 42     /* entries per deque block */
#define TICK_COUNTDOWN_START 45 /* value the countdown is reloaded with after the entries are advanced */

/* Queued entry: a selector, a word and a float value. */
typedef struct TickEntry {
  int kind;       /* 0x0 */
  int unk4;       /* 0x4 */
  float value;    /* 0x8 */
} TickEntry;      /* size 0xc */

/* Queue of entries in fixed-size blocks (same shape as BlockDeque, with unsigned index fields). */
typedef struct TickQueue {
  u32 capacity;           /* 0x00 slots in the block map */
  int count;              /* 0x04 slots in use */
  u32 head;               /* 0x08 map index of the first block */
  TickEntry **blocks;     /* 0x0c */
  u32 first;              /* 0x10 index of the first queued entry */
  int length;             /* 0x14 entries queued */
} TickQueue;

/* The object holds the current entry and the one after it, and a countdown to the next advance. */
typedef struct TickObj {
  char pad00[0x3c];
  DequeOwner *owner;      /* 0x3c owner object; its deque at 0x2f8 holds the queued entries */
  char pad40[0xb0 - 0x40];
  TickEntry cur;          /* 0xb0 */
  TickEntry next;         /* 0xbc */
  u8 unkc8;               /* 0xc8 */
  char padc9[3];
  int countdown;          /* 0xcc */
} TickObj;

#endif
