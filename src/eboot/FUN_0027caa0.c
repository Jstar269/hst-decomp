/* HSTMATCH module=EBOOT.BIN start=0x0027caa0 end=0x0027cae4 symbol=FUN_0027caa0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c34;
extern u32 * FUN_00060e2c();

typedef struct InitObj {
  const void *vtable; /* 0x00 */
  char pad04[0x84 - 4];
  u32 unk84; /* 0x84 */
  char pad88[0x90 - 0x88];
  u32 unk90; /* 0x90 */
  u32 unk94; /* 0x94 */
} InitObj;

/* Constructor: base constructor, class vtable, three fields set. */
InitObj * FUN_0027caa0(InitObj *self)
{
  FUN_00060e2c();
  self->vtable = &DAT_00309c34;
  self->unk90 = 0;
  self->unk94 = 0;
  self->unk84 = 0x40000000;
  return self;
}
