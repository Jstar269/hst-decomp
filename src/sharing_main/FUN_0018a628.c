/* HSTMATCH module=hstp_trans_main.prx start=0x0018a628 end=0x0018a638 symbol=FUN_0018a628 lang=c99 */
/* Clone of src/eboot/FUN_0017df34.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

/* Set the flag at 0x41 and clear the word at 0x44. */
void FUN_0018a628(SlotMgr *self)
{
  self->unk41 = 1;
  self->unk44 = 0;
}
