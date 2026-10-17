/* HSTMATCH module=EBOOT.BIN start=0x0022cb7c end=0x0022cbd4 symbol=FUN_0022cb7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: nested if checks with shared final return 0; exact match verified; names and types await human review. */
extern int DAT_003415a8;
extern char * DAT_0034a114;
extern int FUN_0028c4c0(int, int);

int FUN_0022cb7c(int param_1)
{
  if (DAT_0034a114 != 0) {
    int x = *(int *)(DAT_0034a114 + 0x17c);
    if (x != 0) {
      if (param_1 == 0) {
        param_1 = DAT_003415a8 + 0x80;
      }
      return FUN_0028c4c0(x, param_1);
    }
  }
  return 0;
}
