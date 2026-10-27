/* HSTMATCH module=EBOOT.BIN start=0x0010a684 end=0x0010a6f0 symbol=FUN_0010a684 lang=c99 data=0x002d8eac */
/* Hand-written reconstruction from Ghidra pseudocode: the single `if (FUN_002b7c98()==2)` is a `switch` (likely-equal `beql`), result initialised to 0 up front, calls prototyped; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8eac-0x002d8ee3) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_0010a4a8(char *, int);
extern int FUN_002b7c88(int);
extern int FUN_002b7c98(void);

int FUN_0010a684(int param_1, int param_2)
{
  int result = 0;
  switch (FUN_002b7c98()) {
  case 2:
    result = FUN_002b7c88(param_2);
    if (result < 0) {
      FUN_0010a4a8("ERROR: sceUtilityMsgDialogUpdate() failed. ret = 0x%x\n", result);
    }
    break;
  }
  return result;
}
