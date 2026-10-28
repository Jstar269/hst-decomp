/* HSTMATCH module=EBOOT.BIN start=0x00214ae4 end=0x00214e4c symbol=FUN_00214ae4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed structs in C++, float compares with the variable on the left, the two side flags as unsigned char, swap variables c1/c2 copied before the four position calls (called in the order other, self, p2, p1), second table slot read as `*(Player **)((char *)pl + (u + 2) * 4)` (unfolded index), flag-set arm first, `Max(const float &, const float &)` returning by value for the double global load, `scale` / `z0` / `x0` declared in that order for the FPR numbering; exact match verified; names and types await human review. */
#include "hst/types.h"
struct Player {
  char pad0[0x144];
  u32 f144;
  int f148;
  char pad1[0x580 - 0x14c];
  float f580;
  char pad2[4];
  float f588;
  char pad3[0x5bc - 0x58c];
  int f5bc;
};
struct Game {
  char pad[0x70];
  Player *players[4];
};
struct Cfg {
  char pad[0x45];
  unsigned char f45;
};
struct A30 { char pad[0x30]; float f30; };
struct A124 { char pad[0x124]; float f124; char pad2[0x218 - 0x128]; float f218; };

extern "C" {
extern float DAT_002efacc;
extern float DAT_002efad0;
extern Game *DAT_003386b0;
extern Cfg *DAT_00338b44;
extern u32 FUN_0001342c(void);
extern float *FUN_00093838(int);
extern A124 *FUN_00215a20(Player *);
extern A124 *FUN_00215a58(Player *);
extern A30 *FUN_00215ab8(Player *);

}
static inline float Max(const float &a, const float &b) { return !(a > b) ? b : a; }

extern "C" void FUN_00214ae4(float *out, Player *self)
{
  Player **pl;
  Player *other;
  float sgn;
  float k;
  float m;
  float scale;
  float z0;
  float x0;
  int idx;
  u32 u;
  unsigned char a;
  unsigned char b;
  idx = (self->f148 + 2) % 4;
  pl = DAT_003386b0->players;
  other = pl[idx];
  sgn = other->f580 < self->f580 ? 1.0f : -1.0f;
  x0 = 2.7431998f * sgn;
  k = self->f588 > -5.9435997f ? 0.25f : 1.0f;
  z0 = -11.887199f * k;
  a = self->f588 > -5.9435997f;
  b = other->f588 > -5.9435997f;
  if (a == b) {
    Player *c1;
    Player *c2;
    Player *p2;
    Player *p1;
    float *f2p;
    float *f1p;
    float *f0p;
    float *f3p;
    u = self->f144 ^ 1;
    p1 = pl[u];
    p2 = *(Player **)((char *)pl + (u + 2) * 4);
    c1 = p1;
    c2 = p2;
    f0p = FUN_00093838(other->f5bc);
    f1p = FUN_00093838(self->f5bc);
    f2p = FUN_00093838(p2->f5bc);
    f3p = FUN_00093838(p1->f5bc);
    if ((*f3p - *f2p) * (*f1p - *f0p) < 0.0f) {
      c1 = p2;
      c2 = p1;
    }
    m = c1->f588 < c2->f588 ? 1.0f : -1.0f;
    z0 = z0 + 0.5f * m;
  }
  if (DAT_00338b44->f45 != 0) {
    float s = FUN_00215a58(self)->f124;
    s = s + FUN_00215a20(self)->f124;
    scale = 0.01f * Max(DAT_002efacc, s);
  } else {
    float s = FUN_00215ab8(self)->f30;
    s = s + FUN_00215a20(self)->f218;
    scale = 0.01f * Max(DAT_002efad0, s);
  }
  u = FUN_0001342c();
  x0 = x0 + scale * ((float)(int)(u & 0xfffff800) * 9.313226e-10f + -1.0f);
  u = FUN_0001342c();
  out[0] = x0;
  out[1] = 0.0f;
  out[2] = z0 + scale * ((float)(int)(u & 0xfffff800) * 9.313226e-10f + -1.0f);
  out[3] = 1.0f;
}
