/* HSTMATCH module=EBOOT.BIN start=0x001e0420 end=0x001e05d4 symbol=FUN_001e0420 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s512a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309424;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001e12dc();
extern int FUN_002175d4();

u32 * FUN_001e0420(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309424);
    FUN_001e12dc();
    FUN_002175d4(param_1 + 0xa0a,0xffffffff);
    FUN_002175d4(param_1 + 0x9e7,0xffffffff);
    FUN_002175d4(param_1 + 0x94b,0xffffffff);
    FUN_002175d4(param_1 + 0x920,0xffffffff);
    FUN_002175d4(param_1 + 0x8b1,0xffffffff);
    FUN_002175d4(param_1 + 0x856,0xffffffff);
    FUN_002175d4(param_1 + 0x833,0xffffffff);
    FUN_002175d4(param_1 + 0x810,0xffffffff);
    FUN_002175d4(param_1 + 0x7ed,0xffffffff);
    FUN_002175d4(param_1 + 0x7ca,0xffffffff);
    FUN_002175d4(param_1 + 0x736,0xffffffff);
    FUN_002175d4(param_1 + 0x713,0xffffffff);
    FUN_002175d4(param_1 + 0x6f0,0xffffffff);
    FUN_002175d4(param_1 + 0x6cd,0xffffffff);
    FUN_002175d4(param_1 + 0x632,0xffffffff);
    FUN_002175d4(param_1 + 0x60f,0xffffffff);
    FUN_002175d4(param_1 + 0x24a,0xffffffff);
    FUN_002175d4(param_1 + 0x227,0xffffffff);
    FUN_002175d4(param_1 + 0x1e1,0xffffffff);
    FUN_002175d4(param_1 + 0x1be,0xffffffff);
    FUN_002175d4(param_1 + 0x19b,0xffffffff);
    FUN_002175d4(param_1 + 0x178,0xffffffff);
    FUN_002175d4(param_1 + 0x155,0xffffffff);
    FUN_002175d4(param_1 + 0x132,0xffffffff);
    FUN_002175d4(param_1 + 0x10f,0xffffffff);
    FUN_002175d4(param_1 + 0xeb,0xffffffff);
    FUN_002175d4(param_1 + 0x5a,0xffffffff);
    FUN_002175d4(param_1 + 0x12,0xffffffff);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
