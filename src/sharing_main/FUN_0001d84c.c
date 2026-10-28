/* HSTMATCH module=hstp_trans_main.prx start=0x0001d84c end=0x0001d8c8 symbol=FUN_0001d84c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the copied globals as bytes to preserve retail byte loads and stores; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern u8 DAT_003b8f40;
extern u8 DAT_003b910c;
extern u8 DAT_003b910d;
extern u8 DAT_003b910e;
extern u8 DAT_003b910f;
extern u8 DAT_003b9110;
extern u8 DAT_003b9111;
extern u8 DAT_003b9112;
extern u8 DAT_003b9113;
extern void FUN_0001deb4();
extern u32 FUN_0001ebdc();

void FUN_0001d84c(void)
{
  DAT_003751d4 = (unsigned int)(&DAT_003b8f40);
  DAT_003b910c = DAT_003b9110;
  DAT_003b910d = DAT_003b9111;
  DAT_003b910e = DAT_003b9112;
  DAT_003b910f = DAT_003b9113;
  FUN_0001ebdc(&DAT_003b9110);
  FUN_0001deb4(DAT_003751d4);
}
