/* HSTMATCH module=hstp_trans_main.prx start=0x0017197c end=0x00171a30 symbol=FUN_0017197c lang=c++ */
/* Clone of src/eboot/vec_short_append_n_0016578c.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed short vector, if/else with the fill branch returning and the grow branch falling into the append call, || with the cap compare written n > cap, signed short fill through an inline helper taking an unused empty Tag by value (the 16 extra frame bytes), explicit argument lists; exact match verified; names and types await human review. */
struct Tag {};
struct SVec { short *data; unsigned size; unsigned cap; };
extern "C" void FUN_00172314(SVec *, unsigned);
extern "C" void FUN_001720e4(SVec *, unsigned, const short *);

inline void Fill(short *p, unsigned m, const short *x, Tag)
{
  for (; m != 0; m--) {
    *p = *x;
    p++;
  }
}
extern "C" void FUN_0017197c(SVec *v, unsigned n, const short *x)
{
  if (n > v->cap || v->cap - n < v->size) {
    FUN_00172314(v, v->size + n - v->cap);
  } else {
    short *p = v->data + v->size;
    Fill(p, n, x, Tag());
    v->size += n;
    return;
  }
  FUN_001720e4(v, n, x);
}
