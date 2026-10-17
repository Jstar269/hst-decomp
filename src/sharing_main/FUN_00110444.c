/* HSTMATCH module=hstp_trans_main.prx start=0x00110444 end=0x001104b0 symbol=FUN_00110444 lang=c99 */
/* Clone of src/eboot/FUN_0010a684.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: the single `if (FUN_002c7a38()==2)` is a `switch` (likely-equal `beql`), result initialised to 0 up front, calls prototyped; exact match verified; names and types await human review. */
extern char DAT_0037fc80[];
extern void FUN_00110268(char *, int);
extern int FUN_002c7a28(int);
extern int FUN_002c7a38(void);

int FUN_00110444(int param_1, int param_2)
{
  int result = 0;
  switch (FUN_002c7a38()) {
  case 2:
    result = FUN_002c7a28(param_2);
    if (result < 0) {
      FUN_00110268(DAT_0037fc80, result);
    }
    break;
  }
  return result;
}
