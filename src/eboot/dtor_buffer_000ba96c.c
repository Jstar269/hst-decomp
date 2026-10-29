/* HSTMATCH module=EBOOT.BIN start=0x000ba96c end=0x000ba9e0 symbol=FUN_000ba96c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the free call takes the tested member (FUN_000009e4(param_1[2])); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073e4;
extern void FUN_000009e4(u32);
extern void FUN_00000a00();

/* Buffer holder: owns one data block, plus fields cleared on teardown. */
typedef struct BufferHolder {
  const void *vtable;    /* 0x00 */
  u32 unk4;              /* 0x04 */
  u32 data;              /* 0x08 pointer to the owned block, freed on teardown */
  u32 unkc;              /* 0x0c */
  u8 unk10;              /* 0x10 */
} BufferHolder;

/* Deleting destructor: frees the owned block, clears the fields, frees the object when the flag is positive. */
BufferHolder * FUN_000ba96c(BufferHolder *self,short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_003073e4;
    if (self->data != 0) {
      FUN_000009e4(self->data);
      self->data = 0;
    }
    self->unk4 = 0;
    self->unkc = 0;
    self->unk10 = 0;
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
