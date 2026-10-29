/* HSTMATCH module=EBOOT.BIN start=0x00118598 end=0x001188c8 symbol=FUN_00118598 lang=c++ */
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
extern int DAT_002d9b98;
extern int DAT_002d9b9c;
extern float DAT_0033b470;
extern float DAT_0033b474;
extern float DAT_0033b478;
extern float DAT_0033b47c;
extern unsigned char DAT_003386b8;
extern Other *DAT_00338ac4;
extern Glob *DAT_003386b0;
extern int DAT_0034a678;
extern Rec DAT_003418bc[];
void *FUN_00000bcc(unsigned n);
Sub *FUN_0005b670(void *p);
void FUN_0005c7a4(Sub *s, int n, V4 *v);
void FUN_0005c810(Sub *s, int n, V4 *v);
void FUN_0005bc58(Sub *s);
void FUN_0011a4ac(Obj *o);
void FUN_0011a4e8(Obj *o);
void FUN_00118908(Obj *o);
}

extern "C" void FUN_00118598(Obj *self)
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
    mem = FUN_0005b670(mem);
  self->sub = (Sub *)mem;
  dir.x = 0.0f;
  dir.y = 0.0f;
  dir.w = 0.0f;
  dir.z = -1.0f;
  FUN_0005c7a4(self->sub, 1, &dir);
  col.w = 0.0f;
  col.x = 1.0f;
  col.y = 1.0f;
  col.z = 1.0f;
  FUN_0005c810(self->sub, 1, &col);
  self->sub->f210 = DAT_002d9b98;
  self->sub->f20c = DAT_002d9b9c;
  s = self->sub;
  s->f1d0 = DAT_0033b470;
  s->f1d4 = DAT_0033b474;
  s->f1d8 = DAT_0033b478;
  s->f1dc = DAT_0033b47c;
  s = self->sub;
  s->f1e0 = 0.0f;
  s->f1e4 = 0.0f;
  s->f1e8 = -1.0f;
  s->f1ec = 0.0f;
  FUN_0005bc58(self->sub);
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
  FUN_0011a4ac(self);
  FUN_0011a4e8(self);
  FUN_00118908(self);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 11; j++)
      self->m[i][j] = 0;
  }
  self->f2c8 = 0;
  self->f2c9 = 0;
  self->f2ca = 0;
  self->f2cc = 0;
  if (DAT_003386b8 != 0) {
    if (DAT_00338ac4 != 0)
      self->f2cc = DAT_00338ac4->f198;
  }
  self->f2d0 = DAT_003386b0->slots[self->f2cc]->f144;
  self->f2d4 = -1;
  self->f2d8 = 0;
  self->f2dc = 0;
  self->f2dd = 1;
  if (DAT_0034a678 == 0x44) {
    self->f2dd = 0;
  } else if (DAT_0034a678 == 0x31) {
    self->f2dd = 0;
  } else {
    if (DAT_003418bc[self->f2cc].first != 0)
      self->f2dd = 0;
  }
  self->f314 = 0x1b;
  self->f318 = 0x1b;
  self->f44 = 0;
}
