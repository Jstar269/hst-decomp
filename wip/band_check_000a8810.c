/* HSTMATCH module=EBOOT.BIN start=0x000a8810 end=0x000a8880 symbol=FUN_000a8810 lang=c99 */
/* Near miss: 5 words differ (FPR numbering only). Structure, branches, constants and delay slots match retail;
   retail holds the loaded value in $f1 and the 0.01f constant in $f2 (mtc1 v0,$f2; mul.s $f0,$f2,$f0;
   c.ngt.s $f1,$f0; c.lt.s $f1,$f0), ours has the value in $f2 and the constant in $f1. */
extern int FUN_000b3c68(int);

int FUN_000a8810(int param_1, int param_2)
{
  int iVar1;
  iVar1 = FUN_000b3c68(param_1);
  if (*(float *)(param_2 + 4) > -(*(float *)(iVar1 + 0x24) * 0.01f) && *(float *)(param_2 + 4) < 0.0f) {
    return 1;
  }
  return 0;
}

// Ruled out (all give the same 5-word FPR swap): value in a named local before/after the scale load, scale in
// a local, threshold in a named local (with or without the neg), 0.01f in a non-const local declared before
// or after the call/loads, the mirrored compare (-(s*k) < p gives c.lt.s instead of c.ngt.s), nested ifs vs &&,
// result variable, C++ with trivial inline getters for the value/scale/both, inline helper taking (v, s) in
// either parameter order, volatile load of the value, value + 0.0f. The first call really takes param_1
// (FUN_000b3c68 reads a0), so the callee should be prototyped with an int parameter.
