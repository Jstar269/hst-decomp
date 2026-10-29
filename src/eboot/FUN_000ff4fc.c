/* HSTMATCH module=EBOOT.BIN start=0x000ff4fc end=0x000ff548 symbol=FUN_000ff4fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/buffer_obj.h"

extern u8 DAT_00307974;
extern void * FUN_00010184();

/* Constructor: sets the vtable, stores the argument and allocates the buffer. */
BufferObj * FUN_000ff4fc(BufferObj *self,u32 arg)
{
  void *buffer;
  
  self->vtable = &DAT_00307974;
  self->buffer = 0;
  self->unk8 = arg;
  self->unkc = 0;
  self->unk10 = 0;
  buffer = FUN_00010184(BUFFER_OBJ_BUFFER_SIZE);
  self->buffer = buffer;
  return self;
}
