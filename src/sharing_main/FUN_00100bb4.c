/* HSTMATCH module=hstp_trans_main.prx start=0x00100bb4 end=0x00100be8 symbol=FUN_00100bb4 lang=c99 */
/* Clone of src/eboot/FUN_000fb478.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern void FUN_000fc08c(void *target,int rank,float *pos);

/* Forward (rank, pos) to the core's first target, if there is one. */
void FUN_00100bb4(ModeScreen *self,int rank,float *pos)
{
  ModeTarget *target;
  
  if ((self->core != 0) &&
     (target = self->core->targetA, target != 0)) {
    FUN_000fc08c(target,rank,pos);
  }
}
