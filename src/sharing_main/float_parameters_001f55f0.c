/* HSTMATCH module=hstp_trans_main.prx start=0x001f55f0 end=0x001f5664 symbol=FUN_001f55f0 lang=c99 */
/* Clone of src/eboot/float_parameters_001e73d8.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the mixed integer and float helper parameters and passed the pointer and float values in declared order; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_00394098[];
extern u32 FUN_00066a84();
extern int FUN_001fc5ec();
extern void FUN_002268b4(int,int,float,float);
extern void FUN_002268dc();

void FUN_001f55f0(int param_1)
{
  u32 uVar1;
  
  uVar1 = FUN_001fc5ec();
  uVar1 = FUN_00066a84(uVar1,DAT_00394098,1);
  FUN_002268dc(param_1 + 0x928,*(u32 *)(param_1 + 0x948),0xffffffff,uVar1);
  FUN_002268b4(param_1 + 0x928,uVar1,1.5f,1.0f);
}
