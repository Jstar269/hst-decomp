/* HSTMATCH module=EBOOT.BIN start=0x00203680 end=0x002038ec symbol=FUN_00203680 lang=c++ */
/* STATUS CORRECTION 2026-10-24: measured 82/155 words, 143 differ, first diff +0x4. */
struct Self {
  char pad0[0xf0];
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

struct Quad {
  float x, y, w, h;
};

static inline Quad holdQuad(Quad v) { return v; }

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
  Quad qq = holdQuad(*q);
  float x = qq.x;
  float y = qq.y;
  float w = qq.w;
  float h = qq.h;
  if (DAT_002ef1d0 == 0.0f) {
    return;
  }
  float out[6];
  FUN_0005bbf0(DAT_003313c4, &out[0], &out[1], &out[2], &out[3], &out[4], &out[5]);
  float a = out[0];
  float b = out[1];
  float c = out[2];
  float d = out[3];
  float e = out[4];
  float f = out[5];
  float s = fov / 2.0f;
  float dx = s * (c / 480.0f);
  float dy = s * (b / 272.0f);
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
}
// NEAR MISS 2026-10-22: 70/155 words, 153 differ - this is an EARLY PARTIAL, not a converged draft.
// Verified from the disassembly so far: the four floats are copied from a3 (0,4,8,12) to sp+0x30..3c;
// early-out `c.eq.s 0.0, DAT_002ef1d0; bc1t`; FUN_0005bbf0(DAT_003313c4, &sp+5c,&sp+58,&sp+54,
// &sp+50,&sp+4c,&sp+48) fills six stack floats; s = f12(f20)/2.0f then dx = s*(sp54/1000.0f),
// dy = s*(sp50/280.0f) where the divisors are 480.0 (0x43f0) and 272.0 (0x4388) — RESOLVED: the code uses 480.0f/272.0f; the 1000/280 figures were a misread of the same slots.
// the four c.lt.s/bc1f range tests against 0x457f6000 (4083.0f) etc.; then index*16 + self indexes a
// 0x20-byte-stride cell (lbu 0x28/0x29/0x2a, lw 0x20) and three byte products with the 0x80808081
// magic (x/128) are stored to sp+0x44..0x47 as a colour; f13/f14/f15/f18 are used afterwards, so
// there is a second half (not yet decoded) after 0x203868.
// Next step: decode 0x203868..0x2038ec before writing the second half.
// near miss from lane fm4 (unreviewed)
// improved by lane fm10 (unreviewed): 153 -> 143 differing words
