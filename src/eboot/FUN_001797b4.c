/* HSTMATCH module=EBOOT.BIN start=0x001797b4 end=0x001797fc symbol=FUN_001797b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern void FUN_0017ce84();
extern void FUN_00180edc();

void FUN_001797b4(int param_1)
{
  u32 uVar1;
  
  if (0 < *(int *)(param_1 + 0x6c)) {
    uVar1 = (**(code **)(param_1 + 0x558))();
    FUN_00180edc(*(u32 *)(param_1 + 0x174),uVar1);
    FUN_0017ce84(*(u32 *)(param_1 + 0x178));
  }
}
