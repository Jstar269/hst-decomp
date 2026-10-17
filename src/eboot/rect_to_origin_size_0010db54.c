/* HSTMATCH module=EBOOT.BIN start=0x0010db54 end=0x0010dc48 symbol=FUN_0010db54 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed 36-byte record and one-element local array, field-wise copy loop, the four rect shorts read into locals first, then float stores and w/h, and the clearing loop as do { } while (++i < 1) so it stays rolled; exact match verified; names and types await human review. */
typedef struct Rec {
  int w0, w1, w2, w3;
  short s10, s12, s14, s16, s18;
  int f1c, f20;
} Rec;
typedef struct Obj { char pad[0x60]; float fx; float fy; } Obj;
extern void FUN_00101630(Obj *, Rec *, int);

void FUN_0010db54(Obj *o, Rec *src)
{
  Rec local[1];
  Rec *p = src;
  Rec *q = local;
  Rec *end = src + 1;
  unsigned i;
  short w, h;
  for (; p < end; p++) {
    q->w0 = p->w0;
    q->w1 = p->w1;
    q->w2 = p->w2;
    q->w3 = p->w3;
    q->s10 = p->s10;
    q->s12 = p->s12;
    q->s14 = p->s14;
    q->s16 = p->s16;
    q->s18 = p->s18;
    q->f1c = p->f1c;
    q->f20 = p->f20;
    q++;
  }
  short x = local[0].s10, y = local[0].s12, x2 = local[0].s14, y2 = local[0].s16;
  o->fx = (float)x;
  o->fy = (float)y;
  w = x2 - x;
  h = y2 - y;
  i = 0;
  do {
    local[i].s10 = 0;
    local[i].s12 = 0;
    local[i].s14 = w;
    local[i].s16 = h;
  } while (++i < 1);
  FUN_00101630(o, local, 1);
}
