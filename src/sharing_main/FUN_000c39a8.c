/* HSTMATCH module=hstp_trans_main.prx start=0x000c39a8 end=0x000c3a2c symbol=FUN_000c39a8 lang=c99 */
/* Clone of src/eboot/FUN_000c0308.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ptp_link.h"

extern u8 DAT_003b06c8;
extern void FUN_00000a00();
extern void FUN_002c7680();
extern void FUN_002c76a0();

/* Destructor: asks the worker thread to stop, then terminates and deletes it. */
PtpLink * FUN_000c39a8(PtpLink *self,short delete_flag)
{
  int thread;
  
  if (self != (PtpLink *)0x0) {
    self->vtable = &DAT_003b06c8;
    if (self->stop_flag != (char *)0x0) {
      *self->stop_flag = 1;
    }
    thread = self->thread_id;
    if (0 < thread) {
      FUN_002c7680(thread,0);
      FUN_002c76a0(self->thread_id);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
