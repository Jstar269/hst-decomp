/* HSTMATCH module=hstp_trans_main.prx start=0x0021d0e4 end=0x0021d614 symbol=FUN_0021d0e4 lang=c++ helpers=FUN_002164c4@0x002164c4-0x002164f0 */
/* Hand-written reconstruction from the disassembly (same-file static debug-print stub FUN_002164c4 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
/* PlayerAI.cpp: refresh the shot target (FUN_0021d614 in singles, FUN_0021ff70 otherwise), pull its x back onto
   the court half width (4.1148 m singles / 5.4864 m doubles) when FUN_000e1f50 rejects it twice ("Adjust
   ShotTargetAI.x"), pick a random offset in [-n, n] from the AI parameter sums (FUN_0022492c base + FUN_002248ac
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
extern Cfg *DAT_003e1e84;
extern Game *DAT_003e19f0;
extern float DAT_00397c18;
extern float DAT_00397c1c;
extern float DAT_00397c20;
extern float DAT_00397c24;
extern float DAT_00397c28;
extern float DAT_00397c2c;
extern float DAT_00397c30;
extern float DAT_00397c34;
extern float DAT_00397c38;
extern char DAT_00397c3c[];
unsigned FUN_0001342c();
void FUN_0002245c(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_00022500(const Vec4 *a, const Vec4 *b);
float FUN_00022e6c(float);
int FUN_000aa8d4(PlayerAI *, Elem *, float, Ctx *, int);
int FUN_000aae88(PlayerAI *, Vec4 *);
int FUN_000e1f50(Cfg *, Vec4 *, int);
void FUN_0021d614(PlayerAI *);
void FUN_0021ff70(PlayerAI *);
AIParam *FUN_002248ac(PlayerAI *);
AIParam *FUN_0022492c(PlayerAI *);
}

extern "C" static void FUN_002164c4(...)
{
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}

static inline float Rand01() { return 4.656613e-10f * (float)(int)(FUN_0001342c() & 0xfffff800); }
static inline float Max(const float &a, const float &b) { return a > b ? a : b; }
static inline float MaxV(const float &a, float b) { return a > b ? a : b; }
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }

extern "C" void FUN_0021d0e4(PlayerAI *self)
{
  if (DAT_003e1e84->singles)
    FUN_0021d614(self);
  else
    FUN_0021ff70(self);
  Vec4 t;
  t.x = self->shotTarget.x;
  t.y = self->shotTarget.y;
  t.z = self->shotTarget.z;
  t.w = self->shotTarget.w;
  if (!FUN_000e1f50(DAT_003e1e84, &t, 0)) {
    t.z = 1.0f;
    if (!FUN_000e1f50(DAT_003e1e84, &t, 0)) {
      float x = DAT_003e1e84->singles ? 4.1148f : 5.4863996f;
      if (t.x < 0.0f)
        x = -x;
      FUN_002164c4(DAT_00397c3c);
      self->shotTarget.x = x;
    }
  }
  Ctx *ctx = DAT_003e19f0->ctx;
  ElemList *list = &ctx->list;
  float f;
  if (FUN_000aae88(self, &self->pos)) {
    int s = FUN_0022492c(self)->sae + FUN_002248ac(self)->sae;
    f = MaxV(DAT_00397c18, (float)s);
  } else {
    int s = FUN_0022492c(self)->sac + FUN_002248ac(self)->sac;
    f = MaxV(DAT_00397c1c, (float)s);
  }
  int n = (int)f;
  int first = -n;
  self->f8cc = (int)(first + 4.656613e-10f * ((float)(n + 1) - first) * (float)(int)(FUN_0001342c() & 0xfffff800));
  self->f8dc = 3;
  self->side = 0;
  float range = self->f869 ? self->v880.z : self->pos.z;
  Elem e;
  if (FUN_000aa8d4(self, &e, range, ctx, 0) && e.id > 0) {
    unsigned i = e.id - 1;
    if (i >= list->size)
      i = list->size - 1;
    Elem *p = &list->data[i];
    Vec4 d = Sub(e.v, p->v);
    float dist = FUN_00022e6c(FUN_00022500(&d, &d));
    dist *= 107.99999f;
    if (dist > Max(DAT_00397c20, FUN_0022492c(self)->fb0 + FUN_002248ac(self)->fb0)) {
      float rangeLo = Max(DAT_00397c2c, FUN_0022492c(self)->fb0 + FUN_002248ac(self)->fb0);
      float rangeHi = Max(DAT_00397c28, FUN_0022492c(self)->fb4 + FUN_002248ac(self)->fb4);
      float base = Max(DAT_00397c24, FUN_0022492c(self)->fb0 + FUN_002248ac(self)->fb0);
      dist = Clamp((dist - base) / (rangeHi - rangeLo), DAT_00397c30, DAT_00397c34);
      dist *= 0.01f * Max(DAT_00397c38, FUN_0022492c(self)->fb8 + FUN_002248ac(self)->fb8);
      if (Rand01() < dist)
        self->side = Rand01() < 0.5f ? 1 : -1;
    }
  }
}
