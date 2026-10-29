/* HSTMATCH module=hstp_trans_main.prx start=0x000bf498 end=0x000bf50c symbol=FUN_000bf498 lang=c99 */
/* Clone of src/eboot/FUN_000bc024.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06a4;
extern void FUN_00000a00();
extern void FUN_000104e0();

/* Object that owns one buffer at 0xc. */
typedef struct BufferOwner {
  const void *vtable; /* 0x0 */
  char pad04[8];
  void *buffer;       /* 0xc */
} BufferOwner;

/* Destructor: restores the vtable, frees the buffer, frees the object if delete_flag > 0. */
BufferOwner * FUN_000bf498(BufferOwner *self,short delete_flag)
{
  if (self != (BufferOwner *)0x0) {
    self->vtable = &DAT_003b06a4;
    if ((self->buffer != 0) && (self->buffer != 0)) {
      FUN_000104e0(self->buffer);
      self->buffer = 0;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
