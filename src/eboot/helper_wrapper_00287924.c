/* HSTMATCH module=EBOOT.BIN start=0x00287924 end=0x0028797c symbol=FUN_00287924 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/request_queue.h"

extern void FUN_001b29a8();
extern u32 DAT_0034179c;
extern u32 FUN_00289544(int *, void *, void *, void *);

enum { REQ_TYPE_33 = 0x33 }; /* request kind, named by its hex value */

/* Local frame of the queued call: the list position, the insert result and the request record. */
struct QueueCall {
  DListLinks *sentinel;
  int result;
  RequestRec rec;
};

/* With a count below 1 run the action at once on the global; otherwise queue a request carrying value and count. */
void FUN_00287924(RequestOwner *self,u32 value,int count)
{
  struct QueueCall call;

  if (count < 1) {
    FUN_001b29a8(&DAT_0034179c);
  }
  else {
    call.rec.type = REQ_TYPE_33;
    call.rec.arg8 = value;
    call.rec.count = count;
    call.sentinel = &self->queue.sentinel;
    FUN_00289544(&call.result,&self->queue,&call.sentinel,&call.rec);
  }
}
