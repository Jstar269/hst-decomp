/* HSTMATCH module=EBOOT.BIN start=0x0016fbf4 end=0x0016fc48 symbol=FUN_0016fbf4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern void FUN_0016b6c8();
extern void FUN_00170c24();
extern void FUN_00170d9c();

void FUN_0016fbf4(int param_1)
{
  (**(code **)(param_1 + 0x53c))(*(u32 *)(param_1 + 0xb8));
  FUN_0016b6c8(*(u32 *)(param_1 + 0xbc));
  FUN_00170c24(param_1,0);
  if (*(u8 *)(param_1 + 0x3e) != '\0') {
    FUN_00170d9c(param_1);
  }
}
