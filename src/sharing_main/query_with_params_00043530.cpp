/* HSTMATCH module=hstp_trans_main.prx start=0x00043530 end=0x00043664 symbol=FUN_00043530 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the default constructor already sets every field and the null-pointer branch assigns the same seven defaults again (both sets are in retail); names and types await human review. */
struct Params {
  float a, b;
  unsigned short c;
  float d, e, f, g;
  signed char h;
  short i, j, k, l;
  Params() : a(0.0f), b(0.0f), c(0), d(1.0f), e(1.0f), f(0.0f), g(0.0f), h(0), i(0), j(0), k(-32), l(16) {}
};

extern "C" float FUN_00044b18(void *, void *, Params *);
extern "C" float FUN_00044c88(void *, void *, Params *);

extern "C" void FUN_00043530(void *a, void *b, float *o1, float *o2, const Params *p)
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
  *o1 = FUN_00044b18(a, b, &prm);
  *o2 = FUN_00044c88(a, b, &prm);
}
