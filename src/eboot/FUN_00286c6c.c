/* HSTMATCH module=EBOOT.BIN start=0x00286c6c end=0x00286cb8 symbol=FUN_00286c6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_actor.h"

extern u32 * FUN_0014c794(void *, int, int, int);
extern int FUN_0014c820(void *, int);
extern u32 * FUN_0014c914(void *, void *);

/* Resets the actor's first 36-byte object to a freshly constructed (empty) one. */
void FUN_00286c6c(CmdActor *self)
{
  u8 blank[36];

  FUN_0014c794(blank,0,0,0);
  FUN_0014c914(self->objA,blank);
  FUN_0014c820(blank,0xffffffff);
}
