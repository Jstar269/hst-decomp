/* HSTMATCH module=EBOOT.BIN start=0x00216aa0 end=0x00216bc4 symbol=FUN_00216aa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the 0.3926991f angle step is a non-const float local (value-first mul.s and retail's f0/f1 numbering). */
struct Pt {
  float x;
  float y;
};

struct Sub {
  char pad[0x48];
};

struct Obj {
  unsigned char flag;
  char pad0[3];
  Sub *sub;
  Pt a[16];
  Pt b[16];
};

extern "C" void *FUN_00000bcc(unsigned);
extern "C" Sub *FUN_00050fc0(Sub *);
extern "C" void FUN_00051398(float, Sub *);
extern "C" void FUN_000513fc(Sub *, int);
extern "C" float FUN_0000bc34(float);
extern "C" float FUN_0000bf34(float);

extern "C" Obj *FUN_00216aa0(Obj *self)
{
  self->flag = 0;
  Sub *p = (Sub *)FUN_00000bcc(0x48);
  if (p != 0) p = FUN_00050fc0(p);
  self->sub = p;
  FUN_00051398(3000.0f, p);
  FUN_000513fc(self->sub, 1);
  float step = 0.3926991f;
  for (int i = 0; i < 16; i++) {
    float ang = (float)i * step;
    float s = FUN_0000bc34(ang);
    float c = FUN_0000bf34(ang);
    self->a[i].x = s * 240.0f * 1.45f + 240.0f;
    self->a[i].y = c * 136.0f * 1.45f + 136.0f;
    self->b[i].x = s * 60.0f + 240.0f;
    self->b[i].y = c * 34.0f + 136.0f;
  }
  return self;
}
