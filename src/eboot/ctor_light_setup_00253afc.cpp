/* HSTMATCH module=EBOOT.BIN start=0x00253afc end=0x00253cd8 symbol=__ct__10C_00253afcFv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: constructor of a class with 16-byte Vec4 members whose ctor/copy ctor/operator=/4-float ctor are out-of-line (symbols __ct__4Vec4Fv, __ct__4Vec4Fffff, __ct__4Vec4FRC4Vec4, __as__4Vec4FRC4Vec4 = 0x57344, 0x6de18, 0x4c644, 0x54330); the 4-element zero loop is a do/while over f60[i] (a for loop is unrolled). */
struct Vec4 {
  float x, y, z, w;
  Vec4();
  Vec4(float, float, float, float);
  Vec4(const Vec4 &);
  Vec4 &operator=(const Vec4 &);
};

extern "C" void FUN_0005b670(void *);
extern "C" void FUN_0005ba78(void *, void *);
extern "C" void FUN_0005ba00(void *, int);
extern "C" void FUN_00253cd8(void *);

extern Vec4 DAT_002bc410;
extern void *DAT_003313c4;

struct C_00253afc {
  char pad0[0x60];
  int f60[4];
  Vec4 m70;
  Vec4 m80;
  float f90;
  float f94;
  char pad1[8];
  Vec4 a[2];
  Vec4 b[2];
  Vec4 c;
  char pad2[0x1ec - 0xf0];
  char dq[24];
  C_00253afc();
};

C_00253afc::C_00253afc()
    : m70(DAT_002bc410), m80(Vec4(0.0f, 0.0f, 1.0f, 1.0f)), f90(240.0f), f94(136.0f)
{
  a[0] = Vec4(-0.5f, 0.5f, -1.0f, 0.0f);
  a[1] = Vec4(0.0f, 0.0f, -1.0f, 0.0f);
  b[0] = Vec4(1.0f, 1.0f, 1.0f, 0.0f);
  b[1] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
  c = Vec4(0.65f, 0.65f, 0.65f, 1.0f);
  char cam[704];
  FUN_0005b670(cam);
  FUN_0005ba78(DAT_003313c4, cam);
  FUN_0005ba00(cam, -1);
  FUN_00253cd8(dq);
  unsigned i = 0;
  do {
    f60[i] = 0;
  } while (++i < 4);
}
