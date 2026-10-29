/* HSTMATCH module=EBOOT.BIN start=0x000bc6c0 end=0x000bc72c symbol=FUN_000bc6c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the tested member passed to the free call (Ghidra dropped the argument); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073cc;
extern void FUN_00000a00();
extern void FUN_000104e0();

/* Object that owns one buffer at 0x18. */
typedef struct BufferOwner {
  const void *vtable; /* 0x0 */
  char pad04[0x14];
  void *buffer;       /* 0x18 */
} BufferOwner;

/* Destructor: restores the vtable, frees the buffer, frees the object if delete_flag > 0. */
BufferOwner * FUN_000bc6c0(BufferOwner *self,short delete_flag)
{
  if (self != (BufferOwner *)0x0) {
    self->vtable = &DAT_003073cc;
    if (self->buffer != 0) {
      FUN_000104e0(self->buffer);
      self->buffer = 0;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
