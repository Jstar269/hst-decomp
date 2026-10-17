/* HSTMATCH module=EBOOT.BIN start=0x0004344c end=0x00043580 symbol=FUN_0004344c lang=c++ */
/* Clone of src/sharing_main/query_with_params_00043530.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the default constructor already sets every field and the null-pointer branch assigns the same seven defaults again (both sets are in retail); names and types await human review. */
struct Params {
  float a, b;
  unsigned short c;
  float d, e, f, g;
  signed char h;
  short i, j, k, l;
  Params() : a(0.0f), b(0.0f), c(0), d(1.0f), e(1.0f), f(0.0f), g(0.0f), h(0), i(0), j(0), k(-32), l(16) {}
};

extern "C" float FUN_00044974(void *, void *, Params *);
extern "C" float FUN_00044ae4(void *, void *, Params *);

extern "C" void FUN_0004344c(void *a, void *b, float *o1, float *o2, const Params *p)
{
  Params prm;
  if (p != 0) {
    prm = *p;
  } else {
    prm.a = 0.0f;
    prm.b = 0.0f;
    prm.d = 1.0f;
    prm.e = 1.0f;
    prm.f = 0.0f;
    prm.g = 0.0f;
    prm.h = 0;
  }
  *o1 = FUN_00044974(a, b, &prm);
  *o2 = FUN_00044ae4(a, b, &prm);
}
