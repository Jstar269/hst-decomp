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
  short dx;
  short dy;
  dy = y1 - y0;
  dx = x1 - x0;
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
          count++;
          q->x1 = w + q->x0;
          x += w;
          q->y1 = h + q->y0;
          q->f18 = f18;
          q->f1c = f1c;
          q->f20 = DAT_002d9210;
          q++;
        } while (++col < cols);
      }
      row++;
      y += h;
    } while (row < rows);
  }
  FUN_00101630(m, buf, count);
}
// lane wf20261026-e01-06 (2026-10-26): 25 -> 20 words. Loop now matches retail's schedule with
// `count++` before the x1 store and `while (++col < cols)`; dy assigned before dx (declared dx,dy)
// gives retail's early dx subu. Still open: dx/dy s7/s8 swapped and the w/h v0/v1 colouring after the
// second virtual call (retail seh v1,v0 for h before reloading w). Ruled out this pass: DivUp inline,
// (w+dx-1)/w, (dx+(w-1))/w, (dx-1+w)/w, rows before cols, dx/dy declared at function top in both orders,
// split declaration/assignment, (short) casts.
// improved by lane wf20261026-e01-06 (unreviewed): 25 -> 20 differing words
