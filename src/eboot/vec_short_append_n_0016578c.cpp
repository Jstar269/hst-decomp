/* HSTMATCH module=EBOOT.BIN start=0x0016578c end=0x00165840 symbol=FUN_0016578c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed short vector, if/else with the fill branch returning and the grow branch falling into the append call, || with the cap compare written n > cap, signed short fill through an inline helper taking an unused empty Tag by value (the 16 extra frame bytes), explicit argument lists; exact match verified; names and types await human review. */
struct Tag {};
struct SVec { short *data; unsigned size; unsigned cap; };
extern "C" void FUN_00166150(SVec *, unsigned);
extern "C" void FUN_00165f20(SVec *, unsigned, const short *);

inline void Fill(short *p, unsigned m, const short *x, Tag)
{
  for (; m != 0; m--) {
    *p = *x;
    p++;
  }
}
extern "C" void FUN_0016578c(SVec *v, unsigned n, const short *x)
{
  if (n > v->cap || v->cap - n < v->size) {
    FUN_00166150(v, v->size + n - v->cap);
  } else {
    short *p = v->data + v->size;
    Fill(p, n, x, Tag());
    v->size += n;
    return;
  }
  FUN_00165f20(v, n, x);
}
