/* HSTMATCH module=EBOOT.BIN start=0x0010a350 end=0x0010a360 symbol=FUN_0010a350 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
typedef struct Counter {
  char pad00[4];
  int count;            /* 0x04 */
} Counter;

/* Subtract amount from the counter at +4. */
void FUN_0010a350(Counter *self,int amount)
{
  self->count = self->count - amount;
}
