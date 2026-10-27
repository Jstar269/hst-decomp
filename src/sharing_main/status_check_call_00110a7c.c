/* HSTMATCH module=hstp_trans_main.prx start=0x00110a7c end=0x00110adc symbol=FUN_00110a7c lang=c99 data=0x0037ff2c */
/* Clone of src/eboot/status_check_call_0010a8a0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037ff2c-0x0037ff69) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the status test is a single-case switch and the second stub call takes the same constant 2 as an argument (Ghidra drops it because the callee is an empty stub), which is why retail loads 2 into a0 before the compare; the print stub is variadic; exact match verified; names and types await human review. */
extern int FUN_00110268(const char *, ...);
extern int FUN_002c7a48(void);
extern int FUN_002c79d8(int);
int FUN_00110a7c(void)
{
  int r = 0;
  switch (FUN_002c7a48()) {
  case 2:
    r = FUN_002c79d8(2);
    if (r < 0) FUN_00110268("ERROR: sceUtilityGamedataInstallUpdate() failed. ret = 0x%x\n", r);
    break;
  }
  return r;
}
