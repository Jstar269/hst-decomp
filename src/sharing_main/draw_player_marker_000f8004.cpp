/* HSTMATCH module=hstp_trans_main.prx start=0x000f8004 end=0x000f82bc symbol=FUN_000f8004 bss=0x003e1f20 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/draw_player_marker_000f293c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
  int unk0;
  int unk4;
};

struct Player {
  char pad0[0x5bc];
  Rec *rec;
};

struct Game {
  char pad0[0x70];
  Player *players[6];
};

struct Cam {
  char pad0[0x198];
  int player_index;
};

struct PlayerFlag {
  unsigned char flag;
  char pad[0x11f];
};

struct Self {
  unsigned char hidden;
  char pad1[3];
  float alpha;
  int tex;
};

enum { SCREEN_W = 480, SCREEN_H = 272 };

extern unsigned char DAT_003e19f8;
extern Cam *DAT_003e1e04;
extern Game *DAT_003e19f0;
extern void *DAT_003da704;
extern char DAT_003ba4b0;
extern Mat4 DAT_003d4510;
extern float DAT_0037e7e8;
extern PlayerFlag DAT_003eabf4[];

extern "C" {
void FUN_000957dc(Mat4 *, Rec *, int);
void FUN_00051138(void *, void *);
void FUN_00022570(Vec4 *, Mat4 *, Vec4 *);
void FUN_000224c0(float, Vec4 *, Vec4 *);
void FUN_00051e30(int, int, int, int, int, int, int);
void FUN_00052354(float, float, float, float, float, float, float, float, float, int, Color);
void FUN_000522c0(int);
}

extern "C" void FUN_000f8004(Self *self)
{
  if (self->hidden == 0) {
    int idx = (DAT_003e19f8 != 0 && DAT_003e1e04 != 0) ? DAT_003e1e04->player_index : 0;
    Rec *rec = DAT_003e19f0->players[idx]->rec;
    Vec4 v;
    Mat4 m;
    FUN_000957dc(&m, rec, rec->unk4);
    v.w = 1.0f;
    v.x = m.r3.x;
    v.y = m.r3.y;
    v.z = m.r3.z;
    FUN_00051138(&DAT_003ba4b0, DAT_003da704);
    FUN_00022570(&v, &DAT_003d4510, &v);
    if (v.w > 0.0f) {
      FUN_000224c0(1.0f / v.w, &v, &v);
      v.x = v.x - 1808.0f;
      v.y = v.y - 1912.0f;
      float k = 32.0f;
      static Vec4 off = Vec4(-k * 0.5f, -k * 2.5f, 0.0f, 0.0f);
      v.x = v.x + off.x * DAT_0037e7e8;
      v.y = v.y + off.y * DAT_0037e7e8;
      int tex = self->tex;
      float u = 0.0f;
      if (DAT_003eabf4[idx].flag != 0) u = 32.0f; /* u offset when the player's flag is set */
      FUN_00051e30(tex, 0, 0, SCREEN_W, SCREEN_H, 0, 0);
      Color c;
      c.r = 128;
      c.g = 128;
      c.b = 128;
      c.a = (unsigned char)(unsigned int)(self->alpha * 128.0f);
      float size = 32.0f;
      float z = 65240.0f;
      FUN_00052354(u, 0.0f, v.x, v.y, u + size, size, v.x + size * DAT_0037e7e8, v.y + size * DAT_0037e7e8, (float)(int)z, tex, c);
      FUN_000522c0(tex);
    }
  }
}
