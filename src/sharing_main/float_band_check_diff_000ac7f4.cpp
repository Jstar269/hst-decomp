/* HSTMATCH module=hstp_trans_main.prx start=0x000ac7f4 end=0x000ac984 symbol=FUN_000ac7f4 lang=c++ */
/* Clone of src/eboot/float_band_check_diff_000a9e00.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Subtracts two Vec4 (0x22434), derives a limit from the context (0x16442c, 0x000b3c68), and when |dx| is under it applies the float band test of 0x000a9d20 to dy. Matching idioms: the float locals (s, dx, dy) are declared before the Vec4 call and assigned afterwards (FPR order f22/f21/f20); the limit is its own float local; the band test is a static inline with early returns (as in 0x000a9d20), the outer test a bool. */
extern "C" float fabsf(float);
struct Vec4 { float x, y, z, w; };
struct Ctx {
  char pad0[0x24];
  float f24;
  char pad1[4];
  float f2c;
  char pad2[0xc];
  float f3c;
};
struct Game {
  char pad[0x440];
  int f440;
};
extern "C" void FUN_0002245c(Vec4 *, Vec4 *, Vec4 *);
extern "C" Ctx *FUN_000b6e80(Game *g);
extern "C" float FUN_001709a0(Ctx *, int);

static inline int Band(Game *g, float dy, int flag)
{
  if (flag == 0 || dy > -(FUN_000b6e80(g)->f3c * 0.01f)) {
    Ctx *c = FUN_000b6e80(g);
    int bb;
    if (dy > -(c->f24 * 0.01f) && dy < 0.0f) {
      bb = 1;
    } else {
      bb = 0;
    }
    if (bb == 0 && dy < 0.0f) {
      return 1;
    }
  }
  return 0;
}

extern "C" int FUN_000ac7f4(Game *g, Vec4 *a, Vec4 *b, int unused, int flag)
{
  Vec4 d;
  float s;
  float dx;
  float dy;
  FUN_0002245c(&d, a, b);
  dx = d.x;
  dy = d.y;
  s = FUN_001709a0(FUN_000b6e80(g), g->f440) * 0.01f;
  float lim = (1.0f - s) * (FUN_000b6e80(g)->f2c * 0.01f);
  bool ok = fabsf(dx) < lim;
  if (ok) {
    if (Band(g, dy, flag)) {
      return 1;
    }
  }
  return 0;
}
