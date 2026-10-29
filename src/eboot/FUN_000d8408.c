/* HSTMATCH module=EBOOT.BIN start=0x000d8408 end=0x000d8460 symbol=FUN_000d8408 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000d8dcc();

/* Element destructor: tear down elem, free it when flag > 0. */
int FUN_000d8408(int elem,short flag)
{
  if (elem != 0) {
    if (elem != 0) {
      FUN_000d8dcc(elem,0);
    }
    if (0 < flag) {
      FUN_00000a00(elem);
    }
  }
  return elem;
}
