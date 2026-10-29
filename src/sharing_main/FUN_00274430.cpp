/* HSTMATCH module=hstp_trans_main.prx start=0x00274430 end=0x002744c0 symbol=FUN_00274430 lang=c++ */
/* Clone of src/eboot/FUN_002635b4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_manager.h"

extern "C" {
extern u8 DAT_003b2d20;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_002645b8(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Manager deleting destructor: delete the owned screen, run the base destructors, free when delete_flag is positive. */
extern "C" ScreenManager * FUN_00274430(ScreenManager *self,short delete_flag)
{
  ScreenObj *screen;
  
  if (self != (ScreenManager *)0x0) {
    self->vtable = &DAT_003b2d20;
    screen = self->screen;
    if (screen != (ScreenObj *)0x0) {
      delete ((VC_0 *)(screen));
      self->screen = 0;
    }
    FUN_002645b8();
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
