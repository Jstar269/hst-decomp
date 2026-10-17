/* HSTMATCH module=hstp_trans_main.prx start=0x00189578 end=0x001896a8 symbol=FUN_00189578 lang=c++ */
/* Clone of src/eboot/finish_selected_item_0017ce84.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub {
  virtual void d0();
  virtual void d1();
  virtual void m2(int);
};
struct Part { char pad[0x8c]; int v8c; };
struct Obj {
  char pad0[0x10];
  Sub sub;
  char pad1[0x60 - 0x10 - sizeof(Sub)];
  Part *p60;
  Part *p64;
  Part *p68;
  char pad2[0x74 - 0x6c];
  Part *p74;
  char pad3[0x84 - 0x78];
  char flags;
};
struct Mgr {
  char pad0[4];
  int idx;
  Obj **items;
  char pad1[0x50 - 0x0c];
  int n;
  char pad2[0x58 - 0x54];
  unsigned char f58;
  unsigned char f59;
};

extern "C" void FUN_000962f4(Sub *, char);
extern "C" void FUN_00096348(Sub *);
extern "C" void FUN_0005ffd8(Part *, int);
extern "C" int FUN_00177e98(void);
extern "C" int FUN_00185e00(int);

extern "C" void FUN_00189578(Mgr *m)
{
  if (m->f58 == 0 && m->n >= 2 && m->f59 != 0) {
    Obj *o = m->items[m->idx];
    if (o->p68 != 0 && o->p60 != 0 && o->p64 != 0 && o->p68->v8c != 0 && o->p60->v8c != 0 && o->p64->v8c != 0) {
      int ok = 1;
      if (o->flags & 0x20) ok = 0;
      FUN_000962f4(&o->sub, 5);
      o->sub.m2(0);
      Part *q = o->p74;
      if (q != 0 && q->v8c != 0 && ok) {
        FUN_0005ffd8(q, FUN_00185e00(FUN_00177e98()));
      }
      if (ok) {
        FUN_00096348(&o->sub);
      }
    }
  }
}
