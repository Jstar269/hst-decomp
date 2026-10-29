/* HSTMATCH module=EBOOT.BIN start=0x000b74d4 end=0x000b7870 symbol=FUN_000b74d4 lang=c++ */
typedef unsigned int uint;
struct Elem80 { int w[20]; };
extern "C" void FUN_0027f9b0(void *, void *, void *);
struct Vec {
  Elem80 *begin;
  Elem80 *end;
  Elem80 *cap;
  uint size() const { return end - begin; }
  uint max_size() const { return 0x66666666u; }
  void reserve(uint n) { FUN_0027f9b0(begin, end, (void *)n); }
};
extern "C" Elem80 *FUN_000b74d4(Elem80 **out, Vec *v, Elem80 *pos, uint n, const Elem80 *val, int flag)
{
  uint sz = v->size();
  uint need = sz + n;
  if (need < sz || need > v->max_size()) return 0;
  if (need > (uint)(v->cap - v->begin)) {
    uint cap = need < 0x22222222u ? need * 3 : (need < 0x44444444u ? need + need / 2 : need);
    v->reserve(cap);
  }
  Elem80 *p = pos;
  Elem80 *e = v->end;
  while (e != p) { --e; e[1] = e[0]; }
  Elem80 *r = p;
  for (uint k = 0; k < n; k++) { *p = *val; ++p; }
  v->end += n;
  *out = r;
  return r;
}
// NEAR 209/231; every word differs from +0x0: frame 304 (ours) vs retail different prologue order; need the retail growth block disassembled to shape reserve inline (v1 reserve_impl call emitted as a separate function).
// near miss from lane dsn3 (unreviewed)
