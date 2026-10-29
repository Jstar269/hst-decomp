/* HSTMATCH module=EBOOT.BIN start=0x0011acfc end=0x0011ae7c symbol=FUN_0011acfc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

#define ELEMS_PER_BLOCK 0x2a  /* queue elements per block */

extern char DAT_0033b480;
extern int DAT_002d9ba4;

extern void FUN_0001f1fc();
extern void FUN_0011c998();

typedef struct Entry {
  int kind;
  int amount;
  float param;
} Entry;

/* Block queue of Entry records (block map plus start/size of the elements). */
typedef struct EntryQueue {
  u32 map_cap;
  int map_size;
  u32 map_start;
  Entry **map;
  u32 start;
  int size;
} EntryQueue;

typedef struct Self {
  char pad0[0x3c];
  char *owner;      /* 0x3c */
  char pad1[0x70];
  int kind;         /* 0xb0 */
  int amount;       /* 0xb4 */
  float param;      /* 0xb8 */
  int kind2;        /* 0xbc */
  int amount2;      /* 0xc0 */
  float param2;     /* 0xc4 */
  char pad2[4];
  int count;        /* 0xcc */
} Self;

/* Counts down; at zero loads the next two queued entries into the task, or ends the task when the queue is empty. */
void FUN_0011acfc(Self *self)
{
  int n = self->count - 1;
  self->count = n;
  if (n >= 1) {
    return;
  }
  EntryQueue *q = (EntryQueue *)(self->owner + 0x2e0);
  if (q->size != 0) {
    Entry *first = (Entry *)((char *)q->map[(q->map_start + q->start / ELEMS_PER_BLOCK) % q->map_cap] + (q->start % ELEMS_PER_BLOCK) * 0xc);
    self->kind = first->kind;
    self->amount = first->amount;
    self->param = first->param;
    FUN_0011c998(q);
    if (q->size != 0) {
      Entry *second = (Entry *)((char *)q->map[(q->map_start + q->start / ELEMS_PER_BLOCK) % q->map_cap] + (q->start % ELEMS_PER_BLOCK) * 0xc);
      self->kind2 = second->kind;
      self->amount2 = second->amount;
      self->param2 = second->param;
      FUN_0011c998(q);
    }
    else {
      self->amount2 = 0;
    }
    self->count = DAT_002d9ba4;
  }
  else {
    FUN_0001f1fc(self, 0);
    DAT_0033b480 = 0;
  }
}
