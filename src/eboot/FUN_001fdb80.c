/* HSTMATCH module=EBOOT.BIN start=0x001fdb80 end=0x001fdbb4 symbol=FUN_001fdb80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern void FUN_0001f1fc();
extern void FUN_00201cf4();

/* Releases the sub-object at 0x1250, then forwards to the base cleanup. */
void FUN_001fdb80(int self)
{
  FUN_00201cf4(self + 0x1250);
  FUN_0001f1fc(self,0);
}
