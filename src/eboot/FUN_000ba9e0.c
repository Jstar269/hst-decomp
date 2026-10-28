/* HSTMATCH module=EBOOT.BIN start=0x000ba9e0 end=0x000baa34 symbol=FUN_000ba9e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d4a98;
extern u8 DAT_002d4aa8;

void FUN_000ba9e0(u32 param_1,u32 *param_2)
{
  if (param_2 != (u32 *)0x0) {
    *param_2 = 0x5a4;
    param_2[1] = 0x5a4;
    param_2[2] = 1;
    param_2[3] = 0x10;
    param_2[4] = 0x20000;
    param_2[5] = 0x8000;
    param_2[6] = (unsigned int)(&DAT_002d4a98);
    param_2[7] = (unsigned int)(&DAT_002d4aa8);
  }
}
