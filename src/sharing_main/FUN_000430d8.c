/* HSTMATCH module=hstp_trans_main.prx start=0x000430d8 end=0x000430e8 symbol=FUN_000430d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051d38();

void FUN_000430d8(char *param_1)
{
  FUN_00051d38(*(u32 *)(param_1 + 0x19074));
}
