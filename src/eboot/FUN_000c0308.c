/* HSTMATCH module=EBOOT.BIN start=0x000c0308 end=0x000c038c symbol=FUN_000c0308 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ptp_link.h"

extern u8 DAT_003073fc;
extern void FUN_00000a00();
extern void FUN_002b78e0();
extern void FUN_002b7900();

/* Destructor: asks the worker thread to stop, then terminates and deletes it. */
PtpLink * FUN_000c0308(PtpLink *self,short delete_flag)
{
  int thread;
  
  if (self != (PtpLink *)0x0) {
    self->vtable = &DAT_003073fc;
    if (self->stop_flag != (char *)0x0) {
      *self->stop_flag = 1;
    }
    thread = self->thread_id;
    if (0 < thread) {
      FUN_002b78e0(thread,0);
      FUN_002b7900(self->thread_id);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
