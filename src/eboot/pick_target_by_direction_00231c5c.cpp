/* HSTMATCH module=EBOOT.BIN start=0x00231c5c end=0x00231f84 symbol=FUN_00231c5c lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idioms: plain else-if chain over the four 2-bit config fields ending in 'else return', float locals declared in retail register order (best score first, directions last), the activity gate materialised as 'int act = 0; if (cnt >= 2) act = 1;', and '>' spelled for the positive-direction tests; exact match verified; names and types await human review. */
typedef unsigned char u8;

struct Cfg {
  u8 pad[0x89];
  signed char f0 : 2;
  signed char f1 : 2;
  signed char f2 : 2;
  signed char f3 : 2;
};

struct Self {
  char pad0[0x1dc];
  int f1dc;
  int f1e0;
  char pad1[0x200 - 0x1e4];
  int cnt[10];
  char pad2[0x2a0 - 0x228];
  float x[10];
  float y[10];
};

extern Cfg *DAT_002cfc8c;
extern char DAT_0034179c[];
extern float DAT_002f3e4c;

extern "C" {
float sqrtf(float);
float fabsf(float);
float FUN_0000ce3c(float, float);
float FUN_0000b8a8(float);
void FUN_001b1c44(void *, int);
void FUN_00232558(Self *, int);
}

static inline int Active(int c) { int r; if (c > 1) r = 1; else r = 0; return r; }

extern "C" void FUN_00231c5c(Self *self)
{
  float bestv = 99999.0f;
  float score;
  float ang;
  float dx;
  float dy;
  float len;
  float diry;
  float dirx;
  int best = -1;
  diry = dirx = 0.0f;
  if (DAT_002cfc8c->f3 == 0) {
    dirx = -1.0f;
  } else if (DAT_002cfc8c->f1 == 0) {
    dirx = 1.0f;
  } else if (DAT_002cfc8c->f0 == 0) {
    diry = -1.0f;
  } else if (DAT_002cfc8c->f2 == 0) {
    diry = 1.0f;
  } else {
    return;
  }
  for (int i = 0; i < 10; i++) {
    int act = 0;
    if (self->cnt[i] >= 2) act = 1;
    if (act != 0) {
      score = 99999.0f;
      ang = score;
      dx = self->x[i] - self->x[self->f1e0];
      dy = self->y[i] - self->y[self->f1e0];
      len = sqrtf(FUN_0000ce3c(dx, 2.0f) + FUN_0000ce3c(dy, 2.0f));
      if ((dirx < 0.0f && dx < 0.0f) || (dirx > 0.0f && dx > 0.0f)) {
        ang = 57.29578f * FUN_0000b8a8(fabsf(dy) / fabsf(dx));
        score = len * (1.0f + ang * DAT_002f3e4c);
      } else if ((diry < 0.0f && dy < 0.0f) || (diry > 0.0f && dy > 0.0f)) {
        ang = 57.29578f * FUN_0000b8a8(fabsf(dx) / fabsf(dy));
        score = len * (1.0f + ang * DAT_002f3e4c);
      }
      if (score < bestv && ang < 70.0f) {
        bestv = score;
        best = i;
      }
    }
  }
  if (best >= 0) {
    if (self->f1e0 != best) FUN_001b1c44(DAT_0034179c, 1);
    self->f1e0 = best;
    switch (self->f1dc) {
    case 0:
      break;
    case 1:
      FUN_00232558(self, self->f1e0);
      break;
    }
  }
}
