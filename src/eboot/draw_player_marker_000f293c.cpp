/* HSTMATCH module=EBOOT.BIN start=0x000f293c end=0x000f2bf4 symbol=FUN_000f293c bss=0x00338be0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified. Projects the active player's world position (translation row of the matrix built by FUN_000938b8) to screen space and draws a 32x32 sprite with an alpha-faded colour; the screen-space offset is a function-local static Vec4 (bss=0x00338be0: guard byte then the 16-byte object). Matching idioms: locals declared v before m (v above the matrix), idx as one ternary over the two globals, 'k = 32.0f' held in a non-const local so -k stays a runtime neg.s, the size local used value-first, and (float)(int)z through a non-const local so the trunc/cvt pair survives. Names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct Mat4 {
  Vec4 r0, r1, r2, r3;
};

struct Color {
  unsigned char r, g, b, a;
};

struct Rec {
  int f0;
  int f4;
};

struct Player {
  char pad0[0x5bc];
  Rec *f5bc;
};

struct Game {
  char pad0[0x70];
  Player *players[6];
};

struct Cam {
  char pad0[0x198];
  int f198;
};

struct Slot {
  unsigned char flag;
  char pad[0x11f];
};

struct Self {
  unsigned char hidden;
  char pad1[3];
  float alpha;
  int tex;
};

extern unsigned char DAT_003386b8;
extern Cam *DAT_00338ac4;
extern Game *DAT_003386b0;
extern void *DAT_003313c4;
extern char DAT_00311170;
extern Mat4 DAT_0032b1d0;
extern float DAT_002d7a10;
extern Slot DAT_003418bc[];

extern "C" {
void FUN_000938b8(Mat4 *, Rec *, int);
void FUN_00050824(void *, void *);
void FUN_00022548(Vec4 *, Mat4 *, Vec4 *);
void FUN_00022498(float, Vec4 *, Vec4 *);
void FUN_00051490(int, int, int, int, int, int, int);
void FUN_00051894(float, float, float, float, float, float, float, float, float, int, Color);
void FUN_0005185c(int);
}

extern "C" void FUN_000f293c(Self *self)
{
  if (self->hidden == 0) {
    int idx = (DAT_003386b8 != 0 && DAT_00338ac4 != 0) ? DAT_00338ac4->f198 : 0;
    Rec *rec = DAT_003386b0->players[idx]->f5bc;
    Vec4 v;
    Mat4 m;
    FUN_000938b8(&m, rec, rec->f4);
    v.w = 1.0f;
    v.x = m.r3.x;
    v.y = m.r3.y;
    v.z = m.r3.z;
    FUN_00050824(&DAT_00311170, DAT_003313c4);
    FUN_00022548(&v, &DAT_0032b1d0, &v);
    if (v.w > 0.0f) {
      FUN_00022498(1.0f / v.w, &v, &v);
      v.x = v.x - 1808.0f;
      v.y = v.y - 1912.0f;
      float k = 32.0f;
      static Vec4 off = Vec4(-k * 0.5f, -k * 2.5f, 0.0f, 0.0f);
      v.x = v.x + off.x * DAT_002d7a10;
      v.y = v.y + off.y * DAT_002d7a10;
      int tex = self->tex;
      float u = 0.0f;
      if (DAT_003418bc[idx].flag != 0) u = 32.0f;
      FUN_00051490(tex, 0, 0, 480, 272, 0, 0);
      Color c;
      c.r = 128;
      c.g = 128;
      c.b = 128;
      c.a = (unsigned char)(unsigned int)(self->alpha * 128.0f);
      float size = 32.0f;
      float z = 65240.0f;
      FUN_00051894(u, 0.0f, v.x, v.y, u + size, size, v.x + size * DAT_002d7a10, v.y + size * DAT_002d7a10, (float)(int)z, tex, c);
      FUN_0005185c(tex);
    }
  }
}
