/* HSTMATCH module=EBOOT.BIN start=0x0010aeb0 end=0x0010b06c symbol=FUN_0010aeb0 lang=c++ */
struct Tile {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
  virtual int Width(int arg);
  virtual int Height(int arg);
};
struct Req {
  int f0;
  int f4;
  int idx;
  int arg;
  short x0, y0, x1, y1;
  short f18;
  short pad1a;
  int f1c;
};
struct Quad {
  int f0;
  int f4;
  int idx;
  int arg;
  short x0, y0, x1, y1;
  short f18;
  short pad1a;
  int f1c;
  void *f20;
};
struct Mgr {
  int pad0;
  Tile **tiles;
  char pad8[0x58];
  float fx;
  float fy;
};
extern "C" char DAT_002d9210[];
extern "C" void FUN_00101630(Mgr *m, Quad *q, int n);

extern "C" void FUN_0010aeb0(Mgr *m, Req *r)
{
  Quad buf[128];
  short x0 = r->x0;
  int f0 = r->f0;
  int idx = r->idx;
  short x1 = r->x1;
  int arg = r->arg;
  int f1c = r->f1c;
  short y0 = r->y0;
  short y1 = r->y1;
  short f18 = r->f18;
  short dx = x1 - x0;
  short dy = y1 - y0;
  m->fx = (float)x0;
  m->fy = (float)y0;
  short w = m->tiles[idx]->Width(arg);
  short h = m->tiles[idx]->Height(arg);
  int cols = (dx + w - 1) / w;
  int rows = (dy + h - 1) / h;
  int count = 0;
  int row = 0;
  int col;
  Quad *q;
  int y;
  int x;
  if (rows > 0) {
    q = buf;
    y = 0;
    do {
      col = 0;
      if (cols > 0) {
        x = 0;
        do {
          q->f0 = f0;
          q->f4 = 0;
          q->idx = idx;
          q->arg = arg;
          q->x0 = x;
          q->y0 = y;
          col++;
          count++;
          q->x1 = w + q->x0;
          x += w;
          q->y1 = h + q->y0;
          q->f18 = f18;
          q->f1c = f1c;
          q->f20 = DAT_002d9210;
          q++;
        } while (col < cols);
      }
      row++;
      y += h;
    } while (row < rows);
  }
  FUN_00101630(m, buf, count);
}
// NEAR MISS (25 words, one register decision): control flow, frame (4672, buffer at sp+64), saved registers s0-s8,
// loop registers (t6 row, t5 col, t4 q, t3 y, t2 x, a2 count) and the whole loop body match. The remaining diffs all
// come from the two short call results: retail sign-extends the SECOND virtual call result straight away into v1
// (`seh v1,v0`) and reloads the spilled first one (`lw v0,60(sp)`) into v0 (w=v0, h=v1, x1/y1 temporaries v0/v1);
// ours extends h in place later (`seh v0,v0` after the reload into v1), so w=v1, h=v0 everywhere.
// Matching idioms: dx/dy = (short)(x1-x0) computed before the calls, loop variables declared row,col,q,y,x in that order.
// Ruled out: short vs int return types, int/short locals with casts, declaration order of w/h, rows before cols
// (worse: 38), count initialised earlier (worse), uncached m->tiles[idx] reads.
// rt2 2026-10-21 EBOOT twin (from hstp wip/tile_quads_00110c70.cpp; DAT/FUN/call target remapped).
// Same 25-word profile as the twin: all temps are swapped v0<->v1. Retail loads x1 into v0 and y1 into v1,
// folds dx in place (subu v0), then dy into v0; after the 2nd virtual call it does seh v1,v0 (h) BEFORE
// lw v0,60(sp)/seh v0,v0 (w) so w=v0,h=v1. Ours: x1->v1, y1->v0, and reloads w into v1 first so w=v1,h=v0;
// every remaining diff follows from that one swap. Retried here: w/h declaration order (40), int
// intermediates (79), dx/dy moved before the other field loads (same 25). Invariant to source order =>
// same allocator tie-break as the twin; parked with the twin's notes.
// near miss from lane rt2 (unreviewed)
