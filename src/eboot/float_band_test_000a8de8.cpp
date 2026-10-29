/* HSTMATCH module=EBOOT.BIN start=0x000a8de8 end=0x000a902c symbol=FUN_000a8de8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed structs in C++, context getter called inside the first comparison, division duplicated into both arms, `Min(const float &, const float &)` returning by value (double global load) for the upper clamp, locals declared offset, abs_offset, ratio, raw_ratio, lo, hi for the FPR numbering, final test through a bool-returning inline `Lt` compared `== false` (matching idiom: keeps the materialised bool and its unfilled-slot return); exact match verified; names and types await human review. */
struct Ctx { char pad[0x2c]; float unk2c; /* 0x2c */ };
struct Obj { char pad[0x440]; int unk440; /* 0x440 */ };
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

/* Returns 1 when |vec[0]| is under the limit from the context but not under a smaller limit that depends on
   the ratio (how far vec[2] lies past a threshold, scaled by one of two divisors, capped by a global). */
extern "C" int FUN_000a8de8(Obj *obj, float *vec)
{
  float offset;
  float abs_offset;
  float ratio;
  float raw_ratio;
  float lo;
  float hi;
  int sign;
  if (fabsf(vec[0]) < FUN_000b3c68(obj)->unk2c * 0.01f) {
    offset = vec[2] - DAT_0034129c * 0.01f;
    ratio = 0.0f;
    abs_offset = fabsf(offset);
    if (abs_offset > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
      if (offset < 0.0f) {
        sign = -1;
      } else {
        sign = 1;
      }
      offset = offset - (float)sign * (FUN_001621c0(DAT_00341120, 0) * 0.01f);
      if (offset > 0.0f) {
        raw_ratio = offset / (DAT_00341294 * 0.01f * (float)DAT_00341284);
      } else {
        raw_ratio = offset / (DAT_00341294 * 0.01f * (float)DAT_00341288);
      }
      ratio = Min(raw_ratio, DAT_002d46ac);
    }
    hi = FUN_00164474(FUN_000b3c68(obj), obj->unk440) * 0.01f;
    lo = FUN_0016442c(FUN_000b3c68(obj), obj->unk440) * 0.01f;
    if (Lt(fabsf(vec[0]), (1.0f - (lo + ratio * (hi - lo))) * (FUN_000b3c68(obj)->unk2c * 0.01f)) == false) {
      return 1;
    }
  }
  return 0;
}
