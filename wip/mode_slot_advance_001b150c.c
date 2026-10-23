/* HSTMATCH module=EBOOT.BIN start=0x001b150c end=0x001b1628 symbol=FUN_001b150c lang=c99 */
typedef unsigned char bool;
typedef unsigned int uint;
typedef unsigned int undefined4;
#define false 0
#define true 1

struct Self {
  int slot[0x1da];
  char pad768[0x79c - 0x768];
  int f79c;
  char pad7a0[0x7ac - 0x7a0];
  int f7ac;
  uint f7b0;
};

extern float DAT_002e515c[];
extern unsigned char *FUN_0022cd60(void);
extern void FUN_00062904(int);
extern int FUN_000627e8(int, int);
extern void FUN_001b210c(float, float, int, int *);

undefined4 FUN_001b150c(struct Self *s)
{
  int bVar1;
  unsigned char *pcVar2;
  uint uVar4;
  uint uVar5;

  pcVar2 = FUN_0022cd60();
  if (*pcVar2 == 0) {
    return 0;
  }
  uVar4 = s->f7b0;
  uVar5 = s->f79c + 0xe;
  if (uVar5 != uVar4) {
    bVar1 = ((int)uVar4 < 0x1da) && (s->slot[uVar4] != 0);
    if (bVar1) {
      if (0 <= s->f7ac) {
        FUN_00062904(s->slot[uVar4]);
        s->f7ac = -1;
      }
      s->f7b0 = 0x1da;
    }
    if (0 <= (int)uVar5 && (int)uVar5 < 0x32) {
      bVar1 = false;
      if ((int)uVar5 < 0x1da) {
        bVar1 = s->slot[uVar5] != 0;
      }
      if (bVar1) {
        s->f7b0 = uVar5;
        s->f7ac = FUN_000627e8(s->slot[uVar5],0);
        FUN_001b210c(DAT_002e515c[uVar5],DAT_002e515c[uVar5],0x34179c,&s->f7ac);
      }
    }
    return 1;
  }
  return 0;
}
// NEAR 42 of 71 words (0x001b150c), same length as retail. Pseudocode-faithful rewrite with typed
// `struct Self` (slot[0x1da], f79c/f7ac/f7b0), an `int` flag assigned by `&&`, `unsigned char *`
// for the mode-byte pointer, `0 <= s->f7ac` for the borrow guard, and - the key discovery -
// `DAT_002e515c` is an array of FLOATS: retail loads `lwc1 $f12,0(v0)` from `DAT + uVar5*4` and
// passes it twice (`mov.s $f13,$f12`), so `FUN_001b210c(float, float, int, int *)`.
// MATCHES: prologue, `lbu`/`bnezl` first guard, `beql s0,v1,EPILOGUE` + zero-in-delay, `slti v0,v1,474`
// + `beqzl` on the raw slti result (no `move v0,zero`), `bltzl` on f7ac, the `li 0x1da` stores, the
// float index into DAT_002e515c and the whole tail call.
// LEFT: the `uVar5 < 0x32` guard - retail splits it (`slt v0,s0,zero; xori v0,1; beqz; nop; slti`),
// ours either `sltiu` or a single fused `bltzl`, and the `sw s0,1968(s1)` / index registers are a
// slot apart.
// Ruled out: `uVar5 < 0x32` alone (69 words, `sltiu`), `bool` flag (adds `andi 0xff`), the
// `bVar1 = false; if (range) bVar1 = ...` form (70 words, one short), `&&`-joined guards (64).
// near miss from lane fm5 (unreviewed)
