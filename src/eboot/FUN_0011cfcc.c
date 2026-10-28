/* HSTMATCH module=EBOOT.BIN start=0x0011cfcc end=0x0011d050 symbol=FUN_0011cfcc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0305_0011cfcc_m02.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern u32 * FUN_0011d3f8();
extern void FUN_0011e5bc();
extern void FUN_0011f35c();

int FUN_0011cfcc(int param_1,short param_2)
{
  char auStack_18 [24];
  u8 auStack_30 [24];
  
  if (0 != param_1) {
    FUN_0011f35c(auStack_30,param_1,*(u32 *)(param_1 + 0x14));
    FUN_0011f35c(auStack_18,param_1,0);
    FUN_0011e5bc(param_1,auStack_18,auStack_30);
    FUN_0011d3f8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
