/* HSTMATCH module=hstp_trans_main.prx start=0x00263fa0 end=0x0026417c symbol=__ct__10C_00263fa0Fv lang=c++ */
/* Clone of src/eboot/ctor_light_setup_00253afc.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: constructor of a class with 16-byte Vec4 members whose ctor/copy ctor/operator=/4-float ctor are out-of-line (symbols __ct__4Vec4Fv, __ct__4Vec4Fffff, __ct__4Vec4FRC4Vec4, __as__4Vec4FRC4Vec4 = 0x57344, 0x6de18, 0x4c644, 0x54330); the 4-element zero loop is a do/while over f60[i] (a for loop is unrolled). */
struct Vec4 {
  float x, y, z, w;
  Vec4();
  Vec4(float, float, float, float);
  Vec4(const Vec4 &);
  Vec4 &operator=(const Vec4 &);
};

extern "C" void FUN_0005c2f8(void *);
extern "C" void FUN_0005c700(void *, void *);
extern "C" void FUN_0005c688(void *, int);
extern "C" void FUN_0026417c(void *);

extern Vec4 DAT_002cc260;
extern void *DAT_003da704;

struct C_00263fa0 {
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
  C_00263fa0();
};

C_00263fa0::C_00263fa0()
    : m70(DAT_002cc260), m80(Vec4(0.0f, 0.0f, 1.0f, 1.0f)), f90(240.0f), f94(136.0f)
{
  a[0] = Vec4(-0.5f, 0.5f, -1.0f, 0.0f);
  a[1] = Vec4(0.0f, 0.0f, -1.0f, 0.0f);
  b[0] = Vec4(1.0f, 1.0f, 1.0f, 0.0f);
  b[1] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
  c = Vec4(0.65f, 0.65f, 0.65f, 1.0f);
  char cam[704];
  FUN_0005c2f8(cam);
  FUN_0005c700(DAT_003da704, cam);
  FUN_0005c688(cam, -1);
  FUN_0026417c(dq);
  unsigned i = 0;
  do {
    f60[i] = 0;
  } while (++i < 4);
}
