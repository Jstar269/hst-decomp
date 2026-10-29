/* HSTMATCH module=hstp_trans_main.prx start=0x00100c0c end=0x00100c40 symbol=FUN_00100c0c lang=c99 */
/* Clone of src/eboot/FUN_000fb4d0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern void FUN_000fc08c(void *target,int rank,float *pos);

/* Forward (rank, pos) to the core's second target, if there is one. */
void FUN_00100c0c(ModeScreen *self,int rank,float *pos)
{
  void *target;
  
  if ((self->core != 0) &&
     (target = self->core->targetB, target != 0)) {
    FUN_000fc08c(target,rank,pos);
  }
}
