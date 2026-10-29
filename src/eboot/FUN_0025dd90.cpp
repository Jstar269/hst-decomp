/* HSTMATCH module=EBOOT.BIN start=0x0025dd90 end=0x0025dde8 symbol=FUN_0025dd90 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003386c0;
extern void FUN_001031e8(...);
}
struct GlobalObj { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };
struct Query { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual int m(); };

extern "C" void FUN_0025dd90(Query *self)
{
  int result;
  
  ((GlobalObj *)(DAT_003386c0))->m(1);
  result = self->m();
  if (result != 0) {
    FUN_001031e8(self);
  }
}
