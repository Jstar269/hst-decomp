/* HSTMATCH module=hstp_trans_main.prx start=0x000465ec end=0x00046618 symbol=FUN_000465ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ba2cc;
extern int FUN_002c75b8();

bool FUN_000465ec(void)
{
  int iVar1;
  
  iVar1 = FUN_002c75b8();
  return DAT_003ba2cc == iVar1;
}
