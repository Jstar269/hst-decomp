/* HSTMATCH module=EBOOT.BIN start=0x001181c0 end=0x00118250 symbol=FUN_001181c0 lang=c99 */
#define true 1

int FUN_001181c0(int param_1)
{
  int i;
  int n;
  int p;
  int r;

  i = *(int *)(param_1 + 0x5c);
  r = -1;
  if (i >= 0) {
    while (true) {
      p = param_1 + i * 0x70;
      if (((*(unsigned char *)(p + 0xe0) != 0) ^ 1) != 0) {
        goto advance;
      }
      if (*(unsigned char *)(p + 0xe1) != 0) {
        goto advance;
      }
      else {
        goto done;
      }
    advance:
      n = *(int *)(param_1 + 0x60);
      if (i == n) break;
      i = (i + 8) % 9;
    }
  }
  i = -1;
done:
  if (i >= 0) {
    int off = i * 0x70;
    r = *(int *)(off + (int)param_1 + 0xb8);
  }
  return r;
}
// near miss (2 words short; 23 words differ by layout cascade): retail orients the
// second slot-flag test as `bnez e1 -> ADVANCE; nop; b done; nop` (branch carries the
// NEAR advance block, the else-goto-done falls through), while every spelling tried
// (nested if, else-if chain, flat gotos, named busy/free_slot flags, && form with
// `free_slot = (e0 != 0) ^ 1`) makes MWCC emit `beqz e1 -> done` with the advance
// block as fall-through (branch carries the FAR target). Everything else matches
// retail: unsigned char flags (lbu), the single sltu/xori `(x != 0) ^ 1` normalization,
// bnezl likely-branch with the count reload hoisted into its slot, bltz entry, the
// div/mfhi (i + 8) % 9 loop-back into the subu, and the offset-first final addu
// `off + (int)param_1` with lw 184(v0). Ruled out: polarity flips of the if, moving
// n = count into the arms, break/flag loop conditions.
// near miss from lane fb1 (unreviewed)
