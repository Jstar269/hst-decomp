/* HSTMATCH module=EBOOT.BIN start=0x0011b7f0 end=0x0011b96c symbol=FUN_0011b7f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/tick_obj.h"

extern char DAT_0033b488;

extern void FUN_0001f1fc();
extern void FUN_0011cd48();

/* Counts down; at zero loads the current entry from the front of the owner's queue and pops it, then loads
   the next entry the same way (or clears its second word when the queue ran empty). With nothing queued it
   resets the object and clears a flag instead. */
void FUN_0011b7f0(TickObj *self)
{
  int n = self->countdown - 1;
  self->countdown = n;
  if (n >= 1) {
    return;
  }
  TickQueue *queue = (TickQueue *)&self->owner->deque2f8;
  if (queue->length != 0) {
    TickEntry *e = (TickEntry *)((char *)queue->blocks[(queue->head + queue->first / TICK_BLOCK_ELEMS) % queue->capacity] + (queue->first % TICK_BLOCK_ELEMS) * 0xc);
    self->cur.kind = e->kind;
    self->cur.unk4 = e->unk4;
    self->cur.value = e->value;
    FUN_0011cd48(queue);
    if (queue->length != 0) {
      TickEntry *e2 = (TickEntry *)((char *)queue->blocks[(queue->head + queue->first / TICK_BLOCK_ELEMS) % queue->capacity] + (queue->first % TICK_BLOCK_ELEMS) * 0xc);
      self->next.kind = e2->kind;
      self->next.unk4 = e2->unk4;
      self->next.value = e2->value;
      FUN_0011cd48(queue);
    }
    else {
      self->next.unk4 = 0;
    }
    self->countdown = TICK_COUNTDOWN_START;
  }
  else {
    FUN_0001f1fc(self, 0);
    DAT_0033b488 = 0;
  }
}
