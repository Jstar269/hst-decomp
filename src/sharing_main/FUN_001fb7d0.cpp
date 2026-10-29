/* HSTMATCH module=hstp_trans_main.prx start=0x001fb7d0 end=0x001fb818 symbol=FUN_001fb7d0 lang=c++ */
/* Clone of src/eboot/FUN_001ed460.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/prize_camera.h"

struct VC_0 { virtual ~VC_0(); };

/* Deletes the csv reader and clears the pointer. */
extern "C" void FUN_001fb7d0(PrizeCamera *cam)
{
  VC_0 *res;
  
  res = (VC_0 *)cam->res;
  if (res != (VC_0 *)0x0) {
    delete res;
    cam->res = 0;
  }
}
