/* HSTMATCH module=EBOOT.BIN start=0x00222a00 end=0x00222b40 symbol=FUN_00222a00 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed deleting virtual calls and retained the duplicated global-pointer check with its zero-store arm; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309664;
extern u32 DAT_0034a264;
extern int * DAT_0034a268;
extern int * DAT_0034a26c;
extern "C" void FUN_00000a00(void *);
extern "C" u32 * FUN_00102ea4(u32 *,int);

struct Destroyable {
  virtual void destroy(int);
};

extern "C" u32 * FUN_00222a00(u32 *param_1,short param_2)
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309664);
    DAT_0034a264 = 0;
    piVar1 = (int *)param_1[0x27];
    if (piVar1 != (int *)0x0) {
      if (piVar1 != (int *)0x0) {
        ((Destroyable *)piVar1)->destroy(1);
      }
      param_1[0x27] = 0;
    }
    piVar1 = DAT_0034a268;
    if (DAT_0034a268 != (int *)0x0) {
      if (DAT_0034a268 != (int *)0x0) {
        piVar2 = (int *)*DAT_0034a268;
        if (piVar2 != (int *)0x0) {
          if (piVar2 != (int *)0x0) {
            ((Destroyable *)piVar2)->destroy(1);
            *piVar1 = 0;
          }
          else
            *piVar1 = 0;
        }
        FUN_00000a00(piVar1);
      }
      DAT_0034a268 = (int *)0x0;
    }
    piVar1 = DAT_0034a26c;
    if (DAT_0034a26c != (int *)0x0) {
      if (DAT_0034a26c != (int *)0x0) {
        piVar2 = (int *)*DAT_0034a26c;
        if (piVar2 != (int *)0x0) {
          if (piVar2 != (int *)0x0) {
            ((Destroyable *)piVar2)->destroy(1);
            *piVar1 = 0;
          }
          else
            *piVar1 = 0;
        }
        FUN_00000a00(piVar1);
      }
      DAT_0034a26c = (int *)0x0;
    }
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
