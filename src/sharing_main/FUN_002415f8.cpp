/* HSTMATCH module=hstp_trans_main.prx start=0x002415f8 end=0x002416c4 symbol=FUN_002415f8 lang=c++ */
/* Clone of src/eboot/FUN_002314f8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern "C" {
extern u8 DAT_003b2aec;
extern SingletonHolder * DAT_003f398c;  /* the singleton holder */
extern u32 DAT_003f3990;
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
}
struct Target { virtual ~Target(); };

/* Deleting destructor of the singleton's owner: tear down the holder and its target, then the base. */
extern "C" u32 * FUN_002415f8(u32 *self,short flags)
{
  SingletonHolder *holder;
  Target *target;
  
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003b2aec);
    DAT_003f3990 = 0;
    holder = DAT_003f398c;
    if (DAT_003f398c != (SingletonHolder *)0x0) {
      if (DAT_003f398c != (SingletonHolder *)0x0) {
        DAT_003f398c = (SingletonHolder *)0x0;
        target = (Target *)holder->target;
        if (target != (Target *)0x0) {
          delete target;
          holder->target = 0;
        }
        FUN_00000a00(holder);
      }
      DAT_003f398c = (SingletonHolder *)0x0;
    }
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
