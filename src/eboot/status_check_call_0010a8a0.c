/* HSTMATCH module=EBOOT.BIN start=0x0010a8a0 end=0x0010a900 symbol=FUN_0010a8a0 lang=c99 data=0x002d8f94 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the status test is a single-case switch and the second stub call takes the same constant 2 as an argument (Ghidra drops it because the callee is an empty stub), which is why retail loads 2 into a0 before the compare; the print stub is variadic; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8f94-0x002d8fc9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int FUN_0010a4a8(const char *, ...);
extern int FUN_002b7c58(void);
extern int FUN_002b7c78(int);
int FUN_0010a8a0(void)
{
  int r = 0;
  switch (FUN_002b7c58()) {
  case 2:
    r = FUN_002b7c78(2);
    if (r < 0) FUN_0010a4a8("ERROR: sceUtilityNetconfUpdate() failed. ret = 0x%x\n", r);
    break;
  }
  return r;
}
