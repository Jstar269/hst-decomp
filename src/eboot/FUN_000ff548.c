/* HSTMATCH module=EBOOT.BIN start=0x000ff548 end=0x000ff5b0 symbol=FUN_000ff548 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the tested member passed to the free call (Ghidra dropped the argument); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/buffer_obj.h"

extern u8 DAT_00307974;
extern void FUN_00000a00();
extern void FUN_000104e0();

/* Deleting destructor: frees the buffer; frees the object when delete_flag > 0. */
BufferObj * FUN_000ff548(BufferObj *self,short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_00307974;
    if (self->buffer != 0) {
      FUN_000104e0(self->buffer);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
