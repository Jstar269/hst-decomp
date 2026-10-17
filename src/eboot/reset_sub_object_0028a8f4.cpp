/* HSTMATCH module=EBOOT.BIN start=0x0028a8f4 end=0x0028a9ac symbol=FUN_0028a8f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub {
  char pad0[0xc0];
  unsigned char c0;
  char pad1[3];
  float c4;
  char pad2[4];
  float cc;
  float d0;
};

struct Self {
  char pad[0x74];
  Sub *sub;
};

extern "C" void FUN_00057b58(float, Sub *, int, int);
extern "C" void FUN_00058ec4(float, Sub *, int);
extern "C" void FUN_00058f38(float, Sub *, int);
extern "C" void FUN_0005f110(float, Sub *);
extern "C" void FUN_00058ddc(Sub *, int, int);
extern "C" void FUN_00059084(Sub *, int);

extern "C" void FUN_0028a8f4(Self *self, int a1, int a2)
{
  FUN_00057b58(0.0f, self->sub, 0, a1);
  Sub *p = self->sub;
  FUN_00058ec4(1.0f, p, -1);
  p->c4 = 1.0f;
  p = self->sub;
  FUN_00058f38(0.0f, p, -1);
  FUN_0005f110(0.0f, p);
  p = self->sub;
  FUN_00058ddc(p, a2, -1);
  p->c0 = a2;
  p = self->sub;
  FUN_00059084(p, -1);
  p->d0 = p->c4;
}
