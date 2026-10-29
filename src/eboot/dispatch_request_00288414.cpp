/* HSTMATCH module=EBOOT.BIN start=0x00288414 end=0x00288470 symbol=FUN_00288414 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed Request struct layout with aligned(16) and float parameter; readability pass; exact match verified; names and types await human review. */
#include "hst/mode_obj.h"

/* Frame of the queue call: list position, out-iterator slot and the queued record (tag, count, f, value). */
struct Request {
  QueueNode *pos;
  char result[4];
  int tag;
  int count;
  float f;
  int value;
} __attribute__((aligned(16)));

enum { REQUEST_TAG_QUEUED = 0x4e };

extern "C" void *DAT_0034a114;
extern "C" void FUN_001c7e58(void *);
extern "C" void FUN_00289544(char *, RequestList *, QueueNode **, int *);

/* count < 1: call FUN_001c7e58 on the global; otherwise queue a record. */
extern "C" void FUN_00288414(QueueObj *self, int value, int count, float f)
{
  struct Request request;
  if (count < 1) {
    FUN_001c7e58(DAT_0034a114);
  } else {
    request.tag = REQUEST_TAG_QUEUED;
    request.value = value;
    request.count = count;
    request.f = f;
    request.pos = &self->queue.sentinel;
    FUN_00289544(request.result, &self->queue, &request.pos, &request.tag);
  }
}
