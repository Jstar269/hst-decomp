/* HSTMATCH module=EBOOT.BIN start=0x00152a58 end=0x00152b88 symbol=FUN_00152a58 lang=c99 */
typedef struct Info { int *first; } Info;
typedef struct Owner { char pad[0xf4]; Info **slot; } Owner;
typedef struct Target { char pad[0x70]; Owner *owner; } Target;
typedef struct Spec {
  char pad[8];
  int a;
  int b;
  int c;
  int d;
  int e;
  unsigned char f;
  unsigned char g;
} Spec;

extern unsigned char DAT_003402f0;
extern Target *DAT_0034a114;
extern char DAT_002dc6ac[];
extern unsigned int DAT_003083cc;
extern unsigned int DAT_00308b98;
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(const char *, ...);
extern Target *FUN_001c6f70(Target *, int, int);
extern void FUN_00288208(Target *, int, int, unsigned char, int);
extern unsigned int *FUN_00000bcc(int);

unsigned int *FUN_00152a58(Spec *spec, void *arg)
{
  Target *t;
  int skip;
  unsigned int *obj;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(arg);
    FUN_0014fd94(DAT_002dc6ac, spec->a, spec->b, spec->c);
  }
  t = FUN_001c6f70(DAT_0034a114, spec->a, spec->b);
  skip = spec->g;
  if (t != 0) {
    Info **h;
    FUN_00288208(t, spec->c, spec->d, spec->f, spec->e);
    h = t->owner->slot;
    if ((h != 0 ? *h : 0) == 0) {
      skip = 1;
    } else {
      Info *n = (h != 0 ? *h : 0);
      if (*n->first == 0) {
        skip = 1;
      }
    }
  }
  if (skip == 0) {
    obj = FUN_00000bcc(0x10);
    if (obj != 0) {
      int c = spec->e;
      int b = spec->b;
      int a = spec->a;
      obj[0] = (unsigned int)&DAT_003083cc;
      obj[0] = (unsigned int)&DAT_00308b98;
      obj[1] = a;
      obj[2] = b;
      obj[3] = c;
    }
  } else {
    obj = 0;
  }
  return obj;
}
// lane sn6: 25 of 76 words differ (this version is 73 words, retail 76). Matches word for word up to the lookup/log/FUN_001c6f70/FUN_00288208 calls (+0x5c).
// Remaining differences (all layout of two things retail keeps as real if/else blocks):
//  1. `h ? *h : 0` (twice, h = owner->slot): retail `beqzl v1,JOIN; move v0,zero / b JOIN; lw v0,0(v1) / move v0,zero(dead else copy) / JOIN`; ours folds to `beqzl v1,L; move v0,zero; lw v0,0(v1)`
//     (no `b`, no dead copy). Ternary, if/else statements, inline getters with if/else or early returns all fold the same way.
//  2. the tail: retail `bnezl s0,END; move v0,zero ... sw a3,12(v0); b END; nop; move v0,zero(dead else copy); END: lw ra...` and `beqzl v0,END+4; lw ra`; ours drops the `b` and the
//     dead copy. Early-return forms, a separate `ret` variable, `ret = 0` first all change more than they fix (27..42 words).
//  The flag must be an `int` (not unsigned char / bool: those add andi / sltu), loaded by lbu before the beqz on the looked-up object (it sits in that branch's slot).
// second pass (sn6): the saved version above had `unsigned char skip` although the note says int; with `int skip` (copy of the lbu) the andi vanishes and the shift-tolerant miss drops from 25 to ~9 words
//  (72 vs 76 words). Remaining: the two retail dead else copies (`b J; ...; move v0,zero; J:`) of `h ? *h : 0` and the tail `b END; nop; move v0,zero`. `#pragma peephole off` changes the earlier part (68 words), opt_dead_code off /
//  optimization_level do nothing.
// near miss from lane sn6 (unreviewed)
