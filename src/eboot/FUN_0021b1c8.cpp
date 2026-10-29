/* HSTMATCH module=EBOOT.BIN start=0x0021b1c8 end=0x0021b208 symbol=FUN_0021b1c8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00103628(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Calls FUN_00103628 with 0, clears the flag at 0x5c, then calls slot 1 of the object at 0x78 with 0. */
extern "C" void FUN_0021b1c8(int self)
{
  FUN_00103628(self,0);
  *(u8 *)(self + 0x5c) = 0;
  ((VC_0 *)(*(int **)(self + 0x78)))->m((int)(0));
}
