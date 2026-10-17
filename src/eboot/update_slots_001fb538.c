/* HSTMATCH module=EBOOT.BIN start=0x001fb538 end=0x001fb7cc symbol=FUN_001fb538 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0. Matching idioms: the two four-slot loops are static inline helpers called once per branch of the f12c8 test; the record pointer is computed before the f12c4 store; the table pointer is read into a local before the mode range test; the global in the second helper is declared before the loop index. */
typedef struct Slot { char pad[0x58]; int f58; } Slot;
typedef struct Rec { char pad[0x1c]; int mode; char pad2[0xe4 - 0x20]; } Rec;
typedef struct Obj Obj;
typedef struct Game { char pad[0xa8]; void *fa8; } Game;
typedef struct Tab { char pad[0x2c]; float f[10]; } Tab;

struct Obj {
  char pad0[0x3a0];
  Slot *slots[4];
  int ids[4];
  char pad3c0[4];
  Slot *p3c4;
  Slot *p3c8;
  char pad3cc[0x510 - 0x3cc];
  void *f510;
  char pad514[0x5b8 - 0x514];
  int f5b8;
  char pad5bc[0x10fc - 0x5bc];
  Rec recs[2];
  int f12c4;
  int f12c8;
  int f12cc;
};

extern Game *DAT_003386b0;
extern Tab *DAT_0034a77c;
extern char DAT_0034179c;

extern int FUN_001b2af0(void *, int);
extern void FUN_001b5764(void *, int, int);
extern void FUN_001e4d64(float, void *, int);
extern void FUN_001e51a4(void *);
extern void FUN_001f37e4(Obj *, Slot *, int, int, int, int);
extern void FUN_001fb8a0(Rec *);
extern int FUN_001fb8b0(Rec *);


static inline void LoopA(Obj *o, Slot *p)
{
  int i;
  for (i = 0; i < 4; i++) {
    if (p == 0 || p == o->slots[i]) {
      Slot *s = o->slots[i];
      int v = s ? s->f58 : 0;
      if (v != 0) {
        FUN_001f37e4(o, s, o->ids[i], i, 7, 0);
      }
    }
  }
}

static inline void LoopB(Obj *o, Slot *p)
{
  void *g = DAT_003386b0->fa8;
  int i;
  for (i = 0; i < 4; i++) {
    if (p == 0 || p == o->slots[i]) {
      Slot *s = o->slots[i];
      int v = s ? s->f58 : 0;
      if (v != 0 && g != 0) {
        FUN_001b5764(g, i, 0x81);
      }
    }
  }
}

void FUN_001fb538(Obj *o, int mode)
{
  Rec *r;
  int h;
  float f;
  Tab *tab;
  r = &o->recs[o->f12c8];
  o->f12c4 = 2;
  o->f12cc = 0;
  r->mode = mode;
  h = FUN_001fb8b0(r);
  FUN_001fb8a0(r);
  if (o->f12c8 == 0) {
    LoopA(o, o->p3c4);
    LoopB(o, o->p3c4);
  } else {
    LoopA(o, o->p3c8);
    LoopB(o, o->p3c8);
  }
  o->f5b8 = FUN_001b2af0(&DAT_0034179c, 16);
  tab = DAT_0034a77c;
  if (mode > 0 && mode < 10) {
    f = tab->f[mode];
  } else {
    f = 0.0f;
  }
  FUN_001e4d64(f, o->f510, h);
  FUN_001e51a4(o->f510);
}
