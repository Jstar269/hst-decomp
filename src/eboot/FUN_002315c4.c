/* HSTMATCH module=EBOOT.BIN start=0x002315c4 end=0x00231614 symbol=FUN_002315c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern SingletonHolder * DAT_0034a65c;  /* the singleton */
extern u8 DAT_0034a678;
extern int FUN_00231280();
extern void FUN_0023466c();

/* Update the singleton, if it exists; while it is pending, run the follow-up on DAT_0034a678. */
void FUN_002315c4(void)
{
  if ((DAT_0034a65c != (SingletonHolder *)0x0) && (FUN_00231280(DAT_0034a65c), DAT_0034a65c->pending == HOLDER_PENDING_SET)) {
    FUN_0023466c((int *)&DAT_0034a678);
  }
}
