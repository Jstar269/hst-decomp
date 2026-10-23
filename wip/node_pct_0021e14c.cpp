/* HSTMATCH module=EBOOT.BIN start=0x0021e14c end=0x0021e20c symbol=FUN_0021e14c lang=c++ */
struct Node {
  unsigned char pad00[4];
  short f4;                   /* 0x04 */
  unsigned char pad06[2];
  short f8;                   /* 0x08 */
};

struct Obj {
  unsigned char pad00[0xa8];
  struct Node *node;          /* 0xa8 */
  unsigned char padac[0x128];
  float f1d4;                 /* 0x1d4 */
  unsigned char pad1d8[0x18];
  int f1f0;                   /* 0x1f0 */
  int f1f4;                   /* 0x1f4 */
  unsigned char pad1f8[8];
  int f200;                   /* 0x200 */
  int f204;                   /* 0x204 */
};

extern "C" float DAT_002f0874;
extern "C" float DAT_002f0878;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (v <= hi ? v : hi);
}

extern "C" void FUN_0021e14c(struct Obj *param_1, int param_2)
{
  struct Node *node;
  float ratio;
  float k;
  float den;

  param_1->f204 = param_2;
  den = (float)(param_1->f1f4 - param_1->f1f0);
  ratio = (float)(param_1->f200 + param_2 - param_1->f1f0) * 100.0f / den / 100.0f;
  node = param_1->node;
  if (node != 0) {
    k = Clamp(ratio, DAT_002f0874, DAT_002f0878);
    node->f8 = (short)(int)((float)node->f4 + param_1->f1d4 * k);
  }
}
// NEAR 20 of 48 words (ours 47, retail 48). Everything through the ratio is
// identical, including the double global load of the clamp bounds and the two
// divisions. What differs: retail's final `div.s f1,f0,f2` puts the ratio in $f1
// and reuses $f2 for the clamp value, ours puts it in $f2 (`div.s f2,f0,f2`) and
// uses $f1 for the clamp value, which moves the `beqz node` one slot later and
// flips the second compare to c.le.s + bc1fl (retail: c.ngt.s + bc1tl).
// Ruled out: ratio inside the if (37), node read before the ratio (37), the
// explicit two-arm clamp with the base load duplicated per arm (31, and 43
// words), a named `den`/`num` (20), `100.0f * num` (20), ratio split over two
// statements (34), `k` declared before `ratio` (20), and `hi < v ? hi : v`
// instead of `v <= hi ? v : hi` (37 to 46).
// near miss from lane fm5 (unreviewed)
