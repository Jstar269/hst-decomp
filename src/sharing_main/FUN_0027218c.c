/* HSTMATCH module=hstp_trans_main.prx start=0x0027218c end=0x002721c8 symbol=FUN_0027218c lang=c99 */
/* Clone of src/eboot/FUN_00261364.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void * FUN_000114c0();

/* Clears the record, then marks its three halfword ids as unset. */
void FUN_0027218c(Rec6c *rec)
{
  FUN_000114c0(rec,0,sizeof(Rec6c));
  rec->unk68 = 0xffff;
  rec->unk6a = 0xffff;
  rec->unk24 = 0xffff;
  return;
}
