/* HSTMATCH module=hstp_trans_main.prx start=0x000d8e88 end=0x000d8ef0 symbol=FUN_000d8e88 lang=c++ */
/* Clone of src/eboot/FUN_000d5198.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* The same object seen through two virtual interfaces: the first calls slot 7 (three ints), the second slot 10 (two ints). */
struct FirstIface { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(int, int, int); };
struct SecondIface { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void m(int, int); };

/* Forwards the last three arguments to one virtual method and the first two to another. */
extern "C" void FUN_000d8e88(void *self,int a,int b,int c, int d,int e)
{
  ((FirstIface *)(self))->m(c, d, e);
  ((SecondIface *)(self))->m(a, b);
}
