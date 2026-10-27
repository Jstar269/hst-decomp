/* HSTMATCH module=hstp_trans_main.prx start=0x00209c50 end=0x00209ee4 symbol=FUN_00209c50 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/update_slots_001fb538.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern Game *DAT_003e19f0;
extern Tab *DAT_003f3aac;
extern char DAT_003eaad8;

extern int FUN_001c0bb0(void *, int);
extern void FUN_001c3418(void *, int, int);
extern void FUN_001f2f7c(float, void *, int);
extern void FUN_001f33bc(void *);
extern void FUN_00201ca4(Obj *, Slot *, int, int, int, int);
extern void FUN_00209fb8(Rec *);
extern int FUN_00209fc8(Rec *);


static inline void LoopA(Obj *o, Slot *p)
{
  int i;
  for (i = 0; i < 4; i++) {
    if (p == 0 || p == o->slots[i]) {
      Slot *s = o->slots[i];
      int v = s ? s->f58 : 0;
      if (v != 0) {
        FUN_00201ca4(o, s, o->ids[i], i, 7, 0);
      }
    }
  }
}

static inline void LoopB(Obj *o, Slot *p)
{
  void *g = DAT_003e19f0->fa8;
  int i;
  for (i = 0; i < 4; i++) {
    if (p == 0 || p == o->slots[i]) {
      Slot *s = o->slots[i];
      int v = s ? s->f58 : 0;
      if (v != 0 && g != 0) {
        FUN_001c3418(g, i, 0x81);
      }
    }
  }
}

void FUN_00209c50(Obj *o, int mode)
{
  Rec *r;
  int h;
  float f;
  Tab *tab;
  r = &o->recs[o->f12c8];
  o->f12c4 = 2;
  o->f12cc = 0;
  r->mode = mode;
  h = FUN_00209fc8(r);
  FUN_00209fb8(r);
  if (o->f12c8 == 0) {
    LoopA(o, o->p3c4);
    LoopB(o, o->p3c4);
  } else {
    LoopA(o, o->p3c8);
    LoopB(o, o->p3c8);
  }
  o->f5b8 = FUN_001c0bb0(&DAT_003eaad8, 16);
  tab = DAT_003f3aac;
  if (mode > 0 && mode < 10) {
    f = tab->f[mode];
  } else {
    f = 0.0f;
  }
  FUN_001f2f7c(f, o->f510, h);
  FUN_001f33bc(o->f510);
}
