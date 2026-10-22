/* HSTMATCH module=EBOOT.BIN start=0x002889cc end=0x00288a84 symbol=FUN_002889cc lang=c99 */
extern void *DAT_0034a114;
extern int DAT_002feae4[];
extern int DAT_002feb08[];
extern int FUN_001c70c0(void *, int);
extern void FUN_00286acc(int *, int, int);
extern int FUN_00000bcc(int);
extern int FUN_0029343c(int);
extern void FUN_00293564(int, int);
extern void FUN_001c6b38(void *, int, int);

void FUN_002889cc(int param_1, int param_2)
{
  int obj;
  int r;

  if (FUN_001c70c0(DAT_0034a114, param_1) != 0) {
    FUN_00286acc(DAT_002feae4, param_1, param_2);
  }
  else {
    FUN_00286acc(DAT_002feb08, param_1, param_2);
    obj = FUN_00000bcc(0x90);
    r = obj ? FUN_0029343c(obj) : 0;
    FUN_00293564(r, param_2);
    FUN_001c6b38(DAT_0034a114, param_1, r);
  }
}

// NEAR MISS: 46 words retail (45 ours), 21 differ.
// Retail copies the operator-new result into s0 right away (`move s0,v0`), then `beqzl s0,SKIP`
// with `move a1,s1` in the delay and calls the ctor with `a0 = s0`, reusing s0 for the result; ours
// keeps obj in v0 (`beqzl v0` / `bnezl v0`) so the whole tail shifts. Ruled out: ternary vs if/else,
// the array-typed global (unfixed `lui/addiu` address instead of the loaded pointer).
// near miss from lane fm2 (unreviewed)
