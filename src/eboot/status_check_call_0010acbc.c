/* HSTMATCH module=EBOOT.BIN start=0x0010acbc end=0x0010ad1c symbol=FUN_0010acbc lang=c99 data=0x002d9158 */
/* Clone of src/sharing_main/status_check_call_00110660.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d9158-0x002d9195) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the status test is a single-case switch and the second stub call takes the same constant 2 as an argument (Ghidra drops it because the callee is an empty stub), which is why retail loads 2 into a0 before the compare; the print stub is variadic; exact match verified; names and types await human review. */
extern int FUN_0010a4a8(const char *, ...);
extern int FUN_002b7ca8(void);
extern int FUN_002b7c38(int);
int FUN_0010acbc(void)
{
  int r = 0;
  switch (FUN_002b7ca8()) {
  case 2:
    r = FUN_002b7c38(2);
    if (r < 0) FUN_0010a4a8("ERROR: sceUtilityGamedataInstallUpdate() failed. ret = 0x%x\n", r);
    break;
  }
  return r;
}
