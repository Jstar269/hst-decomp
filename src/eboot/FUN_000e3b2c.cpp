/* HSTMATCH module=EBOOT.BIN start=0x000e3b2c end=0x000e3ba4 symbol=FUN_000e3b2c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) refined by hstperm.py tag p4 random mutation from try/gen-a7/v20/FUN_000e3b2c.cpp, then readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rec_array_obj.h"

extern "C" {
extern void FUN_000009e4(...);
extern void FUN_000e3ba4(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Release the record array (array delete) and the owned sub-object. */
extern "C" void FUN_000e3b2c(RecArrayObj *self)
{
  if (self->recs != 0) {
    FUN_000e3ba4();
    if (self->recs == 0) {
      goto LAB_000e3b70;
    }
    if (self->recs != 0) {
      FUN_000009e4((char *)self->recs + -0x10);
    }
    self->recs = 0;
  }
LAB_000e3b70:
  if (self->unk40 != 0) {
    delete ((VC_0 *)(self->unk40));
    self->unk40 = 0;
  }
}
