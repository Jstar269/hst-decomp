/* HSTMATCH module=hstp_trans_main.prx start=0x0008e97c end=0x0008e9b4 symbol=FUN_0008e97c lang=c99 */
/* Clone of src/eboot/FUN_0008d22c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);

/* Clears a Pair3 and zeroes its first two bytes. */
Pair3 *FUN_0008e97c(Pair3 *pair)
{
  FUN_000114c0(pair, 0, sizeof(Pair3));
  pair->unk0 = 0;
  pair->unk1 = 0;
  return pair;
}
