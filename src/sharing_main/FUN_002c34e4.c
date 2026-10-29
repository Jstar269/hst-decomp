/* HSTMATCH module=hstp_trans_main.prx start=0x002c34e4 end=0x002c34f4 symbol=FUN_002c34e4 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_002c34e4(CountedObj *self, int amount)
{
  self->count -= amount;
}
