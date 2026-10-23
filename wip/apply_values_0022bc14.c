/* HSTMATCH module=EBOOT.BIN start=0x0022bc14 end=0x0022bd08 symbol=FUN_0022bc14 lang=c99 */
extern int FUN_0022b6a0(int, int);
extern void FUN_0022b02c(int, int, int);
extern void FUN_0022bd08(int);

int FUN_0022bc14(int param_1, int param_2, int param_3)
{
  int a;
  int b;
  int ne;
  int ne2;

  a = FUN_0022b6a0(param_1, 0x16);
  b = FUN_0022b6a0(param_1, 1);
  ne = param_2 != a;
  ne2 = param_3 != b;
  if (ne) {
    FUN_0022b02c(param_1, 0, 0);
    FUN_0022b02c(param_1, 2, 0);
    FUN_0022b02c(param_1, 0xd, 0);
    FUN_0022bd08(param_1);
    FUN_0022b02c(param_1, 0x16, param_2);
    FUN_0022b02c(param_1, 1, param_3);
  }
  else if (ne2) {
    FUN_0022bd08(param_1);
    FUN_0022b02c(param_1, 1, param_3);
  }
  return ne2;
}
// NEAR MISS: 47/61 words "differ" but the code is 1 word short and only ONE structural difference
// cascades: retail materialises the first test as `xor s0,param_2,v0 ; sltu s0,zero,s0` (computed
// right after the first FUN_0022b6a0 and the sltu in the second call's delay slot), we keep the call
// result in s0 and compare with `beq s3,s0`. Everything else (call order, the two arms, `return ne2`
// through `move v0,s1`) lines up once the shift is accounted for.
// Ruled out: computing the flag between the two calls (z2), `if (ne != 0)`, int/unsigned char/_Bool
// declarations of the two flags, an inline `int Changed(a,b){return a!=b;}` helper, swapped
// assignment order, and `(a ^ b) != 0` spelled out (that one moves the xor earlier but breaks the
// first two words).
// near miss from lane fm3 (unreviewed)
