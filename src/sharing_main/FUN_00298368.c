/* HSTMATCH module=hstp_trans_main.prx start=0x00298368 end=0x002983b4 symbol=FUN_00298368 lang=c99 */
/* Clone of src/eboot/FUN_00286c6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0015827c();
extern int FUN_00158308();
extern u32 * FUN_001583fc();

void FUN_00298368(int param_1)
{
  u8 auStack_24 [36];
  
  FUN_0015827c(auStack_24,0,0,0);
  FUN_001583fc(*(u32 *)(param_1 + 8),auStack_24);
  FUN_00158308(auStack_24,0xffffffff);
}
