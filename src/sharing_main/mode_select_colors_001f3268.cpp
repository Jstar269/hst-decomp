/* HSTMATCH module=hstp_trans_main.prx start=0x001f3268 end=0x001f33a0 symbol=FUN_001f3268 lang=c++ */
/* Clone of src/eboot/mode_select_colors_001e5050.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cols { unsigned c[3]; };
extern Cols DAT_00394074;

struct Eff { virtual void d0(); virtual void Set(int); };
struct Cur { char pad[0x24]; int f24; int f28; };
struct Tgt { int x; };

extern "C" void FUN_001055a4(Tgt *, unsigned);

struct CurRef { Cur *p; void Add(int k) { p->f24 = p->f28 + k; } };
struct TgtRef { Tgt *p; void Color(unsigned c) { FUN_001055a4(p, c); } };

struct Obj {
  char pad0[0x1f8];
  Eff *eff;
  char pad1[0x20c - 0x1fc];
  CurRef cur;
  char pad2[0x220 - 0x210];
  TgtRef tgt;
};

extern "C" void FUN_001f3268(Obj *o, int mode)
{
  CurRef *cr = &o->cur;
  TgtRef *tr = &o->tgt;
  Cols col = DAT_00394074;
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
