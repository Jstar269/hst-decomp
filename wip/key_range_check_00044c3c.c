/* HSTMATCH module=EBOOT.BIN start=0x00044c3c end=0x00044c88 symbol=FUN_00044c3c lang=c99 */
int FUN_00044c3c(unsigned int unused, unsigned int value)
{
  unsigned int v = value & 0xffff;
  if ((v & 0xff00) != 0xff00) {
    int r = (v & 0xff) != 0 ? 0 : 1;
    return r;
  }
  int low = (int)(v & 0xff);
  unsigned char r2 = 0;
  if (low >= 96 && low < 160) {
    r2 = 1;
  }
  return r2;
}
// NEAR MISS: 17/19 words, 13 differ. The first six instructions match (the mask, the
// 0xff00 compare and the branch polarity). Retail computes the low byte ONCE in the
// branch delay slot (`andi v1,a0,0xff`) and uses it in both arms; ours recomputes it
// in the low-byte arm, and the two range tests (96 / 160) come out as a materialised
// boolean (`sltiu`/`xori`) instead of retail's branch pair
// (`slti v0,v1,96; bnez v0,SKIP` + `slti at,v1,160; beqzl at,END`).
// Ruled out: the 0xff00 arm as the `==` test (gives `bnel`, retail has `beql`), the
// low byte as a variable declared before the test (register allocation flips: ours
// puts the mask in v0 and the low byte in a0), `low >= 96 && low < 160` and
// `low > 95 && low < 160` (both materialise the boolean), nested `if (low >= 96) { if
// (low < 160) ... }`, and the "r = 1 first, then r = 0" spelling (gives `beqz`, retail
// has `beqzl`).
// near miss from lane om1 (unreviewed)
