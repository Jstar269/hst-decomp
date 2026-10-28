/* HSTMATCH module=EBOOT.BIN start=0x00111010 end=0x00111044 symbol=FUN_00111010 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034176c;
extern void FUN_001031e8();

void FUN_00111010(void)
{
  *(u8 *)(DAT_0034176c + 0x88) = 1;
  FUN_001031e8();
  *(u8 *)(DAT_0034176c + 0x88) = 0;
}
