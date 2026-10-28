/* HSTMATCH module=hstp_trans_main.prx start=0x00070030 end=0x000700a0 symbol=FUN_00070030 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051e30();
extern void FUN_000522c0();
extern void FUN_0005b540();

void FUN_00070030(u32 *param_1,u32 param_2)
{
  if (param_1[1] != 0) {
    FUN_00051e30(*param_1,0,0,0x1e0,0x110,0,0);
    FUN_0005b540(param_1[1],*param_1,param_2,0);
    FUN_000522c0(*param_1);
  }
}
