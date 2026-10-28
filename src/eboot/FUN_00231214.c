/* HSTMATCH module=EBOOT.BIN start=0x00231214 end=0x00231240 symbol=FUN_00231214 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_00231248();

void FUN_00231214(int param_1)
{
  if (*(int *)(param_1 + 4) == 1) {
    FUN_00231248(param_1,0);
  }
}
