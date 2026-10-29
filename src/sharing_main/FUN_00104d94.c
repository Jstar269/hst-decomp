/* HSTMATCH module=hstp_trans_main.prx start=0x00104d94 end=0x00104de0 symbol=FUN_00104d94 lang=c99 */
/* Clone of src/eboot/FUN_000ff4fc.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/buffer_obj.h"

extern u8 DAT_003b0c40;
extern void * FUN_00010184();

/* Constructor: sets the vtable, stores the argument and allocates the buffer. */
BufferObj * FUN_00104d94(BufferObj *self,u32 arg)
{
  void *buffer;
  
  self->vtable = &DAT_003b0c40;
  self->buffer = 0;
  self->unk8 = arg;
  self->unkc = 0;
  self->unk10 = 0;
  buffer = FUN_00010184(BUFFER_OBJ_BUFFER_SIZE);
  self->buffer = buffer;
  return self;
}
