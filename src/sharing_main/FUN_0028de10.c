/* HSTMATCH module=hstp_trans_main.prx start=0x0028de10 end=0x0028de54 symbol=FUN_0028de10 lang=c99 */
/* Clone of src/eboot/FUN_0027caa0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f1c;
extern u32 * FUN_00061cb0();

typedef struct InitObj {
  const void *vtable; /* 0x00 */
  char pad04[0x84 - 4];
  u32 unk84; /* 0x84 */
  char pad88[0x90 - 0x88];
  u32 unk90; /* 0x90 */
  u32 unk94; /* 0x94 */
} InitObj;

/* Constructor: base constructor, class vtable, three fields set. */
InitObj * FUN_0028de10(InitObj *self)
{
  FUN_00061cb0();
  self->vtable = &DAT_003b2f1c;
  self->unk90 = 0;
  self->unk94 = 0;
  self->unk84 = 0x40000000;
  return self;
}
