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
  int unk04;
  char pad1[0x10 - 8];
  Vec4 pos;   /* 0x10 */
  char pad2[0x230 - 0x20];
  int unk230;
  int unk234;
  int unk238;
  int kind;
  unsigned char unk240;
  char pad3[3];
  float unk244;
  float unk248;
  char pad4[4];
  Vec4 vel;   /* 0x250 copy of the velocity argument */
  int unk260;
  int unk264;
  int unk268;
  Sub sub26c;
  Sub sub278;
  unsigned char unk284;
  char pad7[3];
  int unk288;
  char pad8[4];
  char unk290[16];
};

struct Ctx {
  char pad[0x3c];
  int mode;
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

/* Initialises the entity at pos with velocity vel: stores the creation arguments, picks the two float
   parameters by whether the kind (p7) is 6, snapshots the position for the tracker and notifies the registries. */
extern "C" void FUN_0008ff48(Obj *self, int p2, int p3, Vec4 pos, Vec4 vel, int p6, int p7, unsigned char p8, int *ex0, unsigned char ex4, float fa, float fb, float fc)
{
  FUN_000c24f0(self, &pos, &vel, ex0, fa, fb, fc, 0.0f);
  self->unk284 = 0;
  self->unk288 = 0;
  self->unk230 = p2;
  self->unk234 = p3;
  self->unk238 = p6;
  self->kind = p7;
  self->unk240 = p8;
  self->vel.x = vel.x;
  self->vel.y = vel.y;
  self->vel.z = vel.z;
  self->vel.w = vel.w;
  if (self->kind == 6) {
    self->unk244 = DAT_003412dc;
    self->unk248 = DAT_003412e0;
  } else {
    self->unk244 = 1.0f;
    self->unk248 = 0.0f;
  }
  self->unk268 = 0;
  Vec4 tmp;
  tmp.x = self->pos.x;
  tmp.y = self->pos.y;
  tmp.z = self->pos.z;
  tmp.w = self->pos.w;
  FUN_000550c8(self->unk290, &tmp);
  FUN_00091080(&self->sub26c, self->sub26c.y, False());
  FUN_00091080(&self->sub278, self->sub278.y, False());
  FUN_00090214(self, self->unk268, self->unk04);
  FUN_000dc90c(DAT_00338b44, self->unk230, self->unk234);
  FUN_000fb074(DAT_00338c20, self->unk230, self->unk234);
  FUN_0011a16c(DAT_0033b460, self->unk230, self->unk234);
  FUN_0008e984(self, 4);
  if (DAT_003386b0->mode == 7)
    self->unk264 = 1;
  FUN_0009044c(self, ex4);
}
