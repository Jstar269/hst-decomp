/* HSTMATCH module=EBOOT.BIN start=0x000bc024 end=0x000bc098 symbol=FUN_000bc024 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073d8;
extern void FUN_00000a00();
extern void FUN_000104e0();

/* Object that owns one buffer at 0xc. */
typedef struct BufferOwner {
  const void *vtable; /* 0x0 */
  char pad04[8];
  void *buffer;       /* 0xc */
} BufferOwner;

/* Destructor: restores the vtable, frees the buffer, frees the object if delete_flag > 0. */
BufferOwner * FUN_000bc024(BufferOwner *self,short delete_flag)
{
  if (self != (BufferOwner *)0x0) {
    self->vtable = &DAT_003073d8;
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
