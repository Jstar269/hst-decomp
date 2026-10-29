/* HSTMATCH module=EBOOT.BIN start=0x002314f8 end=0x002315c4 symbol=FUN_002314f8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern "C" {
extern u8 DAT_00309820;
extern SingletonHolder * DAT_0034a65c;  /* the singleton holder */
extern u32 DAT_0034a660;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
}
struct Target { virtual ~Target(); };

/* Deleting destructor of the singleton's owner: tear down the holder and its target, then the base. */
extern "C" u32 * FUN_002314f8(u32 *self,short flags)
{
  SingletonHolder *holder;
  Target *target;
  
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_00309820);
    DAT_0034a660 = 0;
    holder = DAT_0034a65c;
    if (DAT_0034a65c != (SingletonHolder *)0x0) {
      if (DAT_0034a65c != (SingletonHolder *)0x0) {
        DAT_0034a65c = (SingletonHolder *)0x0;
        target = (Target *)holder->target;
        if (target != (Target *)0x0) {
          delete target;
          holder->target = 0;
        }
        FUN_00000a00(holder);
      }
      DAT_0034a65c = (SingletonHolder *)0x0;
    }
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
