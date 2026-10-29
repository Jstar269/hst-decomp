/* HSTMATCH module=EBOOT.BIN start=0x002635b4 end=0x00263644 symbol=FUN_002635b4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_manager.h"

extern "C" {
extern u8 DAT_00309a38;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00254114(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Manager deleting destructor: delete the owned screen, run the base destructors, free when delete_flag is positive. */
extern "C" ScreenManager * FUN_002635b4(ScreenManager *self,short delete_flag)
{
  ScreenObj *screen;
  
  if (self != (ScreenManager *)0x0) {
    self->vtable = &DAT_00309a38;
    screen = self->screen;
    if (screen != (ScreenObj *)0x0) {
      delete ((VC_0 *)(screen));
      self->screen = 0;
    }
    FUN_00254114();
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
