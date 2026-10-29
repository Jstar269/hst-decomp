/* HSTMATCH module=EBOOT.BIN start=0x00293194 end=0x002931f0 symbol=FUN_00293194 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object and float parameters and an unsigned flag; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ctl_obj.h"

extern int DAT_00331b84;
extern void FUN_00063a30();

/* Resets the control object with level CTL_LEVEL_MAX and the given start value. */
void FUN_00293194(CtlObj *ctl,float start)
{
  ctl->unk40 = 0;
  ctl->unk4 = 30.0f;
  ctl->unk8 = 30.0f;
  ctl->level = 0.0f;
  ctl->level = CTL_LEVEL_MAX;
  ctl->unk4c = 0;
  ctl->active = 0;
  ctl->start = start;
  ctl->unk54 = 0;
  if (ctl->mode == 0) {
    FUN_00063a30(DAT_00331b84,0xf);
  }
}
