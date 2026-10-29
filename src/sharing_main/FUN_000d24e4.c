/* HSTMATCH module=hstp_trans_main.prx start=0x000d24e4 end=0x000d2508 symbol=FUN_000d24e4 lang=c99 */
/* Clone of src/eboot/FUN_000ce8e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0808;
extern u8 DAT_003b081c;

typedef struct FxBase {
  const void *vtable; /* 0x00 */
  int unk04;          /* 0x04 */
} FxBase;

/* Constructor: sets the base vtable, clears the field, then sets the derived vtable. */
FxBase * FUN_000d24e4(FxBase *self)
{
  self->vtable = &DAT_003b0808;
  self->unk04 = 0;
  self->vtable = &DAT_003b081c;
  return self;
}
