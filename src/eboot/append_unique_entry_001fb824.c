/* HSTMATCH module=EBOOT.BIN start=0x001fb824 end=0x001fb8a0 symbol=FUN_001fb824 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: recovered the 20-entry key/value/count record layout and index-first table access; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { QUEUE_CAPACITY = 20 };

/* Key/value queue embedded in a larger object. */
struct QueueView {
  char pad[0x3c];
  int keys[QUEUE_CAPACITY];     /* 0x3c */
  int values[QUEUE_CAPACITY];   /* 0x8c */
  int count;                    /* 0xdc entries in use */
};

/* Appends (key, value) unless the key is already present or the queue is full. */
void FUN_001fb824(int obj,int key,u32 value)
{
  int found;
  int i;
  int key_addr;
  
  found = false;
  i = 0;
  key_addr = obj;
  do {
    if (*(int *)(key_addr + 0x3c) == key) {
      found = true;
      break;
    }
    i = i + 1;
    key_addr = key_addr + 4;
  } while (i < QUEUE_CAPACITY);
  if (!found) {
    struct QueueView *queue = (struct QueueView *)obj;
    i = queue->count;
    if (i < 0) return;
    if (i < QUEUE_CAPACITY) {
      queue->keys[i] = key;
      queue->values[queue->count] = value;
      queue->count = queue->count + 1;
    }
  }
}
