/* HSTMATCH module=hstp_trans_main.prx start=0x00100110 end=0x001002d0 symbol=FUN_00100110 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed structs, rolled 16-iteration record init (opt_unroll_loops off, pointer walked by 0x40; same recipe as init_state_records_000fffc0.cpp), the f4e8 == 1 flag hoisted before the loop, float product kept in one local, unsigned char gate ok = (b != 0) ^ 1, index as nested ternary (flag != 0 ? (p == 0 ? 0 : p->f198) : 0); matching idiom: the two arms of the final compare repeat the same `if (ok)` store block, the object pointer is loaded before the ok test; exact match verified; names and types await human review. */
#pragma opt_unroll_loops off
typedef unsigned char uchar;
typedef struct { float x, y, z, w; } Vec4;

typedef struct {
  uchar f0;
  int f4, f8, fc, f10, f14;
  char pad18[8];
  int f20, f24, f28;
  float f2c;
  int f30;
  char pad34[0xc];
} Rec;

typedef struct {
  char pad0[0xa0];
  Rec recs[16];
} Obj88;

typedef struct {
  uchar b0;
  uchar b1;
} Flags;

typedef struct {
  char pad0[0x6c];
  int f6c;
  char pad70[0x10];
  Flags *f80;
  char pad84[4];
  Obj88 *f88;
} Self;

typedef struct {
  char pad0[0x20];
  Vec4 f20;
} Blk;

typedef struct {
  char pad0[0x144];
  int f144;
  char pad148[0x4e8 - 0x148];
  int f4e8;
} Player;

typedef struct {
  char pad0[0x3c];
  int f3c;
  char pad40[0x30];
  Player *players[6];
  Blk *f88;
} Mgr;

typedef struct {
  char pad0[0x198];
  int f198;
} Cur;

typedef struct {
  char pad0[0x45];
  uchar b45;
} Sys;

typedef struct {
  char pad0[0x44];
  float f44;
} Out;

extern Mgr *DAT_003e19f0;
extern uchar DAT_003e19f8;
extern Cur *DAT_003e1e04;
extern Sys *DAT_003e1e84;
extern Out *DAT_003e95c4;
extern float FUN_00022500(Vec4 *, Vec4 *);
extern float FUN_00022e6c(float);
extern void FUN_000f6c38(int, int, int);

void FUN_00100110(Self *self, int param_2, int param_3)
{
  int mode1;
  unsigned i;
  char *p;
  Vec4 v;
  float scaled;
  uchar ok;
  int idx;

  mode1 = DAT_003e19f0->players[param_3]->f4e8 == 1;
  i = 0;
  p = (char *)self->f88;
  do {
    Rec *r = (Rec *)(p + 0xa0);
    r->f0 = 0;
    r->f4 = 0x10;
    r->f8 = 0;
    r->fc = -1;
    r->f10 = 0;
    r->f14 = 0;
    r->f20 = 0;
    r->f24 = 0;
    r->f28 = 0;
    r->f2c = 1.0f;
    r->f30 = 0;
    i++;
    p += 0x40;
  } while (i < 16);
  v.x = DAT_003e19f0->f88->f20.x;
  v.y = DAT_003e19f0->f88->f20.y;
  v.z = DAT_003e19f0->f88->f20.z;
  v.w = DAT_003e19f0->f88->f20.w;
  scaled = FUN_00022e6c(FUN_00022500(&v, &v)) * 3.6f;
  if (DAT_003e19f0->f3c != 7) {
    DAT_003e95c4->f44 = scaled;
  }
  if (mode1) {
    FUN_000f6c38(self->f6c, (int)scaled, param_2);
  }
  ok = (DAT_003e1e84->b45 != 0) ^ 1;
  if (ok) {
    idx = DAT_003e19f8 != 0 ? (DAT_003e1e04 == 0 ? 0 : DAT_003e1e04->f198) : 0;
    if (param_2 != DAT_003e19f0->players[idx]->f144) {
      Flags *f = self->f80;
      if (ok) {
        f->b0 = 0;
        f->b1 = 1;
      }
    } else {
      Flags *f = self->f80;
      if (ok) {
        f->b0 = 0;
        f->b1 = 1;
      }
    }
  }
}
