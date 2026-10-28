/* HSTMATCH module=EBOOT.BIN start=0x00118258 end=0x001182ac symbol=FUN_00118258 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307ffc;
extern u32 DAT_0033b460;
extern u32 * FUN_0001f06c();
extern u32 FUN_0011835c();
extern u32 FUN_00118424();
extern void FUN_00118598();

u32 * FUN_00118258(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307ffc);
  FUN_00118424(param_1 + 0xb8);
  FUN_0011835c(param_1 + 0xbe);
  DAT_0033b460 = (unsigned int)(param_1);
  FUN_00118598(param_1);
  return param_1;
}
