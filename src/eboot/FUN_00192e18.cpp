/* HSTMATCH module=EBOOT.BIN start=0x00192e18 end=0x00192e8c symbol=FUN_00192e18 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pose_holder.h"

extern "C" {
extern void FUN_00192e8c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Releases the two owned objects after the list cleanup call. */
extern "C" void FUN_00192e18(PoseHolder *self)
{
  void *owned;
  
  FUN_00192e8c();
  owned = self->objA;
  if (owned != (void *)0x0) {
    delete ((VC_0 *)(owned));
    self->objA = 0;
  }
  owned = self->objB;
  if (owned != (void *)0x0) {
    delete ((VC_1 *)(owned));
    self->objB = 0;
  }
}
