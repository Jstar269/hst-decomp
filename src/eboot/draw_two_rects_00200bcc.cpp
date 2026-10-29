/* HSTMATCH module=EBOOT.BIN start=0x00200bcc end=0x00200d94 symbol=FUN_00200bcc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the two identical blocks are one inline DrawRect(pos, rect, dst); the renderer helper takes (dst, six floats); retail's duplicate short loads come from reading the offset sums as direct fields but the width/height/midpoints through inline Rect member functions (getter vs direct access do not CSE); the pos/rect pointers are read into locals before each call; readability pass; exact match verified; names and types await human review. */
struct Rect {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
  short Width() const { return (short)(x1 - x0); }
  short Height() const { return (short)(y1 - y0); }
  short CenterX() const { return (short)((x0 + x1) / 2); }
  short CenterY() const { return (short)((y0 + y1) / 2); }
};
/* Position holder: float x/y at 0x60 */
struct Pos { char pad[0x60]; float px; float py; };
struct Obj {
  char pad0[0x10];
  Pos *posA;    /* 0x10 */
  Pos *posB;    /* 0x14 */
  char pad18[0xbc - 0x18];
  Rect *rectA;   /* 0xbc */
  char pad_c0[0x120 - 0xc0];
  Rect *rectB;   /* 0x120 */
};
extern "C" void FUN_0005bbd4(void *, float, float, float, float, float, float);
extern "C" void FUN_0005bc58(void *);

static inline void DrawRect(Pos *pos, Rect *r, void *dst)
{
  int ix = (int)pos->px;
  int iy = (int)pos->py;
  FUN_0005bbd4(dst, (float)(r->x0 + ix), (float)(r->y0 + iy),
               (float)r->Width(), (float)r->Height(),
               (float)(ix + r->CenterX()), (float)(iy + r->CenterY()));
  FUN_0005bc58(dst);
}

extern "C" void FUN_00200bcc(Obj *self, void *dstA, void *dstB)
{
  Pos *pa = self->posA;
  Rect *ra = self->rectA;
  DrawRect(pa, ra, dstA);
  Pos *pb = self->posB;
  Rect *rb = self->rectB;
  DrawRect(pb, rb, dstB);
}
