/* HSTMATCH module=EBOOT.BIN start=0x0017ce84 end=0x0017cfb4 symbol=FUN_0017ce84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define ITEM_FLAG_BIT5 0x20 /* when set, the finish call and the part call are skipped */

struct Sub {
  virtual void d0();
  virtual void d1();
  virtual void m2(int);
};
struct Part { char pad[0x8c]; int v8c; };
struct Item {
  char pad0[0x10];
  Sub sub;
  char pad1[0x60 - 0x10 - sizeof(Sub)];
  Part *part60;
  Part *part64;
  Part *part68;
  char pad2[0x74 - 0x6c];
  Part *part74;
  char pad3[0x84 - 0x78];
  char flags;
};
struct Mgr {
  char pad0[4];
  int cur;         /* index of the selected item */
  Item **items;
  char pad1[0x50 - 0x0c];
  int count;
  char pad2[0x58 - 0x54];
  unsigned char unk58;
  unsigned char unk59;
};

extern "C" void FUN_000943d0(Sub *, char);
extern "C" void FUN_00094424(Sub *);
extern "C" void FUN_0005f1e8(Part *, int);
extern "C" int FUN_0016bc70(void);
extern "C" int FUN_0017970c(int);

/* Finishes the selected item when it has its three parts loaded (and at least two items exist). */
extern "C" void FUN_0017ce84(Mgr *m)
{
  if (m->unk58 == 0 && m->count >= 2 && m->unk59 != 0) {
    Item *o = m->items[m->cur];
    if (o->part68 != 0 && o->part60 != 0 && o->part64 != 0 && o->part68->v8c != 0 && o->part60->v8c != 0 && o->part64->v8c != 0) {
      int ok = 1;
      if (o->flags & ITEM_FLAG_BIT5) ok = 0;
      FUN_000943d0(&o->sub, 5);
      o->sub.m2(0);
      Part *q = o->part74;
      if (q != 0 && q->v8c != 0 && ok) {
        FUN_0005f1e8(q, FUN_0017970c(FUN_0016bc70()));
      }
      if (ok) {
        FUN_00094424(&o->sub);
      }
    }
  }
}
