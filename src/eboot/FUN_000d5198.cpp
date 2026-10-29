/* HSTMATCH module=EBOOT.BIN start=0x000d5198 end=0x000d5200 symbol=FUN_000d5198 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* The same object seen through two virtual interfaces: the first calls slot 7 (three ints), the second slot 10 (two ints). */
struct FirstIface { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(int, int, int); };
struct SecondIface { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void m(int, int); };

/* Forwards the last three arguments to one virtual method and the first two to another. */
extern "C" void FUN_000d5198(void *self,int a,int b,int c, int d,int e)
{
  ((FirstIface *)(self))->m(c, d, e);
  ((SecondIface *)(self))->m(a, b);
}
