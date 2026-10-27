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

extern "C" void FUN_00091b48(Obj *self, int p2, int p3, Vec4 pos, Vec4 vel, int p6, int p7, unsigned char p8, int *ex0, unsigned char ex4, float fa, float fb, float fc)
{
  FUN_000c5cc0(self, &pos, &vel, ex0, fa, fb, fc, 0.0f);
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
    self->f244 = DAT_003ea61c;
    self->f248 = DAT_003ea620;
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
  FUN_00055be8(self->s290, &tmp);
  FUN_00092d18(&self->s26c, self->s26c.y, False());
  FUN_00092d18(&self->s278, self->s278.y, False());
  FUN_00091e14(self, self->f268, self->f4);
  FUN_000e0a10(DAT_003e1e84, self->f230, self->f234);
  FUN_001007b0(DAT_003e1f60, self->f230, self->f234);
  FUN_00125340(DAT_003e47a0, self->f230, self->f234);
  FUN_000903c8(self, 4);
  if (DAT_003e19f0->f3c == 7)
    self->f264 = 1;
  FUN_000920b8(self, ex4);
}
