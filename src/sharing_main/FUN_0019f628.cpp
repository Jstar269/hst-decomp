/* HSTMATCH module=hstp_trans_main.prx start=0x0019f628 end=0x0019f69c symbol=FUN_0019f628 lang=c++ */
/* Clone of src/eboot/FUN_00192e18.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pose_holder.h"

extern "C" {
extern void FUN_0019f69c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Releases the two owned objects after the list cleanup call. */
extern "C" void FUN_0019f628(PoseHolder *self)
{
  void *owned;
  
  FUN_0019f69c();
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
