/* HSTMATCH module=hstp_trans_main.prx start=0x00198530 end=0x00198b4c symbol=FUN_00198530 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Creates a camera, draws the character, reads the framebuffer region back and copies it into the locked texture,
   setting bit 15 where the depth buffer seen through the VRAM mirror at +0x288000 is non-zero; the character
   state touched for the draw is saved first and restored after. Matching idioms: `int i;` declared before the
   sub-object pointers (saved-register order), the VRAM base formed in int arithmetic (a char * sum puts the
   constant in $at), the call result held in a local before `int flag = 0; if (..) flag = 1;`, the 2-D
   `vram[y + i][x + j]` index (MWCC's row IV) and an aligned(16) Vec4 (frame layout). Same code as EBOOT 0x0018bd80. */
struct Vec3 {
  float x, y, z;
};

struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct Camera {                 /* 0x2c0 bytes, FUN_0005c2f8 */
  char pad0[0x1d0];
  Vec4 pos;
  Vec4 dir;
  char pad1f0[0x20c - 0x1f0];
  int f20c;
  int f210;
};

struct Clip {
  char pad0[8];
  float f8;
};

struct Sub58 {
  char pad0[0xf0];
  int f0f0;
  Clip **f0f4;
  unsigned char f0f8;
  char pad0f9[0x104 - 0xf9];
  float f104;
  char pad108[0x10c - 0x108];
  float f10c;
};

struct Range {
  char pad0[0x10];
  float f10;
};

struct Sub50 {
  char pad0[0xa0];
  int f0a0;
  Range *f0a4;
  char pad0a8[0xc0 - 0xa8];
  unsigned char f0c0;
  char pad0c1[0xc4 - 0xc1];
  float f0c4;
  float f0c8;
  char pad0cc[0xd0 - 0xcc];
  float f0d0;
  char pad0d4[0x1b4 - 0xd4];
  int f1b4;
};

struct Sub5c {
  char pad0[0x171];
  unsigned char f171;
};

struct Chara {
  virtual void v0();
  virtual void v1();
  char pad4[0x50 - 4];
  Sub50 *f50;
  int pad54;
  Sub58 *f58;
  Sub5c *f5c;
  Sub5c *f60;
};

struct Item {                   /* FUN_0019fc84 table entry */
  char pad0[0x66];
  unsigned char f66;
};

struct Game {
  char pad0[0x80];
  struct {
    char pad0[0x1025];
    unsigned char tab[15];
    int Get(int i) const {
      if (i >= 0 && i < 15) return tab[i];
      return 1;
    }
  } sub;
};

struct Self {
  char pad0[0x3c];
  Camera *camera;
  Chara *chara;
  unsigned char f44;
  unsigned char f45;
  char pad46[2];
  int width;
  int height;
  int f50;
  int f54;
  int f58;
  char pad5c[0x60 - 0x5c];
  char f60[0x10];
  Vec3 f70;
  unsigned short *(*fn7c)(int, int);
  int pad80;
  void (*fn84)(int, int, int);
};

