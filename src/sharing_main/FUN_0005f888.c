/* HSTMATCH module=hstp_trans_main.prx start=0x0005f888 end=0x0005f898 symbol=FUN_0005f888 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_0005f888(CountedObj *self, int amount)
{
  self->count -= amount;
}
