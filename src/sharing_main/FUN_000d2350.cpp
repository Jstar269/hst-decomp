/* HSTMATCH module=hstp_trans_main.prx start=0x000d2350 end=0x000d241c symbol=FUN_000d2350 lang=c++ */
/* Clone of src/eboot/FUN_000ce754.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_003b0808;
extern char DAT_003b0830;
Fx *FUN_000d24e4(Fx *);
void FUN_0005931c(Mat4 *, Mat4 *);
void FUN_00068be4(void *, Fx *);
}

extern "C" void FUN_000d2350(void *p1, Mat4 *src, int a, float c, float d, int b, float e)
{
  Fx fx;

  FUN_000d24e4(&fx);
  fx.vptr = &DAT_003b0830;
  FUN_0005931c(&fx.m, src);
  fx.f54 = 1.0f;
  fx.f58 = 3000.0f;
  fx.f5c = 0.0f;
  fx.f50 = a;
  fx.f60 = (unsigned char)b;
  fx.f5c = e;
  fx.f54 = d;
  fx.f58 = c;
  FUN_00068be4(p1, &fx);
  fx.vptr = &DAT_003b0808;
}
