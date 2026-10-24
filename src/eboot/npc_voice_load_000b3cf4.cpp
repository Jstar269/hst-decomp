/* HSTMATCH module=EBOOT.BIN start=0x000b3cf4 end=0x000b3f20 symbol=FUN_000b3cf4 lang=c++ */
/* LoadNpcVoicePack: data/chara/parameter/npc_voicepack.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Name18 { char c[18]; };
struct Vec { Name18 *base; unsigned int count; unsigned int cap; };

struct Sprite;
struct Sub16;

extern "C" void FUN_0008b1d8(void *, int, Tag);
extern "C" {
void FUN_000649c0(void *);
void FUN_0008c230(void *);
int FUN_000651b8(Sprite *, const char *, int, int, const char *);
int FUN_000650e0(Sprite *);
int FUN_0006517c(Sprite *, int, int);
int FUN_00014d64(const char *, const char *);
void FUN_000114c0(void *, int, int);
int FUN_00065104(Sprite *, unsigned int, unsigned int);
void FUN_000b4360(Vec *, Name18 *, Tag);
void FUN_00066338(void *, int);
void FUN_00064a08(void *, int);
extern int DAT_003070bc;
extern char DAT_002d4780[];
extern char DAT_002d47a8[];
extern char DAT_002d47ac[];
}

struct Str {
  int w[4];
  Str() { FUN_0008c230(this); }
  ~Str() { FUN_00066338(this, 0); }
};

struct Base16 {
  int w[4];
  Base16() {
    FUN_000649c0(this);
    *(char **)this = (char *)&DAT_003070bc;
  }
  ~Base16() { FUN_00064a08(this, 0); }
};

struct Sprite : Base16 {
  Str a;
  Str b;
  ~Sprite() { *(char **)this = (char *)&DAT_003070bc; }
};

extern "C" void FUN_000b3cf4(Vec *v)
{
  int j;
  unsigned int r;
  unsigned int q;
  char *p;
  unsigned int i;
  int n;
  int sel;
  Name18 *dst;

  for (i = 0; i < 2; i++) {
    FUN_0008b1d8(&v[i], v[i].count, Tag());
  }
  Sprite spr;
  Name18 name;
  if (FUN_000651b8(&spr, DAT_002d4780, 0, 0, DAT_002d47a8) != 0) {
    n = FUN_000650e0(&spr);
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
}
