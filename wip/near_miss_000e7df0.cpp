/* HSTMATCH module=EBOOT.BIN start=0x000e7df0 end=0x000e7f0c symbol=FUN_000e7df0 lang=c++ */
typedef unsigned int undefined4;

extern "C" {
extern int DAT_00307614;
extern int FUN_00000bcc(unsigned int);
extern int *FUN_0001f06c(int *, int);
extern int *FUN_00054f08(...);
extern void FUN_000550ec(float, int);
extern int FUN_0005b670(...);
}

struct VC_0 {
  virtual void d0();
  virtual void d1();
  virtual void d2();
  virtual void d3();
  virtual void d4();
  virtual void m();
};

struct Vec4_0 { float x, y, z, w; };

extern "C" int *FUN_000e7df0(int *param_1, int param_2,
                              const Vec4_0 *param_3, const Vec4_0 *param_4)
{
  int context = param_2;
  int *self = param_1;
  int value;
  int *object;
  Vec4_0 a = *param_3;
  Vec4_0 b = *param_4;

  FUN_0001f06c(self, context);
  *self = (int)&DAT_00307614;
  FUN_0005b670(self + 0x14);
  ((VC_0 *)self)->m();
  value = *(int *)(context + 0x8c);
  ((float *)self)[200] = a.x;
  ((float *)self)[201] = a.y;
  ((float *)self)[202] = a.z;
  ((float *)self)[203] = a.w;
  ((float *)self)[204] = b.x;
  ((float *)self)[205] = b.y;
  ((float *)self)[206] = b.z;
  ((float *)self)[207] = b.w;
  object = (int *)FUN_00000bcc(0xa0);
  if (object) {
    object = FUN_00054f08(object, value);
  }
  self[0xf] = (int)object;
  FUN_000550ec(1.01f, (int)object);
  self[0xc6] = 0;
  self[0xe4] = 0x3f800000;
  return self;
}
// Near miss: two words differ at +0x44 because MWCC saves a0 to s0 before a1 to s1; retail saves s1 first.
// near miss from lane u2r1-2 (unreviewed)
