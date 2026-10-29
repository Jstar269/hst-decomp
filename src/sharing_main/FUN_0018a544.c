/* HSTMATCH module=hstp_trans_main.prx start=0x0018a544 end=0x0018a54c symbol=FUN_0018a544 lang=c99 */
/* Clone of src/eboot/FUN_0017de50.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

/* Store the float at 0x34. */
void FUN_0018a544(float value,SlotMgr *self)
{
  self->unk34 = value;
  return;
}
