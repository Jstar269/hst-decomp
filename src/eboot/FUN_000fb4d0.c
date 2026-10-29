/* HSTMATCH module=EBOOT.BIN start=0x000fb4d0 end=0x000fb504 symbol=FUN_000fb4d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern void FUN_000f6998(void *target,int rank,float *pos);

/* Forward (rank, pos) to the core's second target, if there is one. */
void FUN_000fb4d0(ModeScreen *self,int rank,float *pos)
{
  void *target;
  
  if ((self->core != 0) &&
     (target = self->core->targetB, target != 0)) {
    FUN_000f6998(target,rank,pos);
  }
}
