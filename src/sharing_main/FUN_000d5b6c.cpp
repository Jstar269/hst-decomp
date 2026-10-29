/* HSTMATCH module=hstp_trans_main.prx start=0x000d5b6c end=0x000d5bd0 symbol=FUN_000d5b6c lang=c++ */
/* Clone of src/eboot/FUN_000d1f3c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void m(int, int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void m(int, int); };

/* Call the same two-argument virtual method through two different vtable slots of the object. */
extern "C" void FUN_000d5b6c(int *obj,u32 a,u32 b,u32 c, u32 d)
{
  ((VC_0 *)(obj))->m((int)(c), (int)(d));
  ((VC_1 *)(obj))->m((int)(a), (int)(b));
}
