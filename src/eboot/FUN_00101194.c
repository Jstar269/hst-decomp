/* HSTMATCH module=EBOOT.BIN start=0x00101194 end=0x00101220 symbol=FUN_00101194 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the member argument Ghidra dropped from the call restored; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307b58;
extern u8 DAT_00307bac;
extern void FUN_00000a00();
extern void FUN_000104e0();
extern u32 * FUN_000510c0();

/* Derived object: base part up to +0x50, then an owned buffer. */
typedef struct BufferOwner {
  const void *vtable; /* 0x00 */
  char pad04[0x4c];
  void *buffer;       /* 0x50 freed by the destructor */
} BufferOwner;

/* Deleting destructor: free the buffer, run the base destructor, free self when flags > 0. */
BufferOwner * FUN_00101194(BufferOwner *self,short flags)
{
  if (self != (BufferOwner *)0x0) {
    self->vtable = &DAT_00307bac;
    if (self->buffer != 0) {
      FUN_000104e0(self->buffer);
      self->buffer = 0;
    }
    if (self != (BufferOwner *)0x0) {
      self->vtable = &DAT_00307b58;
      FUN_000510c0(self,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
