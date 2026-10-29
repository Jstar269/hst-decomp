/* HSTMATCH module=hstp_trans_main.prx start=0x00130f6c end=0x00130fa8 symbol=FUN_00130f6c lang=c99 */
/* Clone of src/eboot/FUN_00125d38.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object built on the base class; only the vtable pointer and two cleared words are touched. */
typedef struct BaseDerived {
  const void *vtable; /* 0x00 */
  char pad04[0x8c];
  u32 unk90;          /* 0x90 */
  u32 unk94;          /* 0x94 */
} BaseDerived;

extern u8 DAT_003b12e4;
extern u32 * FUN_00061cb0();

/* Constructor: runs the base constructor, sets the vtable and clears the two trailing words. */
BaseDerived * FUN_00130f6c(BaseDerived *self)
{
  FUN_00061cb0();
  self->vtable = &DAT_003b12e4;
  self->unk90 = 0;
  self->unk94 = 0;
  return self;
}
