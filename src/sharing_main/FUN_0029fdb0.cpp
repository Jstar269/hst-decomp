/* HSTMATCH module=hstp_trans_main.prx start=0x0029fdb0 end=0x0029fdf4 symbol=FUN_0029fdb0 lang=c++ */
/* Clone of src/eboot/FUN_0028e5e8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/titleinfo_menu.h"

extern "C" {
extern void FUN_00108f54(...);
extern void FUN_0029fdf4(...);
}
struct TitleInfoNotify { virtual void d0(); virtual void d1(); virtual void m(int); };

extern "C" void FUN_0029fdb0(TitleInfoHead *self)
{
  FUN_00108f54(self,1);
  self->notify->m(0);
  FUN_0029fdf4(self);
}
