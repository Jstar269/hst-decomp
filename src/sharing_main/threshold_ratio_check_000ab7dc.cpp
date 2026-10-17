/* HSTMATCH module=hstp_trans_main.prx start=0x000ab7dc end=0x000aba20 symbol=FUN_000ab7dc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed Ctx/Self structs, the FUN_000b6e80 getter takes the object (Ghidra dropped it) and is called INSIDE the first comparison (so the member load follows the product), fabsf intrinsic, the divide placed in each branch, the clamp as an inline MinF(const float&, const float&) (retail reloads the global), the final bool kept in a local with a separate limit local; exact match verified; names and types await human review. */
/* Matching idioms: MinF with const& parameters (double load of DAT_0037acb4), `float b; float a;` declared in that order (decides f21/f22), named `lim` and `bool lt` locals (decide the constant temp registers and the materialised bool). */
extern "C" float fabsf(float);

struct Ctx {
  char pad[0x2c];
  float f2c;
};
struct Self {
  char pad[0x440];
  int f440;
};

extern "C" Ctx *FUN_000b6e80(Self *);
extern "C" float FUN_0016e74c(void *, int);
extern "C" float FUN_001709e8(Ctx *, int);
extern "C" float FUN_001709a0(Ctx *, int);
extern char DAT_003ea460[];
extern float DAT_003ea5dc;
extern float DAT_003ea5d4;
extern int DAT_003ea5c4;
extern int DAT_003ea5c8;
extern float DAT_0037acb4;
static inline float MinF(const float &a, const float &b) { return a > b ? b : a; }

extern "C" int FUN_000ab7dc(Self *self, float *p)
{
  if (fabsf(p[0]) < FUN_000b6e80(self)->f2c * 0.01f) {
    float d = p[2] - DAT_003ea5dc * 0.01f;
    float ratio = 0.0f;
    if (fabsf(d) > FUN_0016e74c(DAT_003ea460, 0) * 0.01f) {
      int sgn;
      if (d < 0.0f) {
        sgn = -1;
      } else {
        sgn = 1;
      }
      float e = d - (float)sgn * (FUN_0016e74c(DAT_003ea460, 0) * 0.01f);
      if (e > 0.0f) {
        e = e / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4);
      } else {
        e = e / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8);
      }
      ratio = MinF(e, DAT_0037acb4);
    }
    float b;
    float a;
    a = FUN_001709e8(FUN_000b6e80(self), self->f440) * 0.01f;
    b = FUN_001709a0(FUN_000b6e80(self), self->f440) * 0.01f;
    float lim = (1.0f - (b + ratio * (a - b))) * (FUN_000b6e80(self)->f2c * 0.01f);
    bool lt = fabsf(p[0]) < lim;
    if (!lt) {
      return 1;
    }
  }
  return 0;
}
