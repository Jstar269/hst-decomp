/* HSTMATCH module=EBOOT.BIN start=0x0009619c end=0x00096214 symbol=FUN_0009619c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag chain as int ok = (G != 0); if (ok) ok = (b != 0) ^ 1 (lbu/sltu/xori), callee result as int* indexed p[i+1] (offset-first addu); exact match verified; names and types await human review. */
extern unsigned char DAT_003386b8;
extern int DAT_00338af0;
extern int FUN_000c4ba0(int, int);

void FUN_0009619c(char *param_1, int param_2, int param_3)
{
  int ok;

  ok = DAT_003386b8 != 0;
  if (ok) {
    ok = (*(unsigned char *)(param_1 + 0x1b4) != 0) ^ 1;
  }
  if (ok && DAT_00338af0 != 0) {
    int *p = (int *)FUN_000c4ba0(DAT_00338af0, *(int *)(param_1 + 0x148));
    p[param_2 + 1] = param_3;
  }
}
