/* HSTMATCH module=EBOOT.BIN start=0x001fac6c end=0x001fac7c symbol=FUN_001fac6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct CounterObj {
  char pad00[0x135c];
  int counter;       /* 0x135c */
} CounterObj;

/* Increments the counter. */
void FUN_001fac6c(CounterObj *self)
{
  self->counter = self->counter + 1;
}
