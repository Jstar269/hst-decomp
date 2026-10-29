/* HSTMATCH module=hstp_trans_main.prx start=0x0015b6fc end=0x0015b70c symbol=FUN_0015b6fc lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_0015b6fc(CountedObj *self, int amount)
{
  self->count -= amount;
}
