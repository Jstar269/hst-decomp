/* HSTMATCH module=EBOOT.BIN start=0x0025d5c4 end=0x0025d6e8 symbol=FUN_0025d5c4 lang=c++ */
/* Clone of src/sharing_main/center_two_widgets_x_0026db70.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Hides the +0x3c4 widget, then for each of the two pairs whose control widget has flag bits 0-1 set moves the paired rect to the stored x and centres it on that x (SetX / MoveX(-Width/2) inline helpers, as in src/sharing_main/recenter_rects_0027c26c.cpp). */
struct Widget {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
  short pad0c;
  unsigned short flags;
};

struct Self {
  char pad0[0x38c];
  Widget *a;
  Widget *ra;
  Widget *b;
  Widget *rb;
  short pad39c;
  short xa;
  short pad3a0;
  short xb;
  char pad3a4[0x3c4 - 0x3a4];
  Widget *w3c4;
};

extern "C" void FUN_000ffb3c(Widget *, bool);

static inline short Width(const Widget *r) { return r->x1 - r->x0; }

static inline void SetX(Widget *r, short x)
{
  short d = x - r->x0;
  r->x0 = x;
  r->x1 += d;
}

static inline void MoveX(Widget *r, short d)
{
  r->x0 += d;
  r->x1 += d;
}

extern "C" void FUN_0025d5c4(Self *self)
{
  FUN_000ffb3c(self->w3c4, false);
  if (self->a->flags & 3) {
    SetX(self->ra, self->xa);
    MoveX(self->ra, -Width(self->ra) / 2);
  }
  if (self->b->flags & 3) {
    SetX(self->rb, self->xb);
    MoveX(self->rb, -Width(self->rb) / 2);
  }
}
