/* HSTMATCH module=EBOOT.BIN start=0x001e5050 end=0x001e5188 symbol=FUN_001e5050 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cols { unsigned c[3]; };
extern Cols DAT_002ec15c;

struct Eff { virtual void d0(); virtual void Set(int); };
struct Cur { char pad[0x24]; int f24; int f28; };
struct Tgt { int x; };

extern "C" void FUN_000ffc70(Tgt *, unsigned);

struct CurRef { Cur *p; void Add(int k) { p->f24 = p->f28 + k; } };
struct TgtRef { Tgt *p; void Color(unsigned c) { FUN_000ffc70(p, c); } };

struct Obj {
  char pad0[0x1f8];
  Eff *eff;
  char pad1[0x20c - 0x1fc];
  CurRef cur;
  char pad2[0x220 - 0x210];
  TgtRef tgt;
};

extern "C" void FUN_001e5050(Obj *o, int mode)
{
  CurRef *cr = &o->cur;
  TgtRef *tr = &o->tgt;
  Cols col = DAT_002ec15c;
  o->eff->Set(1);
  switch (mode) {
  case 1:
    o->eff->Set(0);
    cr->Add(0);
    tr->Color(col.c[0]);
    break;
  case 2:
    o->eff->Set(0);
    cr->Add(2);
    tr->Color(col.c[2]);
    break;
  case 3:
    o->eff->Set(0);
    cr->Add(1);
    tr->Color(col.c[1]);
    break;
  }
}
