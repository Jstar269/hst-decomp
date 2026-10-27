/* HSTMATCH module=EBOOT.BIN start=0x0018bd80 end=0x0018c39c symbol=FUN_0018bd80 lang=c++ */
/* Clone of src/sharing_main/render_to_texture_00198530.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
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

struct Camera {                 /* 0x2c0 bytes, FUN_0005b670 */
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

struct Item {                   /* FUN_00193474 table entry */
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
extern char DAT_0030fe20[];
extern void *DAT_0034a114;
extern Game *DAT_003415a8;

void *FUN_00000bcc(unsigned);           /* operator new */
Camera *FUN_0005b670(void *);
void FUN_0005c7a4(Camera *, int, void *);
void FUN_0005c810(Camera *, int, Vec4 *);
void FUN_0005bc58(Camera *);
unsigned short *FUN_00010184(int, int);
void FUN_0018b490(void *, int);
void FUN_0001f1fc(Self *, int);
float FUN_00093898(Chara *);
Item *FUN_00193474(int);
void FUN_000575fc(Sub58 *, int, int);
void FUN_00057b58(float, Sub58 *, int, int);
void FUN_00058ddc(Sub58 *, unsigned char, int);
void FUN_00058f38(float, Sub58 *, int);
void FUN_00059084(Sub58 *, int);
void FUN_00059100(Sub58 *, int);
void FUN_0005f030(float, Sub50 *, int);
void FUN_0005f110(float, Sub50 *);
void FUN_000931ec(Chara *, int, unsigned char *, int);
void FUN_00093484(float, Chara *);
void FUN_0004848c(unsigned short *, int, int, int, int);
char *FUN_002b7a50(void);
void FUN_00011090(void *, void *, int);  /* memmove */
void FUN_001cd58c(void *);
void FUN_000104e0(void *);              /* free */
void FUN_0005ba00(Camera *, int);

void FUN_0018bd80(Self *self)
{
  if (self->f44 != 0) {
    self->f44 = 0;
    Camera *camera = (Camera *)FUN_00000bcc(0x2c0);
    if (camera != 0) camera = FUN_0005b670(camera);
    self->camera = camera;
    FUN_0005c7a4(camera, 1, self->f60);
    Vec4 color(1.0f, 1.0f, 1.0f, 0.0f);
    FUN_0005c810(self->camera, 1, &color);
    self->camera->f210 = 0x100;
    self->camera->f20c = 0xeff0;
    self->camera->dir = Vec4(0.0f, 0.0f, -1.0f, 0.0f);
    self->camera->pos = Vec4(self->f70.x, self->f70.y, self->f70.z, 1.0f);
    FUN_0005bc58(self->camera);
    unsigned short *buf = FUN_00010184(0x10, self->width * self->height * 2);
    if (self->fn7c(self->f50, self->f54) != 0) {
      self->fn84(self->f50, self->f54, 1);
      unsigned short *pixels = self->fn7c(self->f50, self->f54);
      FUN_0018b490(DAT_0030fe20, 0);
      FUN_0001f1fc(self, 1);
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
        float scale = FUN_00093898(chara);
        Item *item = FUN_00193474(id);
        int flag = 0;
        if (item->f66 == 2) flag = 1;
        if (s58 != 0) {
          FUN_000575fc(s58, self->f58, flag);
          FUN_00057b58(0.0f, s58, 0, self->f58);
          FUN_00058ddc(s58, 0, -1);
          FUN_00058f38(s58->f0f4 != 0 ? (*s58->f0f4)->f8 : 0.0f, s58, -1);
          FUN_00059084(s58, -1);
          FUN_00059100(s58, -1);
        }
        if (s50 != 0) {
          FUN_0005f030(0.0f, s50, self->f58);
          s50->f0c0 = 0;
          FUN_0005f110(s50->f0a4 != 0 ? s50->f0a4->f10 : 0.0f, s50);
          s50->f0d0 = s50->f0c4;
          s50->f0d0 = 0.0f;
        }
        FUN_000931ec(chara, 1, bytes, flag);
        FUN_00093484(1.0f, chara);
        chara->v1();
        self->f45 = 1;
        FUN_0004848c(buf, 240 - (self->width >> 1), 136 - (self->height >> 1), self->width, self->height);
        self->f45 = 0;
        unsigned short (*vram)[512] = (unsigned short (*)[512])((int)FUN_002b7a50() + 0x288000);
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
        if (DAT_003415a8->sub.Get(id) == 2) flag2 = 1;
        if (s58 != 0) {
          FUN_000575fc(s58, f0f0, flag2);
          FUN_00057b58(0.0f, s58, 0, f0f0);
          FUN_00058ddc(s58, f0f8, -1);
          FUN_00058f38(f104, s58, -1);
          if (f10c == 0.0f) {
            FUN_00059100(s58, -1);
          } else {
            FUN_00059084(s58, -1);
          }
        }
        if (s50 != 0) {
          FUN_0005f030(0.0f, s50, f0a0);
          s50->f0c0 = f0c0;
          FUN_0005f110(f0c8, s50);
          if (d0_set) {
            s50->f0d0 = s50->f0c4;
          } else {
            s50->f0d0 = 0.0f;
          }
        }
        FUN_000931ec(chara, 1, bytes, flag2);
        FUN_00093484(scale, chara);
        chara->v1();
      }
      FUN_0018b490(DAT_0030fe20, 1);
      if (DAT_0034a114 != 0) FUN_001cd58c(DAT_0034a114);
    }
    FUN_000104e0(buf);
    if (self->camera != 0) {
      FUN_0005ba00(self->camera, 1);
      self->camera = 0;
    }
  }
}
}
