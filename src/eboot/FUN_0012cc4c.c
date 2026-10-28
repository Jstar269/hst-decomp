/* HSTMATCH module=EBOOT.BIN start=0x0012cc4c end=0x0012ccd0 symbol=FUN_0012cc4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00308108;
extern u8 DAT_00308124;
extern u32 DAT_003313c4;
extern u32 DAT_0033b574;
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();
extern u32 * FUN_0013fb58();
extern u32 * FUN_00286790();

u32 * FUN_0012cc4c(u32 *param_1)
{
  u8 auStack_2c0 [704];
  
  FUN_0013fb58();
  FUN_00286790(param_1 + 0x4c8);
  *param_1 = (unsigned int)(&DAT_00308108);
  param_1[0x4c8] = (unsigned int)(&DAT_00308124);
  param_1[0x4e4] = 0;
  param_1[0x4e5] = 0;
  param_1[0x4e6] = 0;
  param_1[0x4e7] = 0;
  DAT_0033b574 = (unsigned int)(param_1);
  FUN_0005b670(auStack_2c0);
  FUN_0005ba78(DAT_003313c4,auStack_2c0);
  FUN_0005ba00(auStack_2c0,0xffffffff);
  return param_1;
}
