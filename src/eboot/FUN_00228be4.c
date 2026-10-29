/* HSTMATCH module=EBOOT.BIN start=0x00228be4 end=0x00228c7c symbol=FUN_00228be4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/court_prop.h"

extern void FUN_0005f1e8();

/* When both flag bytes are set, calls FUN_0005f1e8 on the embedded object chosen by the state (states 1, 2, 4: the first; 3, 5: the second). */
void FUN_00228be4(CourtProp *prop)
{
  int state;
  
  if ((prop->unk435 != '\0') && (prop->unk436 != '\0')) {
    state = prop->state;
    if (state == 1) {
      FUN_0005f1e8(prop->unkb0,0);
    }
    else if ((state == 2) || (state == 4)) {
      FUN_0005f1e8(prop->unkb0,0);
    }
    else if ((state == 3) || (state == 5)) {
      FUN_0005f1e8(prop->unk260,0);
    }
  }
}
