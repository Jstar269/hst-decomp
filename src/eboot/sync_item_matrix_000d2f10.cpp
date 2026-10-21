/* HSTMATCH module=EBOOT.BIN start=0x000d2f10 end=0x000d31d8 symbol=FUN_000d2f10 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
struct Vec4 { float x, y, z, w; };
#pragma pack(1)
struct Row {
  float x, y, z, w;
  Row() {}
  Row &operator=(Row o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};
struct Mat4 { Row r0, r1, r2, r3; };
#pragma pack()
struct Sub290 { char pad0[0x30]; Mat4 mat; char pad1[0x84 - 0x70]; float scale; };
struct Cam { char pad0[0x20]; Vec4 v20; char pad1[0x290 - 0x30]; Sub290 sub; };
struct Glob { char pad0[0x88]; Cam *cam; };
struct Item { char pad0[0x70]; Mat4 mat; char pad1[0xd0 - 0xb0]; unsigned char fd0; };
struct Node { char pad0[0x70]; float f70; };
struct Self {
  char pad0[0x48]; Node *f48;
  char pad1[0xc0 - 0x4c]; float fc0;
  char pad2[0x180 - 0xc4]; Item *item;
  char pad3[0x194 - 0x184]; int f194;
  unsigned char f198;
};
struct Msg { char pad0[0x20c]; int f20c; int f210; char pad1[0x2c0 - 0x214]; };

extern Glob *DAT_003386b0;
extern "C" {
double __extendsfdf2(float);
double __muldf3(double, double);
float __truncdfsf2(double);
void FUN_00022498(Row *, Row *, float);
void FUN_000e7010(Item *, Row *, Vec4 *);
void FUN_0005b670(Msg *);
void FUN_0005ba00(Msg *, int);
void FUN_0005f1e8(int, Msg *);
}

/* The matrix copy is a chain of nested inline helpers, deepest first: the by-value Row temporaries then sit at
   sp+16..64 in row order (a plain loop or four flat statements reverses them). */
inline void CopyRow0(Item *d, Mat4 *m) { d->mat.r0 = m->r0; }
inline void CopyRow1(Item *d, Mat4 *m) { CopyRow0(d, m); d->mat.r1 = m->r1; }
inline void CopyRow2(Item *d, Mat4 *m) { CopyRow1(d, m); d->mat.r2 = m->r2; }
inline void CopyRow3(Item *d, Mat4 *m) { CopyRow2(d, m); d->mat.r3 = m->r3; }

extern "C" void FUN_000d2f10(Self *self)
{
  Mat4 m;
  Msg e;
  Vec4 pos;
  Node *n = self->f48;
  if (n != 0) {
    n->f70 = (float)(1.5 * (double)self->fc0);
  }
  if (self->item->fd0 != 0) {
    Cam *c = DAT_003386b0->cam;
    Sub290 *s = &c->sub;
    m.r0.x = c->sub.mat.r0.x; m.r0.y = c->sub.mat.r0.y; m.r0.z = c->sub.mat.r0.z; m.r0.w = c->sub.mat.r0.w;
    m.r1.x = c->sub.mat.r1.x; m.r1.y = c->sub.mat.r1.y; m.r1.z = c->sub.mat.r1.z; m.r1.w = c->sub.mat.r1.w;
    m.r2.x = c->sub.mat.r2.x; m.r2.y = c->sub.mat.r2.y; m.r2.z = c->sub.mat.r2.z; m.r2.w = c->sub.mat.r2.w;
    m.r3.x = c->sub.mat.r3.x; m.r3.y = c->sub.mat.r3.y; m.r3.z = c->sub.mat.r3.z; m.r3.w = c->sub.mat.r3.w;
    FUN_00022498(&m.r0, &m.r0, c->sub.scale);
    FUN_00022498(&m.r1, &m.r1, s->scale);
    FUN_00022498(&m.r2, &m.r2, s->scale);
    pos.x = DAT_003386b0->cam->v20.x;
    pos.y = DAT_003386b0->cam->v20.y;
    pos.z = DAT_003386b0->cam->v20.z;
    pos.w = DAT_003386b0->cam->v20.w;
    FUN_000e7010(self->item, &s->mat.r3, &pos);
    CopyRow3(self->item, &m);
  }
  if (self->f198 != 0) {
    FUN_0005b670(&e);
    e.f20c = 500;
    e.f210 = 0;
    FUN_0005f1e8(self->f194, &e);
    FUN_0005ba00(&e, -1);
  }
}
