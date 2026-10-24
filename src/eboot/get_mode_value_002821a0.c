/* HSTMATCH module=EBOOT.BIN start=0x002821a0 end=0x00282214 symbol=FUN_002821a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag fm2 near miss) corrected by hand: the default case passes the switch value as a second (variadic) argument to the log stub FUN_002803d8, which Ghidra dropped; exact match verified; names and types await human review. */
extern char DAT_002fe988;
extern void FUN_002803d8(const char *, ...);

int FUN_002821a0(int param_1)
{
  if (*(int *)(param_1 + 0x5c) == 0) return 2;
  switch (*(int *)(param_1 + 0x80)) {
  case 3:
  case 2:
    return 2;
  case 1:
    return 3;
  case 0:
    return 4;
  default:
    FUN_002803d8(&DAT_002fe988, *(int *)(param_1 + 0x80));
    return 4;
  }
}
