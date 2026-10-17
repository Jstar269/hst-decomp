/* HSTMATCH module=EBOOT.BIN start=0x000a8de8 end=0x000a902c symbol=FUN_000a8de8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed structs in C++, context getter called inside the first comparison, division duplicated into both arms, `Min(const float &, const float &)` returning by value (double global load) for the upper clamp, locals declared v, av, t, q, b, a for the FPR numbering, final test through a bool-returning inline `Lt` compared `== false` (matching idiom: keeps the materialised bool and its unfilled-slot return); exact match verified; names and types await human review. */
struct Ctx { char pad[0x2c]; float f2c; };
struct Obj { char pad[0x440]; int f440; };
extern "C" {
extern float DAT_002d46ac;
extern int DAT_00341284;
extern int DAT_00341288;
extern float DAT_00341294;
extern float DAT_0034129c;
extern char DAT_00341120[];
extern Ctx *FUN_000b3c68(Obj *);
extern float FUN_001621c0(void *, int);
extern float FUN_0016442c(Ctx *, int);
extern float FUN_00164474(Ctx *, int);
extern float fabsf(float);
}
static inline bool Lt(float x, float y) { return x < y; }
static inline float Min(const float &a, const float &b) { return !(a > b) ? a : b; }

extern "C" int FUN_000a8de8(Obj *o, float *p)
{
  float v;
  float av;
  float t;
  float q;
  float b;
  float a;
  int s;
  if (fabsf(p[0]) < FUN_000b3c68(o)->f2c * 0.01f) {
    v = p[2] - DAT_0034129c * 0.01f;
    t = 0.0f;
    av = fabsf(v);
    if (av > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
      if (v < 0.0f) {
        s = -1;
      } else {
        s = 1;
      }
      v = v - (float)s * (FUN_001621c0(DAT_00341120, 0) * 0.01f);
      if (v > 0.0f) {
        q = v / (DAT_00341294 * 0.01f * (float)DAT_00341284);
      } else {
        q = v / (DAT_00341294 * 0.01f * (float)DAT_00341288);
      }
      t = Min(q, DAT_002d46ac);
    }
    a = FUN_00164474(FUN_000b3c68(o), o->f440) * 0.01f;
    b = FUN_0016442c(FUN_000b3c68(o), o->f440) * 0.01f;
    if (Lt(fabsf(p[0]), (1.0f - (b + t * (a - b))) * (FUN_000b3c68(o)->f2c * 0.01f)) == false) {
      return 1;
    }
  }
  return 0;
}
