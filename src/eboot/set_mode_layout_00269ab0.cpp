/* HSTMATCH module=EBOOT.BIN start=0x00269ab0 end=0x0026a0bc symbol=FUN_00269ab0 lang=c++ rodata=0x2ca8d8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0r. Matching idioms: the centring helper reads the width through an inline getter (so x0 is loaded twice, as in retail) and keeps the shift delta in a short local; the jump table is placed with rodata=0x2ca8d8; modes 1, 3 and 8 fall out of the switch. */
struct VC {
  virtual void v0(); virtual void v1(int); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
  virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
};
struct Item {
  char pad0[4];
  short x0;
  short pad6;
  short x1;
  short Width() const { return x1 - x0; }
};
struct Root { char pad[0x60]; float f60; };
struct Holder { Root *p; };

struct Obj {
  char pad0[4];
  Holder *p4;
  char pad8[0x55 - 8];
  unsigned char f55;
  char pad56[2];
  VC *p58;
  int mode;
  int tab[12];
  VC *p90;
  VC *p94;
  VC *p98;
  Item *p9c;
  Item *pa0;
  Item *pa4;
  Item *pa8;
  Item *pac;
  Item *pb0;
  short pb4;
  short pb6;
  short pb8;
  short pba;
  char padbc[0xf4 - 0xbc];
  Item *pf4;
  Item *pf8;
  char padfc[4];
  VC *p100;
};

extern "C" {
void FUN_000ffb3c(Item *, int);
void FUN_00103480(Obj *);
void FUN_00103628(Obj *, int);
void FUN_0010b6d4(VC *, int, int);
void FUN_0010b8cc(VC *, int, int);
}

static inline short Center(Item *s)
{
  return (s->x0 + s->x1) / 2;
}

static inline void SetCenter(Item *s, short cx)
{
  short w = s->Width();
  short nx = cx - w / 2;
  short ox = s->x0;
  short d = nx - ox;
  s->x0 = nx;
  s->x1 = s->x1 + d;
}

extern "C" void FUN_00269ab0(Obj *o, unsigned mode)
{
  o->mode = mode;
  switch (mode) {
  case 0:
  case 2:
    FUN_00103628(o, 0);
    o->p58->v15();
    o->p58->v11();
    o->p58->v1(1);
    SetCenter(o->pa0, Center(o->p9c));
    SetCenter(o->pa4, Center(o->p9c));
    SetCenter(o->pac, Center(o->p9c));
    SetCenter(o->pb0, Center(o->p9c));
    o->p4->p->f60 = -480.0f;
    FUN_00103480(o);
    if (o->mode == 2) {
      FUN_000ffb3c(o->p9c, 1);
      FUN_000ffb3c(o->pa0, 1);
      FUN_000ffb3c(o->pa4, 1);
      return;
    }
    FUN_000ffb3c(o->pa8, 1);
    FUN_000ffb3c(o->pac, 1);
    FUN_000ffb3c(o->pb0, 1);
    break;
  case 4:
    o->p94->v1(0);
    o->p98->v1(1);
    o->p58->v1(0);
    o->p58->v15();
    FUN_0010b6d4(o->p58, 0, 2);
    FUN_0010b8cc(o->p58, o->tab[o->mode], 0);
    o->p58->v11();
    o->p90->v1(0);
    break;
  case 5:
    o->p58->v1(1);
    break;
  case 6:
    FUN_000ffb3c(o->p9c, 1);
    FUN_000ffb3c(o->pa0, 1);
    FUN_000ffb3c(o->pa4, 1);
    FUN_000ffb3c(o->pa8, 0);
    SetCenter(o->pac, o->pba);
    SetCenter(o->pb0, o->pba);
    break;
  case 7:
    o->p94->v1(1);
    o->p98->v1(0);
    FUN_000ffb3c(o->pf4, 0);
    o->p100->v1(0);
    FUN_000ffb3c(o->pf8, 0);
    o->p58->v1(0);
    o->p58->v15();
    FUN_0010b6d4(o->p58, 3, 5);
    FUN_0010b8cc(o->p58, o->tab[o->mode], 0);
    o->p58->v11();
    o->p90->v1(0);
    break;
  case 9:
    FUN_000ffb3c(o->p9c, 0);
    FUN_000ffb3c(o->pa8, 1);
    FUN_000ffb3c(o->pac, 1);
    FUN_000ffb3c(o->pb0, 1);
    SetCenter(o->pa0, o->pb4);
    SetCenter(o->pa4, o->pb4);
    break;
  case 10:
    o->p58->v1(1);
    o->f55 = 1;
    break;
  }
}
