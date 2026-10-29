/* HSTMATCH module=EBOOT.BIN start=0x001ed460 end=0x001ed4a8 symbol=FUN_001ed460 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/prize_camera.h"

struct VC_0 { virtual ~VC_0(); };

/* Deletes the csv reader and clears the pointer. */
extern "C" void FUN_001ed460(PrizeCamera *cam)
{
  VC_0 *res;
  
  res = (VC_0 *)cam->res;
  if (res != (VC_0 *)0x0) {
    delete res;
    cam->res = 0;
  }
}
