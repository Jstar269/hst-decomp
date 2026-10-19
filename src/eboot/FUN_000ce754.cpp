/* HSTMATCH module=EBOOT.BIN start=0x000ce754 end=0x000ce820 symbol=FUN_000ce754 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Mat4 { Vec4 r0, r1, r2, r3; };

struct Fx {
  void *vptr;
  int f4;
  char pad8[8];
  Mat4 m;
  int f50;
  float f54;
  float f58;
  float f5c;
  unsigned char f60;
  char pad61[0x70 - 0x61];
};

extern "C" {
extern char DAT_0030753c;
extern char DAT_00307564;
Fx *FUN_000ce8e8(Fx *);
void FUN_00058694(Mat4 *, Mat4 *);
void FUN_00067790(void *, Fx *);
}

extern "C" void FUN_000ce754(void *p1, Mat4 *src, int a, float c, float d, int b, float e)
{
  Fx fx;

  FUN_000ce8e8(&fx);
  fx.vptr = &DAT_00307564;
  FUN_00058694(&fx.m, src);
  fx.f54 = 1.0f;
  fx.f58 = 3000.0f;
  fx.f5c = 0.0f;
  fx.f50 = a;
  fx.f60 = (unsigned char)b;
  fx.f5c = e;
  fx.f54 = d;
  fx.f58 = c;
  FUN_00067790(p1, &fx);
  fx.vptr = &DAT_0030753c;
}
