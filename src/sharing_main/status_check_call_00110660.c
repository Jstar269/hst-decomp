/* HSTMATCH module=hstp_trans_main.prx start=0x00110660 end=0x001106c0 symbol=FUN_00110660 lang=c99 */
/* Clone of src/eboot/status_check_call_0010a8a0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the status test is a single-case switch and the second stub call takes the same constant 2 as an argument (Ghidra drops it because the callee is an empty stub), which is why retail loads 2 into a0 before the compare; the print stub is variadic; exact match verified; names and types await human review. */
extern char DAT_0037fd68[];
extern int FUN_00110268(const char *, ...);
extern int FUN_002c79f8(void);
extern int FUN_002c7a18(int);
int FUN_00110660(void)
{
  int r = 0;
  switch (FUN_002c79f8()) {
  case 2:
    r = FUN_002c7a18(2);
    if (r < 0) FUN_00110268(DAT_0037fd68, r);
    break;
  }
  return r;
}
