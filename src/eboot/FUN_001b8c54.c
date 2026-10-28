/* HSTMATCH module=EBOOT.BIN start=0x001b8c54 end=0x001b8cf8 symbol=FUN_001b8c54 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern void FUN_00000a00();
extern int FUN_001b23c0();
extern void FUN_001b8d2c();
extern void FUN_001b94f8();

int FUN_001b8c54(int param_1,short param_2)
{
  u8 auStack_4 [4];
  u32 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_001b8d2c();
    if ((((param_1 != 0) && (FUN_001b23c0((int)&DAT_0034179c,0), param_1 != 0)) && (param_1 != 0)) &&
       (param_1 != 0)) {
      local_c = param_1 + 4;
      local_8 = *(u32 *)(param_1 + 8);
      FUN_001b94f8(auStack_4,param_1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
