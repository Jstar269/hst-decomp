/* HSTMATCH module=hstp_trans_main.prx start=0x00231f74 end=0x002320b4 symbol=FUN_00231f74 lang=c++ */
/* Clone of src/eboot/global_cleanup_00222a00.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed deleting virtual calls and retained the duplicated global-pointer check with its zero-store arm; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2930;
extern u32 DAT_003f3594;
extern int * DAT_003f3598;
extern int * DAT_003f359c;
extern "C" void FUN_00000a00(void *);
extern "C" u32 * FUN_001087a8(u32 *,int);

struct Destroyable {
  virtual void destroy(int);
};

extern "C" u32 * FUN_00231f74(u32 *param_1,short param_2)
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2930);
    DAT_003f3594 = 0;
    piVar1 = (int *)param_1[0x27];
    if (piVar1 != (int *)0x0) {
      if (piVar1 != (int *)0x0) {
        ((Destroyable *)piVar1)->destroy(1);
      }
      param_1[0x27] = 0;
    }
    piVar1 = DAT_003f3598;
    if (DAT_003f3598 != (int *)0x0) {
      if (DAT_003f3598 != (int *)0x0) {
        piVar2 = (int *)*DAT_003f3598;
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
      DAT_003f3598 = (int *)0x0;
    }
    piVar1 = DAT_003f359c;
    if (DAT_003f359c != (int *)0x0) {
      if (DAT_003f359c != (int *)0x0) {
        piVar2 = (int *)*DAT_003f359c;
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
      DAT_003f359c = (int *)0x0;
    }
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
