/* HSTMATCH module=hstp_trans_main.prx start=0x001f3c0c end=0x001f3c4c symbol=FUN_001f3c0c lang=c99 */
/* Clone of src/eboot/member_callback_after_lookup_001e59f4.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_001f08e8 as receiver-only; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001f08e8(int);
extern void FUN_0023212c();

void FUN_001f3c0c(int param_1,u32 param_2)
{
  FUN_001f08e8(param_1);
  FUN_0023212c(*(u32 *)(param_1 + 0x1954),param_2,1);
}
