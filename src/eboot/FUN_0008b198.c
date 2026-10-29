/* HSTMATCH module=EBOOT.BIN start=0x0008b198 end=0x0008b1a8 symbol=FUN_0008b198 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Object whose second word is a running count. */
typedef struct CountedObj {
  char pad0[4];
  int count; /* 0x4 */
} CountedObj;

void FUN_0008b198(CountedObj *self, int amount)
{
  self->count -= amount;
}
