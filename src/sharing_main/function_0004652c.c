/* HSTMATCH module=hstp_trans_main.prx start=0x0004652c end=0x0004658c symbol=FUN_0004652c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_000465ec as int and split the short-circuit checks into early guards; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00375968;
extern u32 DAT_003ba300;
extern u32 DAT_003f39a8;
extern int FUN_000465ec();
extern void FUN_00061070();

void FUN_0004652c(void)
{
  if (FUN_000465ec() == 0) return;
  if (DAT_003ba300 == 0) return;
  if (DAT_00375968 == 0) return;
  if (DAT_003f39a8 == 0x21) return;
  FUN_00061070(DAT_003ba300,1);
}
