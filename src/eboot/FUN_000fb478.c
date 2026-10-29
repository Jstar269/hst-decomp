/* HSTMATCH module=EBOOT.BIN start=0x000fb478 end=0x000fb4ac symbol=FUN_000fb478 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern void FUN_000f6998(void *target,int rank,float *pos);

/* Forward (rank, pos) to the core's first target, if there is one. */
void FUN_000fb478(ModeScreen *self,int rank,float *pos)
{
  ModeTarget *target;
  
  if ((self->core != 0) &&
     (target = self->core->targetA, target != 0)) {
    FUN_000f6998(target,rank,pos);
  }
}
