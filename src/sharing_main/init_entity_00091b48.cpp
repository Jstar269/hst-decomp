/* HSTMATCH module=hstp_trans_main.prx start=0x00091b48 end=0x00091d44 symbol=FUN_00091b48 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/init_entity_0008ff48.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
extern float DAT_003ea61c;
extern float DAT_003ea620;
extern int DAT_003e1e84;
extern int DAT_003e1f60;
extern int DAT_003e47a0;
extern Ctx *DAT_003e19f0;
void FUN_000c5cc0(Obj *, Vec4 *, Vec4 *, int *, float, float, float, float);
void FUN_00055be8(void *, Vec4 *);
void FUN_00092d18(Sub *, int, False);
void FUN_00091e14(Obj *, int, int);
void FUN_000e0a10(int, int, int);
void FUN_001007b0(int, int, int);
void FUN_00125340(int, int, int);
void FUN_000903c8(Obj *, int);
void FUN_000920b8(Obj *, unsigned char);
}

/* Initialises the entity at pos with velocity vel: stores the creation arguments, picks the two float
   parameters by whether the kind (p7) is 6, snapshots the position for the tracker and notifies the registries. */
extern "C" void FUN_00091b48(Obj *self, int p2, int p3, Vec4 pos, Vec4 vel, int p6, int p7, unsigned char p8, int *ex0, unsigned char ex4, float fa, float fb, float fc)
{
  FUN_000c5cc0(self, &pos, &vel, ex0, fa, fb, fc, 0.0f);
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
    self->unk244 = DAT_003ea61c;
    self->unk248 = DAT_003ea620;
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
  FUN_00055be8(self->unk290, &tmp);
  FUN_00092d18(&self->sub26c, self->sub26c.y, False());
  FUN_00092d18(&self->sub278, self->sub278.y, False());
  FUN_00091e14(self, self->unk268, self->unk04);
  FUN_000e0a10(DAT_003e1e84, self->unk230, self->unk234);
  FUN_001007b0(DAT_003e1f60, self->unk230, self->unk234);
  FUN_00125340(DAT_003e47a0, self->unk230, self->unk234);
  FUN_000903c8(self, 4);
  if (DAT_003e19f0->mode == 7)
    self->unk264 = 1;
  FUN_000920b8(self, ex4);
}
