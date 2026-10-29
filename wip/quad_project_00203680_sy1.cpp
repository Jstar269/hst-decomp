/* HSTMATCH module=EBOOT.BIN start=0x00203680 end=0x002038ec symbol=FUN_00203680 lang=c++ */
struct Color {
  unsigned char r, g, b, a;
};
struct Quad {
  float x, y, w, h;
} __attribute__((aligned(16)));
struct Cell {
  char pad[0x20];
  int f0;
  int pad4;
  unsigned char r, g, b, pad2;
};
struct Self {
  char pad1[0xf0];
  unsigned char r;
  unsigned char g;
  unsigned char b;
  char pad2[0x520 - 0xf3];
  void *tex;
};

extern float DAT_002ef1d0;
extern int DAT_003313c4;
extern "C" void FUN_0005bbf0(int, float *, float *, float *, float *, float *, float *);
extern "C" void FUN_00051894(void *tex, Color col, float u0, float v0, float x0, float y0, float u1, float v1,
                             float x1, float y1, float z);

extern "C" void FUN_00203680(Self *self, int index, int level, Quad q, float fov)
{
  if (DAT_002ef1d0 == 0.0f)
    return;
  float f5c, f58, f54, f50, f4c, f48;
  FUN_0005bbf0(DAT_003313c4, &f5c, &f58, &f54, &f50, &f4c, &f48);
  float s = fov / 2.0f;
  float dx = s * (f54 / 480.0f);
  float dy = s * (f50 / 272.0f);
  float left = q.x - dx;
  float top = q.y - dy;
  float right = q.x + dx;
  float bottom = q.y + dy;
  if (10.0f < left && right < 4086.0f && 10.0f < top && bottom < 4086.0f) {
    float ox = -1808.0f;
    float oy = -1912.0f;
    float x0 = left + ox;
    float y0 = top + oy;
    float x1 = right + ox;
    float y1 = bottom + oy;
    int off = index * 16;
    Cell *c = (Cell *)(off + (int)self);
    Color col;
    col.a = (int)((float)level * DAT_002ef1d0);
    col.r = self->r * c->r / 255;
    col.g = self->g * c->g / 255;
    col.b = self->b * c->b / 255;
    FUN_00051894(self->tex, col, (float)(c->f0 * 42), 0.0f, x0, y0,
                 (float)((c->f0 + 1) * 42), 42.0f, x1, y1, 65280.0f);
  }
}
// sy1: complete decode, 155/155 words (was 82/155): same instruction multiset, differs only in scheduling and FPR numbering.
// Decoded: by-value Quad (aligned(16): gives the sp+48 copy at the frame bottom), early-out on DAT_002ef1d0==0, six-float
// FUN_0005bbf0 out block, dx = fov/2*(f54/480), dy = fov/2*(f50/272), range test 10 < x-dx, x+dx < 4086, 10 < y-dy, y+dy < 4086
// (4086.0f = 0x457f6000), then colour bytes r/g/b = self.rgb(0xf0..0xf2) * cell[+0x28..0x2a] / 255 (magic 0x80808081) and
// alpha = (int)(level * DAT_002ef1d0), FUN_00051894(self->tex(0x520), Color, 42*cell.f20, 0, x0, y0, 42*(cell.f20+1), 42,
// x1, y1, 65280.0f) with x0 = left - 1808, y0 = top - 1912. Cell at self + index*16 (+0x20 f0, +0x28.. bytes).
// Open: retail keeps c (f54/480 operand) in $f2 and x in $f3 (we get the reverse), loads the self rgb bytes before the ori t2
// constant, computes the four offset floats interleaved with the colour maths, and uses add.s value-first (x0 = left + (-1808)).
// Tried: float locals x/y first, left/top order, direct expressions in the condition (worse), ox/oy non-const locals, pre-computed
// x0/y0/x1/y1 before the colour, `off + (int)self` cell address.
// near miss from lane sy1 (unreviewed)