extern "C" {
extern char DAT_003b9120[];
extern void *DAT_003f344c;
extern Game *DAT_003ea8e8;

void *FUN_00000bcc(unsigned);           /* operator new */
Camera *FUN_0005c2f8(void *);
void FUN_0005d42c(Camera *, int, void *);
void FUN_0005d4fc(Camera *, int, Vec4 *);
void FUN_0005c8e0(Camera *);
unsigned short *FUN_00010184(int, int);
void FUN_00197bdc(void *, int);
void FUN_0001ef14(Self *, int);
float FUN_000957bc(Chara *);
Item *FUN_0019fc84(int);
void FUN_00058250(Sub58 *, int, int);
void FUN_000587ac(float, Sub58 *, int, int);
void FUN_00059ac0(Sub58 *, unsigned char, int);
void FUN_00059c1c(float, Sub58 *, int);
void FUN_00059d68(Sub58 *, int);
void FUN_00059de4(Sub58 *, int);
void FUN_0005fe20(float, Sub50 *, int);
void FUN_0005ff00(float, Sub50 *);
void FUN_00095080(Chara *, int, unsigned char *, int);
void FUN_000953a8(float, Chara *);
void FUN_0004861c(unsigned short *, int, int, int, int);
char *FUN_002c77f0(void);
void FUN_00011090(void *, void *, int);  /* memmove */
void FUN_001dbc68(void *);
void FUN_000104e0(void *);              /* free */
void FUN_0005c688(Camera *, int);

void FUN_00198530(Self *self)
{
  if (self->f44 != 0) {
    self->f44 = 0;
    Camera *camera = (Camera *)FUN_00000bcc(0x2c0);
    if (camera != 0) camera = FUN_0005c2f8(camera);
    self->camera = camera;
    FUN_0005d42c(camera, 1, self->f60);
    Vec4 color(1.0f, 1.0f, 1.0f, 0.0f);
    FUN_0005d4fc(self->camera, 1, &color);
    self->camera->f210 = 0x100;
    self->camera->f20c = 0xeff0;
    self->camera->dir = Vec4(0.0f, 0.0f, -1.0f, 0.0f);
    self->camera->pos = Vec4(self->f70.x, self->f70.y, self->f70.z, 1.0f);
    FUN_0005c8e0(self->camera);
    unsigned short *buf = FUN_00010184(0x10, self->width * self->height * 2);
    if (self->fn7c(self->f50, self->f54) != 0) {
      self->fn84(self->f50, self->f54, 1);
      unsigned short *pixels = self->fn7c(self->f50, self->f54);
      FUN_00197bdc(DAT_003b9120, 0);
      FUN_0001ef14(self, 1);
      Chara *chara = self->chara;
      if (chara != 0) {
        int i;
        Sub58 *s58 = chara->f58;
        Sub50 *s50 = chara->f50;
        Sub5c *s5c = chara->f5c;
        Sub5c *s60 = chara->f60;
        int id = 0;
        int f0f0 = 0;
        unsigned char f0f8 = 0;
        float f104 = 0.0f;
        float f10c = 0.0f;
        int f0a0 = 0;
        unsigned char f0c0 = 0;
        float f0c8 = 0.0f;
        bool d0_set = false;
        unsigned char bytes[2] = {0};
        if (s58 != 0) {
          f0f0 = s58->f0f0;
          f104 = s58->f104;
          f10c = s58->f10c;
          f0f8 = s58->f0f8;
        }
        if (s50 != 0) {
          f0a0 = s50->f0a0;
          f0c0 = s50->f0c0;
          id = s50->f1b4;
          f0c8 = s50->f0c8;
          d0_set = s50->f0d0 != 0.0f;
        }
        if (s5c != 0) bytes[0] = s5c->f171;
        if (s60 != 0) bytes[1] = s60->f171;
        float scale = FUN_000957bc(chara);
        Item *item = FUN_0019fc84(id);
        int flag = 0;
        if (item->f66 == 2) flag = 1;
        if (s58 != 0) {
          FUN_00058250(s58, self->f58, flag);
          FUN_000587ac(0.0f, s58, 0, self->f58);
          FUN_00059ac0(s58, 0, -1);
          FUN_00059c1c(s58->f0f4 != 0 ? (*s58->f0f4)->f8 : 0.0f, s58, -1);
          FUN_00059d68(s58, -1);
          FUN_00059de4(s58, -1);
        }
        if (s50 != 0) {
          FUN_0005fe20(0.0f, s50, self->f58);
          s50->f0c0 = 0;
          FUN_0005ff00(s50->f0a4 != 0 ? s50->f0a4->f10 : 0.0f, s50);
          s50->f0d0 = s50->f0c4;
          s50->f0d0 = 0.0f;
        }
        FUN_00095080(chara, 1, bytes, flag);
        FUN_000953a8(1.0f, chara);
        chara->v1();
        self->f45 = 1;
        FUN_0004861c(buf, 240 - (self->width >> 1), 136 - (self->height >> 1), self->width, self->height);
        self->f45 = 0;
        unsigned short (*vram)[512] = (unsigned short (*)[512])((int)FUN_002c77f0() + 0x288000);
        int x = 240 - (self->width >> 1);
        int y = 136 - (self->height >> 1);
        for (i = 0; i < self->height; i++) {
          FUN_00011090(&pixels[i * self->width], &buf[i * self->width], self->width * 2);
          for (int j = 0; j < self->height; j++) {
            if (vram[y + i][x + j] != 0) {
              pixels[j + i * self->width] |= 0x8000;
            }
          }
        }
        int flag2 = 0;
        if (DAT_003ea8e8->sub.Get(id) == 2) flag2 = 1;
        if (s58 != 0) {
          FUN_00058250(s58, f0f0, flag2);
          FUN_000587ac(0.0f, s58, 0, f0f0);
          FUN_00059ac0(s58, f0f8, -1);
          FUN_00059c1c(f104, s58, -1);
          if (f10c == 0.0f) {
            FUN_00059de4(s58, -1);
          } else {
            FUN_00059d68(s58, -1);
          }
        }
        if (s50 != 0) {
          FUN_0005fe20(0.0f, s50, f0a0);
          s50->f0c0 = f0c0;
          FUN_0005ff00(f0c8, s50);
          if (d0_set) {
            s50->f0d0 = s50->f0c4;
          } else {
            s50->f0d0 = 0.0f;
          }
        }
        FUN_00095080(chara, 1, bytes, flag2);
        FUN_000953a8(scale, chara);
        chara->v1();
      }
      FUN_00197bdc(DAT_003b9120, 1);
      if (DAT_003f344c != 0) FUN_001dbc68(DAT_003f344c);
    }
    FUN_000104e0(buf);
    if (self->camera != 0) {
      FUN_0005c688(self->camera, 1);
      self->camera = 0;
    }
  }
}
}
