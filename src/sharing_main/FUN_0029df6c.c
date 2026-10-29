/* HSTMATCH module=hstp_trans_main.prx start=0x0029df6c end=0x0029df7c symbol=FUN_0029df6c lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_0029df6c(CountedObj *self, int amount)
{
  self->count -= amount;
}
