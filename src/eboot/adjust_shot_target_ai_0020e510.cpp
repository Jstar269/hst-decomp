/* HSTMATCH module=EBOOT.BIN start=0x0020e510 end=0x0020ea40 symbol=FUN_0020e510 lang=c++ helpers=FUN_0020b600@0x0020b600-0x0020b62c */
/* Clone of src/sharing_main/adjust_shot_target_ai_0021d0e4.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (same-file static debug-print stub FUN_0020b600 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
/* PlayerAI.cpp: refresh the shot target (FUN_0020ea40 in singles, FUN_00211270 otherwise), pull its x back onto
   the court half width (4.1148 m singles / 5.4864 m doubles) when FUN_000ddd64 rejects it twice ("Adjust
   ShotTargetAI.x"), pick a random offset in [-n, n] from the AI parameter sums (FUN_00215a58 base + FUN_00215a20
   individual), then compare the distance to the next course element with the parameter limits and choose a random
   side. The distance variable is reused for the clamped rate (Ghidra's fVar6), which gives retail's FPR colouring;
   a separate rate local moves it. Names provisional. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
} __attribute__((aligned(16)));

struct Elem {
  int id;
  unsigned char flag;
  int c;
  Vec4 v;
};

struct ElemList {
  Elem *data;
  unsigned size;
};

struct Ctx {
  char pad[0x268];
  int base;
  ElemList list;
};

struct Game {
  char pad[0x88];
  Ctx *ctx;
};

struct Cfg {
  char pad[0x45];
  unsigned char singles;
};

struct AIParam {
  char pad[0xac];
  short sac;
  short sae;
  float fb0;
  float fb4;
  float fb8;
};

struct PlayerAI {
  char pad0[0x580];
  Vec4 pos;
  char pad1[0x869 - 0x590];
  unsigned char f869;
  char pad2[0x880 - 0x86a];
  Vec4 v880;
  char pad3[0x8cc - 0x890];
  int f8cc;
  int side;
  int f8d4;
  int f8d8;
  int f8dc;
  char pad4[0x8f0 - 0x8e0];
  Vec4 shotTarget;
};

extern "C" {
extern Cfg *DAT_00338b44;
extern Game *DAT_003386b0;
extern float DAT_002efa2c;
extern float DAT_002efa30;
extern float DAT_002efa34;
extern float DAT_002efa38;
extern float DAT_002efa3c;
extern float DAT_002efa40;
extern float DAT_002efa44;
extern float DAT_002efa48;
extern float DAT_002efa4c;
extern char DAT_002efa50[];
unsigned FUN_0001342c();
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
float FUN_00022e44(float);
int FUN_000a7ee0(PlayerAI *, Elem *, float, Ctx *, int);
int FUN_000a8494(PlayerAI *, Vec4 *);
int FUN_000ddd64(Cfg *, Vec4 *, int);
void FUN_0020ea40(PlayerAI *);
void FUN_00211270(PlayerAI *);
AIParam *FUN_00215a20(PlayerAI *);
AIParam *FUN_00215a58(PlayerAI *);
}

extern "C" static void FUN_0020b600(...)
{
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}

static inline float Rand01() { return 4.656613e-10f * (float)(int)(FUN_0001342c() & 0xfffff800); }
static inline float Max(const float &a, const float &b) { return a > b ? a : b; }
static inline float MaxV(const float &a, float b) { return a > b ? a : b; }
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }

extern "C" void FUN_0020e510(PlayerAI *self)
{
  if (DAT_00338b44->singles)
    FUN_0020ea40(self);
  else
    FUN_00211270(self);
  Vec4 t;
  t.x = self->shotTarget.x;
  t.y = self->shotTarget.y;
  t.z = self->shotTarget.z;
  t.w = self->shotTarget.w;
  if (!FUN_000ddd64(DAT_00338b44, &t, 0)) {
    t.z = 1.0f;
    if (!FUN_000ddd64(DAT_00338b44, &t, 0)) {
      float x = DAT_00338b44->singles ? 4.1148f : 5.4863996f;
      if (t.x < 0.0f)
        x = -x;
      FUN_0020b600(DAT_002efa50);
      self->shotTarget.x = x;
    }
  }
  Ctx *ctx = DAT_003386b0->ctx;
  ElemList *list = &ctx->list;
  float f;
  if (FUN_000a8494(self, &self->pos)) {
    int s = FUN_00215a58(self)->sae + FUN_00215a20(self)->sae;
    f = MaxV(DAT_002efa2c, (float)s);
  } else {
    int s = FUN_00215a58(self)->sac + FUN_00215a20(self)->sac;
    f = MaxV(DAT_002efa30, (float)s);
  }
  int n = (int)f;
  int first = -n;
  self->f8cc = (int)(first + 4.656613e-10f * ((float)(n + 1) - first) * (float)(int)(FUN_0001342c() & 0xfffff800));
  self->f8dc = 3;
  self->side = 0;
  float range = self->f869 ? self->v880.z : self->pos.z;
  Elem e;
  if (FUN_000a7ee0(self, &e, range, ctx, 0) && e.id > 0) {
    unsigned i = e.id - 1;
    if (i >= list->size)
      i = list->size - 1;
    Elem *p = &list->data[i];
    Vec4 d = Sub(e.v, p->v);
    float dist = FUN_00022e44(FUN_000224d8(&d, &d));
    dist *= 107.99999f;
    if (dist > Max(DAT_002efa34, FUN_00215a58(self)->fb0 + FUN_00215a20(self)->fb0)) {
      float rangeLo = Max(DAT_002efa40, FUN_00215a58(self)->fb0 + FUN_00215a20(self)->fb0);
      float rangeHi = Max(DAT_002efa3c, FUN_00215a58(self)->fb4 + FUN_00215a20(self)->fb4);
      float base = Max(DAT_002efa38, FUN_00215a58(self)->fb0 + FUN_00215a20(self)->fb0);
      dist = Clamp((dist - base) / (rangeHi - rangeLo), DAT_002efa44, DAT_002efa48);
      dist *= 0.01f * Max(DAT_002efa4c, FUN_00215a58(self)->fb8 + FUN_00215a20(self)->fb8);
      if (Rand01() < dist)
        self->side = Rand01() < 0.5f ? 1 : -1;
    }
  }
}
