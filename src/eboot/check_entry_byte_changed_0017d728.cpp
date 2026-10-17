/* HSTMATCH module=EBOOT.BIN start=0x0017d728 end=0x0017d7ac symbol=FUN_0017d728 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the two nested conditions are one && chain (the pre-call test and a comma expression with the call and byte compare) feeding if r=1 else r=0, which gives retail's unthreaded beq/b/li/move tail; exact match verified; names and types await human review. */
typedef unsigned char uchar;
struct Obj { char pad[8]; int *tab; };
extern "C" void FUN_00092630(void *, unsigned);
extern "C" int FUN_001fe984(void *, int, int);

extern "C" int FUN_0017d728(Obj *self, int idx, unsigned v)
{
  char *o;
  int r;
  if (FUN_001fe984((char *)self + 0x2e4, idx, 0) == 0 && (o = (char *)self->tab[idx], FUN_00092630(o + 0x10, v), (uchar)v != *(uchar *)(o + 0x85))) r = 1; else r = 0;
  return r;
}
