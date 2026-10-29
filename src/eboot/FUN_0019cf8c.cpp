/* HSTMATCH module=EBOOT.BIN start=0x0019cf8c end=0x0019d02c symbol=FUN_0019cf8c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/save_task.h"

extern "C" {
extern u8 DAT_003091cc;
extern void *DAT_003415d4; /* save menu */
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00190848(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: drop the owned object, call FUN_00190848 on the save menu, run the base destructor. */
extern "C" SaveTask * FUN_0019cf8c(SaveTask *self,short flags)
{
  int *owned;
  
  if (self != (SaveTask *)0x0) {
    self->vtable = &DAT_003091cc;
    owned = (int *)self->owned;
    if (owned != (int *)0x0) {
      delete ((VC_0 *)(owned));
      self->owned = 0;
    }
    if (DAT_003415d4 != 0) {
      FUN_00190848(DAT_003415d4);
    }
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
