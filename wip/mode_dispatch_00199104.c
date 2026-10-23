/* HSTMATCH module=EBOOT.BIN start=0x00199104 end=0x001991cc symbol=FUN_00199104 lang=c99 */
typedef unsigned char undefined1;

extern undefined1 DAT_00341770;
extern undefined1 DAT_002e189c;
extern void FUN_001991cc(undefined1 *);
extern void FUN_001991f8(int, int);
extern void FUN_002b7c30(void);
extern int FUN_002b7cd0(void);

void FUN_00199104(int param_1)
{
  int iVar1;

  DAT_00341770 = 0;
  switch (*(int *)(param_1 + 0x7c)) {
  case 0:
    break;
  case 1:
    iVar1 = FUN_002b7cd0();
    if (iVar1 != 0) {
      switch (iVar1) {
      case 1:
        break;
      case 2:
        DAT_00341770 = 1;
        break;
      case 3:
        FUN_002b7c30();
        break;
      case 4:
        break;
      default:
        FUN_001991cc(&DAT_002e189c);
        break;
      }
    }
    else {
      FUN_001991f8(param_1,0);
    }
    break;
  }
}

// NEAR MISS: 49/50 words, 1 word short. Every branch, argument setup and call site
// matches retail except ONE instruction: retail starts the inner compare chain with
// `move a1,v0` and tests a1 (beqzl a1,..., beq a1,v1,...), ours tests v0 directly and
// so is one word shorter, which shifts the two epilogue targets by 4 bytes.
// The shape that reproduced everything else: the outer dispatch is a two-label switch
// on the 0x7c field (case 0 falls to the end, case 1 runs the inner block), and the
// inner one is `if (v != 0) { switch (v) { case 1: break; case 2: DAT=1; break;
// case 3: F(); break; case 4: break; default: G(&DAT); break; } } else { H(param,0); }`
// (the `!= 0` guard with the else call is what gives retail's `beqzl ... move a0,s0`).
// Ruled out: the plain inner switch including case 0 (tests 4,3,2,1 then a separate
// case-0 block: 35 words off, wrong chain order); `if (v == 0) {H} else {switch}`
// (inverts to `bnezl`); a flat if/else-if chain in retail's test order (bnel/bnezl
// everywhere, 45 words); `case 0: return;` in the outer switch (duplicates the
// epilogue, 52 words). The remaining difference is the same a1-vs-v0 switch-selector
// colouring that MWCC-NOTES records as unsolved for 0x002821a0.
// near miss from lane fm5 (unreviewed)
