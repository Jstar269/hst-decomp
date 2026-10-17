/* HSTMATCH module=hstp_trans_main.prx start=0x00047d58 end=0x00047da4 symbol=FUN_00047d58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: the byte flag and int store typed, `if (param_2 != 0)` call arm first, the store of param_1 shared after the if/else; exact match verified; names and types await human review. */
extern unsigned char DAT_0037596c;
extern int DAT_003ba2d8;
extern void FUN_000483e8(void);

void FUN_00047d58(int param_1,int param_2)
{
  if (param_1 >= 0) {
    if (param_2 != 0) {
      FUN_000483e8();
    }
    else {
      DAT_0037596c = 0;
    }
    DAT_003ba2d8 = param_1;
  }
}
