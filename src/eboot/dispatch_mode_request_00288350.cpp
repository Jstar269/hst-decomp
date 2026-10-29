/* HSTMATCH module=EBOOT.BIN start=0x00288350 end=0x00288414 symbol=FUN_00288350 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: modeled the virtual interface and aligned request context; readability pass; exact match verified; names and types await human review. */
#include "hst/mode_obj.h"

/* Frame of the queue call: out-iterator slot, list position and the queued record (tag, index, value). */
struct Request {
  QueueNode *pos;
  char result[4];
  int tag;
  int index;
  int value;
} __attribute__((aligned(16)));

enum { REQUEST_TAG_QUEUED = 0x52 };

extern "C" int *FUN_00288a84(QueueObj *);
extern "C" void FUN_00127a68(int *, int, int);
extern "C" void FUN_00289544(char *, RequestList *, QueueNode **, int *);

/* In mode 2 or 3: index < 1 acts directly on the object found by FUN_00288a84; otherwise queue a record. */
extern "C" void FUN_00288350(QueueObj *self, int value, int index)
{
  bool matched;
  int mode;
  struct Request request;
  mode = self->mode();
  matched = mode == 2;
  if (!matched) {
    mode = self->mode();
    matched = mode == 3;
  }
  if (matched) {
    if (index < 1) {
      int *target = FUN_00288a84(self);
      FUN_00127a68(target, value, 1);
    } else {
      request.tag = REQUEST_TAG_QUEUED;
      request.pos = &self->queue.sentinel;
      request.index = index;
      request.value = value;
      FUN_00289544(request.result, &self->queue, &request.pos, &request.tag);
    }
  }
}
