/* HSTMATCH module=EBOOT.BIN start=0x0027cc30 end=0x0027cc74 symbol=FUN_0027cc30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c18;
extern u32 * FUN_0001f06c();

typedef struct ZeroedObj {
  const void *vtable; /* 0x00 */
  char pad04[0x3c - 4];
  u32 unk3c; /* 0x3c */
  u32 unk40; /* 0x40 */
  u32 unk44; /* 0x44 */
  u32 unk48; /* 0x48 */
} ZeroedObj;

/* Constructor: base constructor, class vtable, four fields cleared. */
ZeroedObj * FUN_0027cc30(ZeroedObj *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_00309c18;
  self->unk3c = 0;
  self->unk40 = 0;
  self->unk48 = 0;
  self->unk44 = 0;
  return self;
}
