/* HSTMATCH module=hstp_trans_main.prx start=0x0020f39c end=0x0020f564 symbol=FUN_0020f39c lang=c++ */
/* Clone of src/eboot/draw_two_rects_00200bcc.cpp (hstclone.py tag c060607): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the two identical blocks are one inline DrawRect(pos, rect, dst); the renderer helper takes (dst, six floats); retail's duplicate short loads come from reading the offset sums as direct fields but the width/height/midpoints through inline Rect member functions (getter vs direct access do not CSE); the pos/rect pointers are read into locals before each call; exact match verified; names and types await human review. */
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
struct Pos { char pad[0x60]; float px; float py; };
struct Obj {
  char pad0[0x10];
  Pos *f10;
  Pos *f14;
  char pad18[0xbc - 0x18];
  Rect *fbc;
  char pad_c0[0x120 - 0xc0];
  Rect *f120;
};
extern "C" void FUN_0005c85c(void *, float, float, float, float, float, float);
extern "C" void FUN_0005c8e0(void *);

static inline void DrawRect(Pos *pos, Rect *r, void *dst)
{
  int ix = (int)pos->px;
  int iy = (int)pos->py;
  FUN_0005c85c(dst, (float)(r->x0 + ix), (float)(r->y0 + iy),
               (float)r->Width(), (float)r->Height(),
               (float)(ix + r->CenterX()), (float)(iy + r->CenterY()));
  FUN_0005c8e0(dst);
}

extern "C" void FUN_0020f39c(Obj *param_1, void *param_2, void *param_3)
{
  Pos *pa = param_1->f10;
  Rect *ra = param_1->fbc;
  DrawRect(pa, ra, param_2);
  Pos *pb = param_1->f14;
  Rect *rb = param_1->f120;
  DrawRect(pb, rb, param_3);
}
