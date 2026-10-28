/* HSTMATCH module=EBOOT.BIN start=0x001943bc end=0x00194400 symbol=FUN_001943bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341730;
extern u32 DAT_0034173c;
extern u32 DAT_00341740;

u32 FUN_001943bc(void)
{
  if (DAT_00341740 == 0) goto zero;
  if (DAT_0034173c == 0) goto zero;
  if (DAT_00341730 == 0) goto zero;
  return 1;
zero:
  return 0;
}
