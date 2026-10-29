/* HSTMATCH module=hstp_trans_main.prx start=0x0012376c end=0x00123a9c symbol=FUN_0012376c lang=c++ */
/* Clone of src/eboot/init_actor_state_00118598.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (replaces the fm10 Ghidra draft: the compiler's own unroll of the 27-element int and byte loops and the 2x11 int matrix loop, block-scoped loop counters, the sub object read once per float group, an if/else-if chain for the two special modes); exact match verified; names and types await human review. */
struct V4 {
  float x, y, z, w;
};

struct Sub {
  char pad00[0x1d0];
  float f1d0, f1d4, f1d8, f1dc;
  float f1e0, f1e4, f1e8, f1ec;
  char pad1f0[0x1c];
  int f20c;
  int f210;
};

struct Slot {
  char pad00[0x144];
  int f144;
};

struct Glob {
  char pad00[0x70];
  Slot *slots[1];
};

struct Other {
  char pad00[0x198];
  int f198;
};

struct Rec {
  unsigned char first;
  char pad[0x11f];
};

struct Obj {
  char pad00[0x3c];
  int f3c;
  int f40;
  unsigned char f44;
  char pad45[3];
  int arr48[27];
  unsigned char a[27];
  unsigned char b[29];
  Sub *sub;
  unsigned char f0, f1, f2;
  char pad_f3[0x270 - 0xf3];
  int m[2][11];
  unsigned char f2c8, f2c9, f2ca;
  char pad2cb;
  int f2cc;
  int f2d0;
  int f2d4;
  int f2d8;
  unsigned char f2dc;
  unsigned char f2dd;
  char pad2de[0x314 - 0x2de];
  int f314;
  int f318;
};

extern "C" {
extern int DAT_00380b78;
extern int DAT_00380b7c;
extern float DAT_003e47b0;
extern float DAT_003e47b4;
extern float DAT_003e47b8;
extern float DAT_003e47bc;
extern unsigned char DAT_003e19f8;
extern Other *DAT_003e1e04;
extern Glob *DAT_003e19f0;
extern int DAT_003f39a8;
extern Rec DAT_003eabf4[];
void *FUN_00000bcc(unsigned n);
Sub *FUN_0005c2f8(void *p);
void FUN_0005d42c(Sub *s, int n, V4 *v);
void FUN_0005d4fc(Sub *s, int n, V4 *v);
void FUN_0005c8e0(Sub *s);
void FUN_00125680(Obj *o);
void FUN_001256bc(Obj *o);
void FUN_00123adc(Obj *o);
}

extern "C" void FUN_0012376c(Obj *self)
{
  V4 dir;
  V4 col;
  void *mem;
  Sub *s;

  for (int i = 0; i < 27; i++)
    self->arr48[i] = 0;
  self->f3c = 0;
  self->f40 = 0;
  mem = FUN_00000bcc(0x2c0);
  if (mem)
    mem = FUN_0005c2f8(mem);
  self->sub = (Sub *)mem;
  dir.x = 0.0f;
  dir.y = 0.0f;
  dir.w = 0.0f;
  dir.z = -1.0f;
  FUN_0005d42c(self->sub, 1, &dir);
  col.w = 0.0f;
  col.x = 1.0f;
  col.y = 1.0f;
  col.z = 1.0f;
  FUN_0005d4fc(self->sub, 1, &col);
  self->sub->f210 = DAT_00380b78;
  self->sub->f20c = DAT_00380b7c;
  s = self->sub;
  s->f1d0 = DAT_003e47b0;
  s->f1d4 = DAT_003e47b4;
  s->f1d8 = DAT_003e47b8;
  s->f1dc = DAT_003e47bc;
  s = self->sub;
  s->f1e0 = 0.0f;
  s->f1e4 = 0.0f;
  s->f1e8 = -1.0f;
  s->f1ec = 0.0f;
  FUN_0005c8e0(self->sub);
  for (int i = 0; i < 27; i++) {
    self->a[i] = 0;
    self->b[i] = 1;
  }
  self->b[7] = 0;
  self->b[6] = 0;
  self->b[19] = 0;
  self->b[18] = 0;
  self->b[8] = 0;
  self->f0 = 0;
  self->f1 = 0;
  self->f2 = 0;
  FUN_00125680(self);
  FUN_001256bc(self);
  FUN_00123adc(self);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 11; j++)
      self->m[i][j] = 0;
  }
  self->f2c8 = 0;
  self->f2c9 = 0;
  self->f2ca = 0;
  self->f2cc = 0;
  if (DAT_003e19f8 != 0) {
    if (DAT_003e1e04 != 0)
      self->f2cc = DAT_003e1e04->f198;
  }
  self->f2d0 = DAT_003e19f0->slots[self->f2cc]->f144;
  self->f2d4 = -1;
  self->f2d8 = 0;
  self->f2dc = 0;
  self->f2dd = 1;
  if (DAT_003f39a8 == 0x44) {
    self->f2dd = 0;
  } else if (DAT_003f39a8 == 0x31) {
    self->f2dd = 0;
  } else {
    if (DAT_003eabf4[self->f2cc].first != 0)
      self->f2dd = 0;
  }
  self->f314 = 0x1b;
  self->f318 = 0x1b;
  self->f44 = 0;
}
