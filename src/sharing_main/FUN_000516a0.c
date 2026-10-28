/* HSTMATCH module=hstp_trans_main.prx start=0x000516a0 end=0x000516e4 symbol=FUN_000516a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00004f78();
extern void FUN_00048fb8();
extern void FUN_00049020();
extern void FUN_000516e4();
extern void FUN_0005b024();

void FUN_000516a0(u32 param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_000516e4();
  }
  FUN_00048fb8();
  FUN_00004f78(0,0);
  FUN_00049020();
  FUN_0005b024();
}
