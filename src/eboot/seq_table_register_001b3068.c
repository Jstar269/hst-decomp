/* HSTMATCH module=EBOOT.BIN start=0x001b3068 end=0x001b3130 symbol=FUN_001b3068 lang=c99 data=0x002e9488 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the module address 0x30ebf4 is the symbol &DAT_0030ebf4 (lui/addiu, not lui/ori); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002e9488-0x002e950b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002e5970;
extern u8 DAT_002e5978;
extern u8 DAT_002e5984;
extern u8 DAT_0030ebf4;
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern void FUN_001b06d4();

void FUN_001b3068(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_0001ca58(&DAT_0030ebf4,"menu/optionvoice/option_voice_menu_us_0.xb");
  FUN_001b06d4(uVar1,&DAT_002e5970,2,0);
  FUN_0001cb88(&DAT_0030ebf4);
  FUN_0001ca58(&DAT_0030ebf4,"menu/optionvoice/option_voice_menu_us_1.xb");
  FUN_001b06d4(uVar1,&DAT_002e5978,3,0);
  FUN_0001cb88(&DAT_0030ebf4);
  FUN_0001ca58(&DAT_0030ebf4,"menu/optionvoice/option_voice_menu_us_2.xb");
  FUN_001b06d4(uVar1,&DAT_002e5984,2,0);
  FUN_0001cb88(&DAT_0030ebf4);
}
