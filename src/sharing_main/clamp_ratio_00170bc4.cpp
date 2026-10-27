/* HSTMATCH module=hstp_trans_main.prx start=0x00170bc4 end=0x00170c70 symbol=FUN_00170bc4 lang=c++ */
/* Hand-written reconstruction from the disassembly (the last row is addressed through a `Row *` local, `Row *lastRow = p + n;`, which keeps retail's base-first addu where `p[n].key` gives index-first; matching idiom: the ratio is an in-place divide `f = t - first; f = f / (last - first);` as in the sibling src/sharing_main/clamp_ratio_00170b24.cpp); exact match verified; names and types await human review. */
struct Row { int id; float key; int c; int d; int e; };
struct TrackCtx { Row *rows; int count; };
extern TrackCtx *DAT_003ea850;
extern float DAT_0038794c;
extern float DAT_00387950;
extern "C" float FUN_0017020c(int, int, int, float, int);

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00170bc4(int param_1, int param_2)
{
  float t = FUN_0017020c(param_1, param_2, 1, 100.0f, 0);
  TrackCtx *ctx = DAT_003ea850;
  Row *p = ctx->rows;
  float first = p[0].key;
  int n = ctx->count - 1;
  Row *lastRow = p + n;
  float last = lastRow->key;
  float f = t - first;
  f = f / (last - first);
  return Clamp(f, DAT_0038794c, DAT_00387950);
}
