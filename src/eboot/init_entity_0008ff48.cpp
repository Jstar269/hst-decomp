/* HSTMATCH module=EBOOT.BIN start=0x0008ff48 end=0x00090144 symbol=FUN_0008ff48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: two by-value Vec4 parameters copied by the callee, the 4-float copies written member by member, the empty tag False passed by value to FUN_00091080, the float parameters f12-f14 and a trailing 0.0f forwarded to FUN_000c24f0); names and types await human review. */
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct False {};

struct Sub {
  int x;
  int y;
  int z;
};

struct Obj {
  char pad0[4];
  int f4;
  char pad1[0x10 - 8];
  Vec4 v10;
  char pad2[0x230 - 0x20];
  int f230;
  int f234;
  int f238;
  int f23c;
  unsigned char f240;
  char pad3[3];
  float f244;
  float f248;
  char pad4[4];
  Vec4 f250;
  int f260;
  int f264;
  int f268;
  Sub s26c;
  Sub s278;
  unsigned char f284;
  char pad7[3];
  int f288;
  char pad8[4];
  char s290[16];
};

struct Ctx {
  char pad[0x3c];
  int f3c;
};

extern "C" {
extern float DAT_003412dc;
extern float DAT_003412e0;
extern int DAT_00338b44;
extern int DAT_00338c20;
extern int DAT_0033b460;
extern Ctx *DAT_003386b0;
void FUN_000c24f0(Obj *, Vec4 *, Vec4 *, int *, float, float, float, float);
void FUN_000550c8(void *, Vec4 *);
void FUN_00091080(Sub *, int, False);
void FUN_00090214(Obj *, int, int);
void FUN_000dc90c(int, int, int);
void FUN_000fb074(int, int, int);
void FUN_0011a16c(int, int, int);
void FUN_0008e984(Obj *, int);
void FUN_0009044c(Obj *, unsigned char);
}

extern "C" void FUN_0008ff48(Obj *self, int p2, int p3, Vec4 pos, Vec4 vel, int p6, int p7, unsigned char p8, int *ex0, unsigned char ex4, float fa, float fb, float fc)
{
  FUN_000c24f0(self, &pos, &vel, ex0, fa, fb, fc, 0.0f);
  self->f284 = 0;
  self->f288 = 0;
  self->f230 = p2;
  self->f234 = p3;
  self->f238 = p6;
  self->f23c = p7;
  self->f240 = p8;
  self->f250.x = vel.x;
  self->f250.y = vel.y;
  self->f250.z = vel.z;
  self->f250.w = vel.w;
  if (self->f23c == 6) {
    self->f244 = DAT_003412dc;
    self->f248 = DAT_003412e0;
  } else {
    self->f244 = 1.0f;
    self->f248 = 0.0f;
  }
  self->f268 = 0;
  Vec4 tmp;
  tmp.x = self->v10.x;
  tmp.y = self->v10.y;
  tmp.z = self->v10.z;
  tmp.w = self->v10.w;
  FUN_000550c8(self->s290, &tmp);
  FUN_00091080(&self->s26c, self->s26c.y, False());
  FUN_00091080(&self->s278, self->s278.y, False());
  FUN_00090214(self, self->f268, self->f4);
  FUN_000dc90c(DAT_00338b44, self->f230, self->f234);
  FUN_000fb074(DAT_00338c20, self->f230, self->f234);
  FUN_0011a16c(DAT_0033b460, self->f230, self->f234);
  FUN_0008e984(self, 4);
  if (DAT_003386b0->f3c == 7)
    self->f264 = 1;
  FUN_0009044c(self, ex4);
}
