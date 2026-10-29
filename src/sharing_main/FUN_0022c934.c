/* HSTMATCH module=hstp_trans_main.prx start=0x0022c934 end=0x0022c96c symbol=FUN_0022c934 lang=c99 */
/* Clone of src/eboot/FUN_0021b79c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

/* Puts the screen in its finished state: finished flag set, counter idle (-1). */
void FUN_0022c934(int self)
{
  FUN_00108f54(self,1);
  *(u8 *)(self + 0x54) = 1;
  *(u32 *)(self + 100) = 0xffffffff;
}
