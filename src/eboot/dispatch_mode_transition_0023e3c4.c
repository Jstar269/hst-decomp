/* HSTMATCH module=EBOOT.BIN start=0x0023e3c4 end=0x0023e468 symbol=FUN_0023e3c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else to if (step > 0); readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/mode_host.h"

extern void FUN_00217548(void *, int, int, u32);
extern void FUN_00217588(void *, int);
extern void FUN_0023de6c(void *, int, int);

/* Starts a transition on the host's control record; the sign of step picks the variant (0 for positive, 1 otherwise). */
void FUN_0023e3c4(ModeHost *host, int step, u32 arg)
{
  if (step > 0) {
    FUN_00217588(host->ctl, 0);
    FUN_0023de6c(host, 1, -1);
    FUN_00217548(host->ctl, 0, step, arg);
  }
  else {
    FUN_00217588(host->ctl, 1);
    FUN_0023de6c(host, 1, 0);
    FUN_00217548(host->ctl, 1, step, arg);
  }
}
