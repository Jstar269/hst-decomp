/* HSTMATCH module=hstp_trans_main.prx start=0x001aa4c8 end=0x001aa568 symbol=FUN_001aa4c8 lang=c++ */
/* Clone of src/eboot/FUN_0019cf8c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/save_task.h"

extern "C" {
extern u8 DAT_003b2498;
extern void *DAT_003ea914; /* save menu */
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_0019d058(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: drop the owned object, call FUN_0019d058 on the save menu, run the base destructor. */
extern "C" SaveTask * FUN_001aa4c8(SaveTask *self,short flags)
{
  int *owned;
  
  if (self != (SaveTask *)0x0) {
    self->vtable = &DAT_003b2498;
    owned = (int *)self->owned;
    if (owned != (int *)0x0) {
      delete ((VC_0 *)(owned));
      self->owned = 0;
    }
    if (DAT_003ea914 != 0) {
      FUN_0019d058(DAT_003ea914);
    }
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
