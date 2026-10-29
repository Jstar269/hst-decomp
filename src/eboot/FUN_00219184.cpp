/* HSTMATCH module=EBOOT.BIN start=0x00219184 end=0x00219210 symbol=FUN_00219184 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/particle_sys.h"

extern "C" {
extern void FUN_000006e8(...);
extern void FUN_00000a00(...);
extern void FUN_002190e4(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: frees the particle array, then the view object. */
extern "C" ParticleSys * FUN_00219184(ParticleSys *sys,short flags)
{
  VC_0 *view;
  
  if (sys != (ParticleSys *)0x0) {
    if (sys->parts != 0) {
      FUN_000006e8(sys->parts,FUN_002190e4);
      sys->parts = 0;
    }
    view = (VC_0 *)sys->view;
    if (view != (VC_0 *)0x0) {
      delete view;
      sys->view = 0;
    }
    if (0 < flags) {
      FUN_00000a00(sys);
    }
  }
  return sys;
}
