/* HSTMATCH module=hstp_trans_main.prx start=0x00198514 end=0x00198530 symbol=FUN_00198514 lang=c99 */
/* Clone of src/eboot/FUN_0018bd64.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ba2f8;
extern void FUN_00197eec();

void FUN_00198514(int param_1)
{
  *(u8 *)(param_1 + 0x44) = 1;
  DAT_003ba2f8 = (unsigned int)(FUN_00197eec);
}
