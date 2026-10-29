/* HSTMATCH module=hstp_trans_main.prx start=0x00232608 end=0x00232650 symbol=FUN_00232608 lang=c++ */
/* Clone of src/eboot/FUN_00223094.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern "C" {
extern void FUN_00108f54(...);
}
/* Virtual view of the child object: slot 1 is called with 1. */
struct ChildV { virtual void d0(); virtual void m(int); };

/* Hides the pane and calls the child object. */
extern "C" void FUN_00232608(ChildPane *pane)
{
  ChildV *child;

  FUN_00108f54(pane,0);
  pane->active = 0;
  child = (ChildV *)pane->child;
  if (child != 0) {
    child->m(1);
  }
}
