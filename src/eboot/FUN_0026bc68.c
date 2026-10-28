/* HSTMATCH module=EBOOT.BIN start=0x0026bc68 end=0x0026bccc symbol=FUN_0026bc68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386c8;
extern int * FUN_0025c474();
extern int * FUN_0025de54();
extern int * FUN_00261e1c();
extern int * FUN_00269798();
extern int * FUN_0026b590();

u32 * FUN_0026bc68(u32 *param_1)
{
  *param_1 = *(u32 *)(DAT_003386c8 + 0x40);
  FUN_00269798(param_1 + 1);
  FUN_0025de54(param_1 + 0x44);
  FUN_0025c474(param_1 + 0x1bc);
  FUN_00261e1c(param_1 + 0x2af);
  FUN_0026b590(param_1 + 0x2d2);
  param_1[0x2ee] = 0;
  param_1[0x2f2] = 0;
  return param_1;
}
