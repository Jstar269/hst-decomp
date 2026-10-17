/* HSTMATCH module=hstp_trans_main.prx start=0x001a0788 end=0x001a0840 symbol=FUN_001a0788 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void *FUN_000114c0(void *, int, int);

struct Entry {
  char pad[16];
  short a;
  short b;
};

struct Obj {
  char hdr[20];
  Entry e[4];
  char tail[12];
};

extern "C" Obj *FUN_001a0788(Obj *o)
{
  Entry *p = o->e;
  do {
    FUN_000114c0(p, 0, 20);
    p->a = -1;
    p->b = -1;
    p++;
  } while (p < o->e + 4);
  FUN_000114c0(o, 0, 112);
  for (int i = 0; i < 4; i++) {
    Entry *e = &o->e[i];
    FUN_000114c0(e, 0, 20);
    e->a = -1;
    e->b = -1;
  }
  return o;
}
