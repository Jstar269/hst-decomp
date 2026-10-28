/* HSTMATCH module=EBOOT.BIN start=0x002a6b30 end=0x002a6b68 symbol=FUN_002a6b30 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_001031e8();
extern void FUN_002a6668();

void FUN_002a6b30(int param_1)
{
  if (*(int *)(param_1 + 0x880) == 0) {
    FUN_002a6668();
  }
  FUN_001031e8(param_1);
}
