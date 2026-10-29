/* HSTMATCH module=hstp_trans_main.prx start=0x002a446c end=0x002a44b8 symbol=FUN_002a446c lang=c99 */
/* Clone of src/eboot/FUN_00292e60.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_list_obj.h"

extern u8 DAT_003b30b4;
extern u32 * FUN_002a308c();

SlotListObj * FUN_002a446c(SlotListObj *self)
{
  FUN_002a308c();
  self->vtable = (unsigned int)(&DAT_003b30b4);
  self->unk4c = 0;
  self->unk4d = 0;
  self->unk50 = 0;
  self->unk54 = 0;
  self->unk4e = 1;
  return self;
}
