/* HSTMATCH module=EBOOT.BIN start=0x000def58 end=0x000defb4 symbol=FUN_000def58 lang=c99 */
extern unsigned char DAT_00338b48;
int FUN_000def58(int self) {
  if (DAT_00338b48 != 0) return *(int *)(self + 0xc8) > 0;
  int half = (*(int *)(self + 0xb4) + 1) / 2;
  if (*(int *)(self + 0xb8) < half) {
    if (*(int *)(self + 0xbc) >= half) return 1;
    return 0;
  }
  return 1;
}
// Near miss: 7 words differ. The midpoint divide and first range compare match; the second compare becomes slt plus xori and returns early, while retail branches likely on the comparison and shares the final return, with two more tail words.
// Ruled out: an int result assigned in the surrounding arm changed the midpoint register from v1 to a1; separate C/if arms also produced a nonlikely branch.
// near miss from lane u1r1-1 (unreviewed)
