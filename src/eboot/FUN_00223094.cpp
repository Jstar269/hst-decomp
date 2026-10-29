/* HSTMATCH module=EBOOT.BIN start=0x00223094 end=0x002230dc symbol=FUN_00223094 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern "C" {
extern void FUN_00103628(...);
}
/* Virtual view of the child object: slot 1 is called with 1. */
struct ChildV { virtual void d0(); virtual void m(int); };

/* Hides the pane and calls the child object. */
extern "C" void FUN_00223094(ChildPane *pane)
{
  ChildV *child;

  FUN_00103628(pane,0);
  pane->active = 0;
  child = (ChildV *)pane->child;
  if (child != 0) {
    child->m(1);
  }
}
