/* HSTMATCH module=EBOOT.BIN start=0x001b0610 end=0x001b06d4 symbol=FUN_001b0610 lang=c99 */
extern void FUN_00062418(int, int);

void FUN_001b0610(int *param_1, int param_2)
{
  int *slot;
  int *p;
  int n;
  int i;

  slot = param_1 + 0x1de;
  if (slot[param_2] == 0) {
    return;
  }
  n = 0;
  for (p = slot; p != slot + 4; p++) {
    if (*p == slot[param_2]) {
      n++;
    }
  }
  if (n < 2) {
    for (i = 0; i < 0x1da; i++) {
      if (param_1[i] == slot[param_2]) {
        if (param_1[i] != 0) {
          FUN_00062418(param_1[i],1);
          param_1[i] = 0;
        }
        break;
      }
    }
    slot[param_2] = 0;
  }
}
// NEAR 4 (45/49 words, 0x001b0610). Two semantic corrections found by reading retail's branches:
// (a) the `slot[param_2] = 0` store is INSIDE the `if (n < 2)` arm - retail skips it entirely when
// the value appears in two or more of the four slots (`beqzl at,EPILOGUE` when n >= 2); (b) the null
// test is an early `return` (`if (slot[param_2] == 0) return;`), which is what produces retail's
// `beqzl v1,EPILOGUE` with the `lw ra,12(sp)` epilogue load in the taken delay slot.
// Left (4 words): the slot pointer has to form as retail's `sll v1,a1,2; addu v1,v1,a0;
// addiu s0,v1,0x778` (index first, base second, offset last) with the fetch folded as
// `lw v1,0x778(v1)`; ours forms `addiu t0,a0,0x778; addu s0,t0,v1`. Writing
// `(int *)(param_2 * 4 + (int)param_1) + 0x1de` gets the sll/addu pair but orders the prologue
// saves differently, and the counting loop then wants `*slot` cached in a1.
// near miss from lane fm5 (unreviewed)
