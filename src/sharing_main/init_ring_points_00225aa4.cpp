/* HSTMATCH module=hstp_trans_main.prx start=0x00225aa4 end=0x00225bc8 symbol=FUN_00225aa4 lang=c++ */
/* Clone of src/eboot/init_ring_points_00216aa0.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" Sub *FUN_000518d4(Sub *);
extern "C" void FUN_00051d38(float, Sub *);
extern "C" void FUN_00051d9c(Sub *, int);
extern "C" float FUN_0000bc4c(float);
extern "C" float FUN_0000bf4c(float);

extern "C" Obj *FUN_00225aa4(Obj *self)
{
  self->flag = 0;
  Sub *p = (Sub *)FUN_00000bcc(0x48);
  if (p != 0) p = FUN_000518d4(p);
  self->sub = p;
  FUN_00051d38(3000.0f, p);
  FUN_00051d9c(self->sub, 1);
  float step = 0.3926991f;
  for (int i = 0; i < 16; i++) {
    float ang = (float)i * step;
    float s = FUN_0000bc4c(ang);
    float c = FUN_0000bf4c(ang);
    self->a[i].x = s * 240.0f * 1.45f + 240.0f;
    self->a[i].y = c * 136.0f * 1.45f + 136.0f;
    self->b[i].x = s * 60.0f + 240.0f;
    self->b[i].y = c * 34.0f + 136.0f;
  }
  return self;
}
