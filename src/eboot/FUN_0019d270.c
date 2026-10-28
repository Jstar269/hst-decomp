/* HSTMATCH module=EBOOT.BIN start=0x0019d270 end=0x0019d30c symbol=FUN_0019d270 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307f60;
extern u8 DAT_003091e8;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern int * FUN_00107514();

u32 * FUN_0019d270(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003091e8);
    if (param_1 != (u32 *)0x0) {
      puVar1 = param_1 + 0x48;
      *param_1 = (unsigned int)(&DAT_00307f60);
      if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
        FUN_00107514(puVar1,0);
      }
      if (param_1 != (u32 *)0x0) {
        *param_1 = (unsigned int)(&DAT_0030779c);
        FUN_00100b24(param_1,0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
