/* HSTMATCH module=hstp_trans_main.prx start=0x001483c4 end=0x001483d4 symbol=FUN_001483c4 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_001483c4(CountedObj *self, int amount)
{
  self->count -= amount;
}
