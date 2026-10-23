/* HSTMATCH module=EBOOT.BIN start=0x000b3cf4 end=0x000b3f20 symbol=FUN_000b3cf4 lang=c++ */
struct Tag {};
struct Name18 { char c[18]; };
struct Sub16 { int f0; int f4; int f8; void *f12; };
struct Sprite { void *vt; int pad[3]; Sub16 a; Sub16 b; };
struct Vec { Name18 *base; unsigned int count; unsigned int cap; };

extern "C" void FUN_0008b1d8(void *, int, Tag);
extern "C" {
void FUN_000649c0(Sprite *);
void FUN_0008c230(Sub16 *);
int FUN_000651b8(Sprite *, const char *, int, int, const char *);
int FUN_000650e0(Sprite *);
int FUN_0006517c(Sprite *, int, int);
int FUN_00014d64(const char *, const char *);
void FUN_000114c0(void *, int, int);
int FUN_00065104(Sprite *, unsigned int, unsigned int);
void FUN_000b4360(Vec *, Name18 *, Tag);
void FUN_00066338(Sub16 *, int);
void FUN_00064a08(Sprite *, int);
extern int DAT_003070bc;
extern char DAT_002d4780[];
extern char DAT_002d47a8[];
extern char DAT_002d47ac[];
}

extern "C" void FUN_000b3cf4(Vec *v)
{
  Sprite spr;
  Name18 name;
  Name18 *dst;
  int j;
  unsigned int r;
  unsigned int q;
  char *p;
  unsigned int i;
  int n;
  int sel;
  Sprite *sp;

  for (i = 0; i < 2; i++) {
    FUN_0008b1d8(&v[i], v[i].count, Tag());
  }
  sp = &spr;
  FUN_000649c0(sp);
  spr.vt = &DAT_003070bc;
  FUN_0008c230(&spr.a);
  FUN_0008c230(&sp->b);
  if (FUN_000651b8(sp, DAT_002d4780, 0, 0, DAT_002d47a8) != 0) {
    n = FUN_000650e0(sp);
    j = 0;
    while (j < n) {
      i = FUN_0006517c(&spr, j, 0);
      sel = !FUN_00014d64((const char *)i, DAT_002d47ac);
      j = j + 1;
      FUN_000114c0(&name, 0, 0x12);
      r = 0;
      p = name.c;
      do {
        for (q = 0; q < 3; q++) {
          p[q] = FUN_00065104(&spr, j, q);
        }
        j = j + 1;
        p = p + 3;
      } while (++r < 6);
      if (v[sel].count < v[sel].cap) {
        dst = v[sel].base + v[sel].count;
        if (dst != 0) {
          *dst = name;
        }
        v[sel].count = v[sel].count + 1;
      } else {
        FUN_000b4360(&v[sel], &name, Tag());
      }
    }
  }
  spr.vt = &DAT_003070bc;
  FUN_00066338(&spr.b, 0);
  FUN_00066338(&spr.a, 0);
  FUN_00064a08(&spr, 0);
}

// NEAR MISS: 139/139 words, 1 differs. Retail passes the second sub-object as `addiu a0,s0,32`
// (s0 = &spr, set before the constructor call); ours folds it to `addiu a0,sp,96` because mwcc
// proves s0 == sp+64. Tried: &spr.b / &sp->b / &sp->sub[1] (array member) / &sp->a + 1 / a
// Sub16 *bp temporary - every spelling folds to the absolute address. Everything else is exact:
// the empty-Tag third arguments, the do-while (++r < 6) name loop and the int sel (not bool, which
// adds an `andi` before the index multiply) are all required.
// near miss from lane fm4 (unreviewed)
