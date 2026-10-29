/* HSTMATCH module=hstp_trans_main.prx start=0x00238158 end=0x002381f0 symbol=FUN_00238158 lang=c99 */
/* Clone of src/eboot/FUN_00228be4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/court_prop.h"

extern void FUN_0005ffd8();

/* When both flag bytes are set, calls FUN_0005ffd8 on the embedded object chosen by the state (states 1, 2, 4: the first; 3, 5: the second). */
void FUN_00238158(CourtProp *prop)
{
  int state;
  
  if ((prop->unk435 != '\0') && (prop->unk436 != '\0')) {
    state = prop->state;
    if (state == 1) {
      FUN_0005ffd8(prop->unkb0,0);
    }
    else if ((state == 2) || (state == 4)) {
      FUN_0005ffd8(prop->unkb0,0);
    }
    else if ((state == 3) || (state == 5)) {
      FUN_0005ffd8(prop->unk260,0);
    }
  }
}
