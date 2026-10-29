/* HSTMATCH module=hstp_trans_main.prx start=0x00298368 end=0x002983b4 symbol=FUN_00298368 lang=c99 */
/* Clone of src/eboot/FUN_00286c6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_actor.h"

extern u32 * FUN_0015827c(void *, int, int, int);
extern int FUN_00158308(void *, int);
extern u32 * FUN_001583fc(void *, void *);

/* Resets the actor's first 36-byte object to a freshly constructed (empty) one. */
void FUN_00298368(CmdActor *self)
{
  u8 blank[36];

  FUN_0015827c(blank,0,0,0);
  FUN_001583fc(self->objA,blank);
  FUN_00158308(blank,0xffffffff);
}
