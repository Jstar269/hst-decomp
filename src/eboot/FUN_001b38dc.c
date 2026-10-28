/* HSTMATCH module=EBOOT.BIN start=0x001b38dc end=0x001b39e4 symbol=FUN_001b38dc lang=c99 data=0x002e9544 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001b38dc.c) corrected by hand: replaced the absolute data address literal with DAT_0030ebf4; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002e9544-0x002e9597) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002e58e4;
extern u8 DAT_002e58ec;
extern u8 DAT_002e58f4;
extern u8 DAT_002e5908;
extern u32 DAT_0034178c;
extern char DAT_0030ebf4[];
extern u32 FUN_0001342c();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern void FUN_001b06d4();
extern void FUN_001b0ef8();

void FUN_001b38dc(u32 *param_1,int param_2)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  DAT_0034178c = FUN_0001342c();
  FUN_0001ca58(DAT_0030ebf4,"sound/game/000_common_00.xb");
  FUN_001b06d4(uVar1,&DAT_002e58e4,2,0);
  FUN_0001cb88(DAT_0030ebf4);
  FUN_0001ca58(DAT_0030ebf4,"sound/game/000_common_01.xb");
  FUN_001b06d4(uVar1,&DAT_002e58ec,2,0);
  FUN_0001cb88(DAT_0030ebf4);
  FUN_0001ca58(DAT_0030ebf4,"sound/game/000_common_1.xb");
  FUN_001b06d4(uVar1,&DAT_002e58f4,5,0);
  FUN_001b0ef8(uVar1,*(u32 *)(&DAT_002e5908 + param_2 * 4),0,0,0);
  FUN_0001cb88(DAT_0030ebf4);
}
