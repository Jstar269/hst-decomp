/* HSTMATCH module=EBOOT.BIN start=0x00253afc end=0x00253cd8 symbol=__ct__10C_00253afcFv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: constructor of a class with 16-byte Vec4 members whose ctor/copy ctor/operator=/4-float ctor are out-of-line (symbols __ct__4Vec4Fv, __ct__4Vec4Fffff, __ct__4Vec4FRC4Vec4, __as__4Vec4FRC4Vec4 = 0x57344, 0x6de18, 0x4c644, 0x54330); the 4-element zero loop is a do/while over unk60[i] (a for loop is unrolled). */
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

/* Scene setup object: screen centre, light directions/colours and an ambient colour. */
struct C_00253afc {
  char pad0[0x60];
  int unk60[4];
  Vec4 unk70;
  Vec4 unk80;
  float centerX;           /* 0x90 half the 480-pixel screen width */
  float centerY;           /* 0x94 half the 272-pixel screen height */
  char pad98[8];
  Vec4 lightDir[2];        /* 0xa0 direction vectors (w = 0) */
  Vec4 lightColor[2];      /* 0xc0 */
  Vec4 ambient;            /* 0xe0 */
  char padf0[0x1ec - 0xf0];
  char dq[24];
  C_00253afc();
};

C_00253afc::C_00253afc()
    : unk70(DAT_002bc410), unk80(Vec4(0.0f, 0.0f, 1.0f, 1.0f)), centerX(240.0f), centerY(136.0f)
{
  lightDir[0] = Vec4(-0.5f, 0.5f, -1.0f, 0.0f);
  lightDir[1] = Vec4(0.0f, 0.0f, -1.0f, 0.0f);
  lightColor[0] = Vec4(1.0f, 1.0f, 1.0f, 0.0f);
  lightColor[1] = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
  ambient = Vec4(0.65f, 0.65f, 0.65f, 1.0f);
  char cam[704];
  FUN_0005b670(cam);
  FUN_0005ba78(DAT_003313c4, cam);
  FUN_0005ba00(cam, -1);
  FUN_00253cd8(dq);
  unsigned i = 0;
  do {
    unk60[i] = 0;
  } while (++i < 4);
}
