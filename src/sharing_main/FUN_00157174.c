/* HSTMATCH module=hstp_trans_main.prx start=0x00157174 end=0x00157184 symbol=FUN_00157174 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_00157174(CountedObj *self, int amount)
{
  self->count -= amount;
}
