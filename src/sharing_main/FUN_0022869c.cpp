/* HSTMATCH module=hstp_trans_main.prx start=0x0022869c end=0x00228728 symbol=FUN_0022869c lang=c++ */
/* Clone of src/eboot/FUN_00219184.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/particle_sys.h"

extern "C" {
extern void FUN_000006e8(...);
extern void FUN_00000a00(...);
extern void FUN_002285fc(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: frees the particle array, then the view object. */
extern "C" ParticleSys * FUN_0022869c(ParticleSys *sys,short flags)
{
  VC_0 *view;
  
  if (sys != (ParticleSys *)0x0) {
    if (sys->parts != 0) {
      FUN_000006e8(sys->parts,FUN_002285fc);
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
