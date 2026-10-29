/* HSTMATCH module=EBOOT.BIN start=0x001c5f54 end=0x001c5fc4 symbol=FUN_001c5f54 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: passed the named module address and two state values to the helper; readability pass; exact match verified; names and types await human review. */
#include "hst/phase_obj.h"

enum { PHASE_RESET = 2 };

extern int DAT_002ea610;
extern void FUN_001b2430();
extern void FUN_001c725c(PhaseObj *,int,int);
extern int DAT_0034179c;

/* Once the timer passes the limit: runs the helper (when both stored values are valid) and resets the phase and timer. */
void FUN_001c5f54(PhaseObj *obj)
{
  if (DAT_002ea610 < obj->timer) {
    FUN_001b2430(&DAT_0034179c);
    int first = obj->unkd4;
    if (first >= 0) {
      int second = obj->unkd8;
      if (second >= 0) {
        FUN_001c725c(obj,first,second);
      }
    }
    obj->state = PHASE_RESET;
    obj->timer = 0;
  }
  return;
}
