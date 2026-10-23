/* HSTMATCH module=EBOOT.BIN start=0x00089c8c end=0x00089e9c symbol=FUN_00089c8c lang=c99 */
/* NEAR MISS 131/132 words, 87 differ. Structure found and confirmed: switch on state (param+0x44) with the
   cases listed ASCENDING 0..3 (retail's compare chain is the reverse, 3,2,1,0), every arm ending in `break`
   with one shared return after the switch - `return` inside each arm costs 3 words and breaks the `beql`
   dispatch. Case 1 must be written as a `!= 0` guard with the state increment SHARED after the if, otherwise
   MWCC emits two increment blocks. The clamp flag needs the pointer global (`DAT_002cfc8c[0x8b]`), case 0's
   guard needs `if (DAT_003386b8 != 0)` (the shared-`mode` variant adds an `addiu a1,s2,68` and a dead store).
   Needs s_result_frame__d__s__002d23cc = 0x002d23cc in symbols/EBOOT.BIN.txt. Remaining: one word short, and
   case 2's `(*(int *)(param_1 + 0x98) == 0 || FUN_00118f84() != 0)` comes out `beqzl`+`addiu v0,s2,72` where
   retail has `beqz`+nop (the store address leaks into the delay slot), plus a0-vs-v1 allocation on the
   count+1/slt/compare triple. Writing the df000/byte tail as `if (f() != 0 || byte != 0) { state++ } else { f40 = 6 }`
   with an `unsigned char` read moves retail's state++ arm inline (130 words, same 87 diffs). */
extern int DAT_002d23c4;
extern int DAT_002d23c8;
extern char *DAT_002cfc8c;
extern unsigned char DAT_003386b8;
extern char *DAT_003402a0;
extern char *DAT_00338b44;
extern char DAT_002d23e4;
extern char DAT_002d23ec;
extern char s_result_frame__d__s__002d23cc[];

extern void FUN_0008822c(char *, int, void *);
extern int FUN_0008a72c(int, int);
extern void FUN_0008ab10(void);
extern void FUN_0008ad40(int);
extern int FUN_0008add8(int);
extern int FUN_000def58(char *);
extern int FUN_000df000(char *);
extern int FUN_00118f84(void);
extern int FUN_0013b868(char *, int *);

void FUN_00089c8c(int param_1)
{
  int limit;
  int clamp;
  int count;
  int r;
  void *msg;

  limit = DAT_002d23c4;
  clamp = ((int)*(signed char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
  FUN_0008ab10();
  switch (*(int *)(param_1 + 0x44)) {
  case 0:
    *(int *)(param_1 + 0x48) = 0;
    if (DAT_003386b8 != 0) {
      *(int *)(param_1 + 0x6c) = 0x1c2;
      *(char *)(param_1 + 0x68) = 0;
    }
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    break;
  case 1:
    if (FUN_000def58(DAT_00338b44) != 0) {
      FUN_0008ad40(param_1);
      if (FUN_0008add8(param_1) == 0)
        break;
    }
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    break;
  case 2: {
    int lim;
    lim = DAT_002d23c8;
    if (DAT_003402a0 != 0) {
      r = FUN_0013b868(DAT_003402a0, &lim);
      if (r != 0 && !clamp)
        limit = lim;
    }
    count = *(int *)(param_1 + 0x48);
    *(int *)(param_1 + 0x48) = count + 1;
    if (limit <= count + 1 &&
        (*(int *)(param_1 + 0x98) == 0 || FUN_00118f84() != 0)) {
      if (clamp)
        msg = &DAT_002d23e4;
      else
        msg = &DAT_002d23ec;
      FUN_0008822c(s_result_frame__d__s__002d23cc, *(int *)(param_1 + 0x48), msg);
      if (FUN_000df000(DAT_00338b44) == 0 && *(char *)(DAT_00338b44 + 0x5d) == 0) {
        if (FUN_0008a72c(param_1, 1) == 0)
          *(int *)(param_1 + 0x40) = 6;
      } else {
        if (FUN_0008a72c(param_1, 1) == 0)
          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
      }
    }
    break;
  }
  case 3:
    FUN_0008ad40(param_1);
    if (FUN_0008add8(param_1) == 0)
      break;
    *(int *)(param_1 + 0x40) = 4;
    break;
  }
  return;
}
// near miss from lane fm7 (unreviewed)
