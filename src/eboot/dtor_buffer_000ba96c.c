/* HSTMATCH module=EBOOT.BIN start=0x000ba96c end=0x000ba9e0 symbol=FUN_000ba96c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the free call takes the tested member (FUN_000009e4(param_1[2])); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073e4;
extern void FUN_000009e4(u32);
extern void FUN_00000a00();

u32 * FUN_000ba96c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003073e4);
    if (param_1[2] != 0) {
      FUN_000009e4(param_1[2]);
      param_1[2] = 0;
    }
    param_1[1] = 0;
    param_1[3] = 0;
    *(u8 *)(param_1 + 4) = 0;
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
