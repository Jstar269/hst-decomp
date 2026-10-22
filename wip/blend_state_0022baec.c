/* HSTMATCH module=EBOOT.BIN start=0x0022baec end=0x0022bbc8 symbol=FUN_0022baec lang=c99 */
typedef unsigned char bool;

extern int FUN_0022b6a0(int, int);
extern void FUN_0022bbc8(int);
extern void FUN_0022bd08(int);
extern void FUN_0022b02c(int, int, int);

bool FUN_0022baec(int param_1, int param_2, int param_3)
{
  int v16;
  int v0;
  bool neq2;
  bool neq3;

  v16 = FUN_0022b6a0(param_1, 0x16);
  neq2 = param_2 != v16;
  v0 = FUN_0022b6a0(param_1, 0);
  neq3 = param_3 != v0;
  if (neq2) {
    FUN_0022bbc8(param_1);
    FUN_0022bd08(param_1);
    FUN_0022b02c(param_1, 0x16, param_2);
    FUN_0022b02c(param_1, 0, param_3);
    FUN_0022b02c(param_1, 1, param_3);
  }
  else {
    if (neq3) {
      FUN_0022bbc8(param_1);
      FUN_0022b02c(param_1, 0, param_3);
    }
  }
  return neq3;
}

// NEAR MISS: 55 words retail (56 ours), 42 differ.
// Retail computes both flag booleans into saved regs right after their calls (`xor s0,s3,v0` after
// the first jal, `sltu s0,zero,s0` after the second) and branches with `beqz s0`; ours keeps v16 in
// s0 and emits the xor at the branch (`xor v0,s3,s0; sltu v0,zero,v0; bne`), so the tail shifts.
// Ruled out: if/else in both orders, plain `if (param_2 == v16)`, comparing without bool locals.
// near miss from lane fm2 (unreviewed)
