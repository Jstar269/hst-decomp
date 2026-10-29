/* Object that queues four-slot entries to start: the queue deque and the per-slot arrays. */
#ifndef HST_SLOT_QUEUE_H
#define HST_SLOT_QUEUE_H

#define SLOT_QUEUE_COUNT 4         /* slots handled by the object */
#define SLOT_QUEUE_NAME_LEN 17     /* bytes per slot name */
#define SLOT_QUEUE_BLOCK_ELEMS 128 /* queued ints per deque block */

enum { SLOT_STATE_PENDING = 2 };   /* value of state[] while a slot waits for its start to finish */

/* Deque of ints held in blocks of SLOT_QUEUE_BLOCK_ELEMS (block map, then start index and length). */
typedef struct SlotDeque {
  unsigned capacity;      /* 0x00 slots in the block map */
  unsigned count;         /* 0x04 slots in use */
  unsigned head;          /* 0x08 map index of the first block */
  int **blocks;           /* 0x0c */
  unsigned first;         /* 0x10 index of the first queued int */
  unsigned length;        /* 0x14 ints queued */
} SlotDeque;

typedef struct SlotQueueObj {
  int cur;                                        /* 0x000 slot being started */
  unsigned char ready[SLOT_QUEUE_COUNT];          /* 0x004 */
  int arg[SLOT_QUEUE_COUNT];                      /* 0x008 */
  char name[SLOT_QUEUE_COUNT][SLOT_QUEUE_NAME_LEN]; /* 0x018 */
  unsigned char kind[SLOT_QUEUE_COUNT];           /* 0x05c */
  int unk60[SLOT_QUEUE_COUNT];                    /* 0x060 passed to the slot entry's virtual call */
  char pad70[0xf0 - 0x70];
  unsigned char unkf0[8];                         /* 0x0f0 */
  int count;                                      /* 0x0f8 slots in use */
  char padfc[0x19c - 0xfc];
  int slot[SLOT_QUEUE_COUNT][SLOT_QUEUE_COUNT];   /* 0x19c cleared when a slot is set up */
  int state[SLOT_QUEUE_COUNT];                    /* 0x1dc */
  SlotDeque queue;                                /* 0x1ec slots waiting to start */
} SlotQueueObj;

#endif
