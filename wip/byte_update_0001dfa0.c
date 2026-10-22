/* HSTMATCH module=EBOOT.BIN start=0x0001dfa0 end=0x0001dfe8 symbol=FUN_0001dfa0 lang=c99 */
extern void FUN_0001dd58();

void FUN_0001dfa0(unsigned char *param_1, int param_2, int param_3)
{
  if ((param_2 & 0xff) == (unsigned)*param_1) return;
  *param_1 = param_2;
  if (param_3 == 0) {
    if (param_2 == 0) {
      FUN_0001dd58();
    } else {
      *(unsigned *)(param_1 + 0x84) = 0xffff;
    }
  }
}

// NEAR MISS (18/18 words, 1 differ at +0x1c; op1 lane 2026-10-21, converted from the Sharing twin wip/byte_update_0001dbec.c).
// Retail stores the raw parameter (`sb a1,0(a0)`), we store the masked copy `a3` that the compare already computed
// (`sb a3,0(a0)`); both are equivalent because sb truncates.
// Ruled out: `(unsigned char)param_2` cast, `*param_1 == (param_2 & 0xff)` operand order (3 words worse), a named
// `unsigned char c = param_2;` local, an explicit cast on the store, an if/else arm split (20 words).
// near miss from lane op1 (unreviewed)
