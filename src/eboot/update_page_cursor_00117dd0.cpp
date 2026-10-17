/* HSTMATCH module=EBOOT.BIN start=0x00117dd0 end=0x00117ff8 symbol=FUN_00117dd0 lang=c++ */
/* Clone of src/sharing_main/update_page_cursor_00122e94.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: locals n, lim, w declared ahead of their first use in that order (lim before w gives the retail registers); names and types await human review. */
template <class T> inline const T &Min(const T &a, const T &b) { return (b < a) ? b : a; }
template <class T> inline const T &Max(const T &a, const T &b) { return (a < b) ? b : a; }

struct Sink {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
};

struct Game {
  char pad[0x88];
  Sink *sink;
};

struct Page {
  char pad0[0x38];
  int f38;
  int pad3c;
  int f40;
  char pad44[0x70 - 0x44];
};

struct Obj {
  char pad0[0x44];
  int f44;
  int f48;
  char pad4c[8];
  unsigned char b54;
  char pad55[3];
  int f58;
  int f5c;
  int f60;
  int pad64;
  int f68;
  int pad6c;
  int f70;
  char pad74[0x80 - 0x74];
  Page pages[9];
};

extern Game *DAT_003386b0;
extern "C" void FUN_001180b0(Obj *, Page *, int);

extern "C" void FUN_00117dd0(Obj *o)
{
  if (o->f60 < 0) {
    return;
  }
  o->b54 = 0;
  int n;
  int lim;
  int w;
  n = o->f5c + 1 - o->f60;
  if (n <= 0) {
    n += 9;
  }
  w = o->f48;
  lim = o->f44;
  if (w < 0) {
    lim++;
  }
  if (n < lim) {
    lim = n;
    if (w < 0) {
      w = 0;
    }
  }
  o->f68 = (o->f5c + 10 - lim) % 9;
  o->f58 = o->pages[o->f68].f38;
  int a = o->pages[(o->f68 + 1) % 9].f38;
  if (a < 0) {
    a = -a;
  }
  if (w >= 0) {
    o->f58 = Min(a - 1, o->f58 + w);
  } else {
    o->f58 = Max(o->f58, a + w);
  }
  Page *p = &o->pages[o->f68];
  o->f58 = (o->f58 < p->f38) ? p->f38 : o->f58;
  o->f70 = o->f58 - p->f38;
  o->f70 = Min(o->f70, p->f40 - 1);
  if (o->f58 > p->f38) {
    FUN_001180b0(o, p, 0);
    Sink *s = DAT_003386b0->sink;
    int cnt = o->f58 - p->f38;
    for (int i = 0; i < cnt; i++) {
      s->v10();
    }
  } else {
    o->f68 = o->f68 - 1;
  }
  o->f70 = o->f70 - 1;
}
