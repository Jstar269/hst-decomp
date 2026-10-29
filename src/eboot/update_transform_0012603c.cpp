/* HSTMATCH module=EBOOT.BIN start=0x0012603c end=0x00126304 symbol=FUN_0012603c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Rebuilds the two 16-float blocks at self+0x40 and self+0x60 (plus the scalar at self+0x80) from one of
   two parameter records: p->f4c selects the first path, otherwise p->f56/p->f57 drive the second. Each
   path builds a local helper object with a fluent call chain, then copies the two result vectors out.
   Layout notes: Vec4 is the PSP 16-byte-aligned float4 (mwcc rounds every such local slot to 16 bytes,
   which is what produces the 384-byte frame and the descending placement of a, d0, b, d1, d2, v1, v2);
   the second helper's 0x44..0x54 fields must stay four separate floats because a 16-aligned Vec4 there
   would move to +0x50 and change the frame. `float h = self->f80` exists because retail loads that
   scalar once before the stores and keeps it in f3 until the +0x54 store. */

struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct BuilderA {
  char pad0[0x64];
  char f64;
  char f65;
  char pad1[0x0a];
  Vec4 out70;
  Vec4 out80;
  char pad2[0x28];
  float fB8;
  float fBC;
};

struct BuilderB {
  Vec4 m00;
  Vec4 m10;
  Vec4 m20;
  Vec4 m30;
  float m40;
  float m44x;
  float m44y;
  float m44z;
  float m44w;
  float m54;
};

struct Param {
  char pad0[0x20];
  float f20;
  float f24;
  float f28;
  float f2c;
  float f30;
  char pad1[0x18];
  char f4c;
  char pad2[0x09];
  char f56;
  char f57;
};

struct Self {
  char pad0[0x40];
  float f40;
  float f44;
  float f48;
  float f4c;
  char pad1[0x10];
  float f60;
  float f64;
  float f68;
  float f6c;
  char pad2[0x10];
  float f80;
};

extern char DAT_002da1f8[];
extern char DAT_002da1fc[];
extern char DAT_002da200[];
extern unsigned char DAT_002da204;
extern unsigned char DAT_002da205;
extern char DAT_002da208[];
extern char DAT_002da20c[];
extern int DAT_00340284;

extern "C" void FUN_000609f8(Self *self);
extern "C" void FUN_00131198(void *buf, int table, int value, int flags);
extern "C" BuilderA *FUN_001669dc(BuilderA *a);
extern "C" BuilderA *FUN_00166a04(BuilderA *a, int flags);
extern "C" void FUN_00166af4(BuilderA *a, Vec4 *v);
extern "C" void FUN_00166b38(BuilderA *a, Vec4 *v);
extern "C" void FUN_00166bac(BuilderA *a, void *p);
extern "C" void FUN_00166b7c(BuilderA *a, void *p);
extern "C" void FUN_00166ba0(BuilderA *a, float *p);
extern "C" void FUN_00166bb8(BuilderA *a, float *p, void *q, void *r);
extern "C" void FUN_00166c04(BuilderA *a, void *p, void *q);
extern "C" void FUN_00166c28(BuilderA *a);
extern "C" void FUN_001672a4(BuilderA *a);
extern "C" BuilderB *FUN_001677b4(BuilderB *b);
extern "C" BuilderB *FUN_001677dc(BuilderB *b, int flags);
extern "C" void FUN_0016787c(BuilderB *b);

extern "C" void FUN_0012603c(Self *self, Param *p)
{
  if (p == 0) {
    return;
  }
  BuilderA a;
  Vec4 d0;
  BuilderB b;
  Vec4 d1;
  Vec4 d2;
  Vec4 v1;
  Vec4 v2;
  if (p->f4c != 0) {
    FUN_001669dc(&a);
    FUN_00131198(&d0, DAT_00340284, p->f4c, -1);
    a.fBC = self->f80;
    v1.x = self->f40;
    v1.y = self->f44;
    v1.z = self->f48;
    v1.w = self->f4c;
    FUN_00166af4(&a, &v1);
    v2.x = self->f60;
    v2.y = self->f64;
    v2.z = self->f68;
    v2.w = self->f6c;
    FUN_00166b38(&a, &v2);
    FUN_00166bac(&a, DAT_002da1f8);
    FUN_00166b7c(&a, &d0);
    FUN_00166ba0(&a, &a.fBC);
    a.fB8 = 1.5f * a.fBC;
    FUN_00166bb8(&a, &a.fB8, DAT_002da1fc, DAT_002da200);
    a.f65 = DAT_002da204;
    a.f64 = DAT_002da205;
    FUN_00166c04(&a, DAT_002da208, DAT_002da20c);
    FUN_00166c28(&a);
    FUN_001672a4(&a);
    self->f40 = a.out70.x;
    self->f44 = a.out70.y;
    self->f48 = a.out70.z;
    self->f4c = a.out70.w;
    self->f60 = a.out80.x;
    self->f64 = a.out80.y;
    self->f68 = a.out80.z;
    self->f6c = a.out80.w;
    FUN_000609f8(self);
    FUN_00166a04(&a, -1);
    return;
  }
  if (p->f56 == 0) {
    return;
  }
  if (p->f57 == 0) {
    return;
  }
  FUN_001677b4(&b);
  FUN_00131198(&d1, DAT_00340284, p->f56, -1);
  FUN_00131198(&d2, DAT_00340284, p->f57, -1);
  float h = self->f80;
  b.m00 = d1;
  b.m10 = d2;
  b.m40 = p->f30;
  b.m54 = h;
  b.m44x = p->f20;
  b.m44y = p->f24;
  b.m44z = p->f28;
  b.m44w = p->f2c;
  FUN_0016787c(&b);
  self->f40 = b.m20.x;
  self->f44 = b.m20.y;
  self->f48 = b.m20.z;
  self->f4c = b.m20.w;
  self->f60 = b.m30.x;
  self->f64 = b.m30.y;
  self->f68 = b.m30.z;
  self->f6c = b.m30.w;
  FUN_000609f8(self);
  FUN_001677dc(&b, -1);
}