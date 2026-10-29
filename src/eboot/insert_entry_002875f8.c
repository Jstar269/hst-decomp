/* HSTMATCH module=EBOOT.BIN start=0x002875f8 end=0x002876a0 symbol=FUN_002875f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: 24-byte record struct, !(0 < param_3) condition, and exact local declaration order; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/request_queue.h"

extern int DAT_0034a2e0;
extern void FUN_00225b00(int, int, int, int, int);
extern int FUN_00288f2c(RequestOwner *, int *);
extern int FUN_00289544(void *, void *, void *, void *);

enum { REQ_TYPE_3D = 61 }; /* request kind, named by its hex value */

/* With a count of 0 or less run the request now through the owner's lookup; otherwise queue it. */
void FUN_002875f8(RequestOwner *self, int key, u32 flag, int count)
{
  int found;
  RequestRec rec;
  int out;
  DListLinks *sentinel;

  if (count <= 0) {
    found = 0;
    int slot = FUN_00288f2c(self, &found);
    if (slot < 0) {
      return;
    }
    if (found == 0) {
      return;
    }
    FUN_00225b00(DAT_0034a2e0, key, found, slot, !(0 < flag));
    return;
  }

  rec.argc = flag & 0xff;
  rec.type = REQ_TYPE_3D;
  rec.count = count;
  sentinel = &self->queue.sentinel;
  rec.arg8 = key;
  FUN_00289544(&out, &self->queue, &sentinel, &rec);
}
