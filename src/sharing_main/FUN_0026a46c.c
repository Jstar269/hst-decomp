/* HSTMATCH module=hstp_trans_main.prx start=0x0026a46c end=0x0026a4ac symbol=FUN_0026a46c lang=c99 */
/* Clone of src/eboot/FUN_00259fbc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u32 DAT_003eaafc;
extern void FUN_001c2a10();
extern void FUN_00265b24();
extern int FUN_00297288();

/* Feeds the owner's handle, converted by a lookup, to the update helper for its sub-object. */
void FUN_0026a46c(SpawnOwner *owner)
{
  u32 value;
  
  FUN_001c2a10(DAT_003eaafc);
  value = FUN_00297288(owner->handle);
  FUN_00265b24(owner->sub,value);
}
