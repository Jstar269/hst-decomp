/* HSTMATCH module=hstp_trans_main.prx start=0x002a4454 end=0x002a446c symbol=FUN_002a4454 lang=c99 */
/* Clone of src/eboot/FUN_00292e48.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_list_obj.h"

/* Reset: both float fields to 30.0f, other fields cleared. */
void FUN_002a4454(SlotListObj *self)
{
  self->unk40 = 0;
  self->unk04 = 0x41f00000;
  self->unk08 = 0x41f00000;
  self->unk38 = 0;
}
