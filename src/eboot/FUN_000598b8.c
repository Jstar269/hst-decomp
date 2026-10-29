/* HSTMATCH module=EBOOT.BIN start=0x000598b8 end=0x000598c8 symbol=FUN_000598b8 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_000598b8(CountedObj *self, int amount)
{
  self->count -= amount;
}
