/* HSTMATCH module=hstp_trans_main.prx start=0x00058090 end=0x00058118 symbol=FUN_00058090 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0c) corrected by hand: branch polarity inverted (param_3 != 0 first), inline new/ctor allocation; exact match verified; names and types await human review. */
extern void *FUN_00000bcc(int);
extern void *FUN_00056dac(void *, int);
extern void FUN_00058118(int, int, void *, int);

void FUN_00058090(int param_1, int param_2, int param_3, int param_4)
{
  if (param_3 != 0) {
    void *p = FUN_00000bcc(16);
    if (p != 0) {
      p = FUN_00056dac(p, param_3);
    }
    FUN_00058118(param_1, param_2, p, param_4);
  } else {
    FUN_00058118(param_1, param_2, 0, param_4);
  }
}
