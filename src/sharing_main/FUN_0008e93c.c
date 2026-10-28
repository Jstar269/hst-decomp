/* HSTMATCH module=hstp_trans_main.prx start=0x0008e93c end=0x0008e97c symbol=FUN_0008e93c lang=c99 */
/* Clone of src/eboot/FUN_0008d1ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);

/* Clears a Rec6c and sets its three halfword fields to -1. */
Rec6c *FUN_0008e93c(Rec6c *rec)
{
  FUN_000114c0(rec, 0, sizeof(Rec6c));
  rec->unk68 = -1;
  rec->unk6a = -1;
  rec->unk24 = -1;
  return rec;
}
