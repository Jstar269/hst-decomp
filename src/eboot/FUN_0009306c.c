/* HSTMATCH module=EBOOT.BIN start=0x0009306c end=0x00093094 symbol=FUN_0009306c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

extern void FUN_0005ef18();

void FUN_0009306c(int param_1)
{
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_0005ef18(*(int *)(param_1 + 0x50));
  }
}
