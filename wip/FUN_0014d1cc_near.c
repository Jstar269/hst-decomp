/* HSTMATCH module=EBOOT.BIN start=0x0014d1cc end=0x0014d25c symbol=FUN_0014d1cc lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc250[];
extern char DAT_002dc254[];
extern void FUN_0014c610(const char *);

int FUN_0014d1cc(int param_1, int *param_2)
{
  int i;
  int n;
  if (DAT_003402f0 != 0) {
    FUN_0014c610(DAT_002dc240);
    n = param_2[6] + 1;
    if (n > 0) {
      for (i = 0; i < param_2[6] + 1; i++) {
        FUN_0014c610(DAT_002dc24c);
      }
    }
    FUN_0014c610(DAT_002dc250);
  }
  FUN_0014c610((const char *)*(int *)(param_1 + 8));
  FUN_0014c610(DAT_002dc254);
  return 0;
}
// near miss: debug-dump print routine. Retail keeps the second parameter in a1 across every jal 0x14c610
// (a variadic prologue stub that saves a0..t3 and returns) and has no saved registers; every C spelling
// (extern, static declaration, static definition after, locals for the count) makes MWCC spill param_2 to
// s0/s1 plus s2 for param_1, and the loop guard comes out duplicated. Unresolved register-lifetime issue.
// near miss from lane ds4 (unreviewed)
