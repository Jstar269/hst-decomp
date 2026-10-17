/* HSTMATCH module=hstp_trans_main.prx start=0x0023cc80 end=0x0023ccd8 symbol=FUN_0023cc80 lang=c99 */
/* Clone of src/eboot/init_context_helper_0022cb7c.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: nested if checks with shared final return 0; exact match verified; names and types await human review. */
extern int DAT_003ea8e8;
extern char * DAT_003f344c;
extern int FUN_0029dc88(int, int);

int FUN_0023cc80(int param_1)
{
  if (DAT_003f344c != 0) {
    int x = *(int *)(DAT_003f344c + 0x17c);
    if (x != 0) {
      if (param_1 == 0) {
        param_1 = DAT_003ea8e8 + 0x80;
      }
      return FUN_0029dc88(x, param_1);
    }
  }
  return 0;
}
