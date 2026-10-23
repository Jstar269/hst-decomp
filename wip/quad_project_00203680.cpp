/* HSTMATCH module=EBOOT.BIN start=0x00203680 end=0x002038ec symbol=FUN_00203680 lang=c++ */
struct Self {
  char pad0[0xf0];
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

struct Quad {
  float x, y, w, h;
};

struct Cell {
  char pad0[0x20];
  int f20;
  char pad1[4];
  unsigned char a;
  unsigned char b;
  unsigned char c;
};

extern float DAT_002ef1d0;
extern int DAT_003313c4;
extern "C" void FUN_0005bbf0(int, float *, float *, float *, float *, float *, float *);

extern "C" void FUN_00203680(Self *self, int index, int level, Quad *q, float fov)
{
  float x = q->x;
  float y = q->y;
  float w = q->w;
  float h = q->h;
  if (DAT_002ef1d0 == 0.0f) {
    return;
  }
  float a, b, c, d, e, f;
  FUN_0005bbf0(DAT_003313c4, &a, &b, &c, &d, &e, &f);
  float s = fov / 2.0f;
  float dx = s * (c / 1000.0f);
  float dy = s * (b / 280.0f);
  if (!(y - dy < d)) {
    return;
  }
  if (!(x - dx < a)) {
    return;
  }
  if (!(x + dx < a + w)) {
    return;
  }
  if (!(y + dy < d + h)) {
    return;
  }
  Cell *cell = (Cell *)((char *)self + index * 16);
  float k = (float)level * DAT_002ef1d0;
  unsigned char cr = (unsigned char)((self->r * cell->a * 0x8081) >> 7);
  unsigned char cg = (unsigned char)((self->g * cell->b * 0x8081) >> 7);
  unsigned char cb = (unsigned char)((self->b * cell->c * 0x8081) >> 7);
  (void)k;
  (void)cr;
  (void)cg;
  (void)cb;
}
// NEAR MISS 2026-10-22: 70/155 words, 153 differ - this is an EARLY PARTIAL, not a converged draft.
// Verified from the disassembly so far: the four floats are copied from a3 (0,4,8,12) to sp+0x30..3c;
// early-out `c.eq.s 0.0, DAT_002ef1d0; bc1t`; FUN_0005bbf0(DAT_003313c4, &sp+5c,&sp+58,&sp+54,
// &sp+50,&sp+4c,&sp+48) fills six stack floats; s = f12(f20)/2.0f then dx = s*(sp54/1000.0f),
// dy = s*(sp50/280.0f) where 1000.0 (0x447a0000? no - 0x43f0 = 480.0) - recheck the constants;
// the four c.lt.s/bc1f range tests against 0x457f6000 (4083.0f) etc.; then index*16 + self indexes a
// 0x20-byte-stride cell (lbu 0x28/0x29/0x2a, lw 0x20) and three byte products with the 0x80808081
// magic (x/128) are stored to sp+0x44..0x47 as a colour; f13/f14/f15/f18 are used afterwards, so
// there is a second half (not yet decoded) after 0x203868.
// Next step: decode 0x203868..0x2038ec before writing the second half.
// near miss from lane fm4 (unreviewed)
