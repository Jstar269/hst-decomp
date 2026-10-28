/* HSTMATCH module=EBOOT.BIN start=0x0026397c end=0x00263a40 symbol=FUN_0026397c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed the float argument and deallocation receiver; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309aac;
extern u32 DAT_00331b84;
extern u32 DAT_003415ac;
extern void FUN_00000a00(u32 *);
extern void FUN_00063478(float,u32);
extern void FUN_00103628(u32, int);
extern u32 * FUN_00258180();
extern u32 * FUN_0025e600();

u32 * FUN_0026397c(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309aac);
    FUN_00063478(203000.0f,DAT_00331b84);
    FUN_00103628(DAT_003415ac,1);
    *(u8 *)(param_1[400] + 0x616) = 0;
    *(u8 *)(param_1[400] + 0x736) = 0;
    *(u8 *)(param_1[400] + 0x856) = 0;
    *(u8 *)(param_1[400] + 0x617) = 0;
    *(u8 *)(param_1[400] + 0x737) = 0;
    *(u8 *)(param_1[400] + 0x857) = 0;
    FUN_0025e600(param_1 + 0x618,-1);
    FUN_00258180(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
