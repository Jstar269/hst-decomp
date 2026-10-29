/* HSTMATCH module=hstp_trans_main.prx start=0x001382bc end=0x0013830c symbol=FUN_001382bc lang=c99 */
/* Clone of src/eboot/FUN_0012ce50.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003da704;
extern u32 DAT_003e1a54;
extern int FUN_0005c700();
extern void FUN_0014c118();
extern void FUN_0015142c();

/* Teardown step: passes the registry to the object registered in DAT_003e1a54 (if any), then runs the two cleanup calls. */
void FUN_001382bc(u32 obj)
{
  if (DAT_003e1a54 != 0) {
    FUN_0005c700(DAT_003e1a54,DAT_003da704);
  }
  FUN_0014c118(obj);
  FUN_0015142c(obj);
}
