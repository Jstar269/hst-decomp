/* HSTMATCH module=hstp_trans_main.prx start=0x001c1198 end=0x001c1260 symbol=FUN_001c1198 lang=c99 data=0x00390db8 */
/* Clone of src/eboot/seq_table_register_001b3068.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x00390db8-0x00390e3b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the module address 0x3b7ebc is the symbol &DAT_003b7ebc (lui/addiu, not lui/ori); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0038d2a0;
extern u8 DAT_0038d2a8;
extern u8 DAT_0038d2b4;
extern u8 DAT_003b7ebc;
extern void FUN_0001c5f4();
extern void FUN_0001c73c();
extern void FUN_001be0d0();

void FUN_001c1198(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_0001c5f4(&DAT_003b7ebc,"menu/optionvoice/option_voice_menu_us_0.xb");
  FUN_001be0d0(uVar1,&DAT_0038d2a0,2,0);
  FUN_0001c73c(&DAT_003b7ebc);
  FUN_0001c5f4(&DAT_003b7ebc,"menu/optionvoice/option_voice_menu_us_1.xb");
  FUN_001be0d0(uVar1,&DAT_0038d2a8,3,0);
  FUN_0001c73c(&DAT_003b7ebc);
  FUN_0001c5f4(&DAT_003b7ebc,"menu/optionvoice/option_voice_menu_us_2.xb");
  FUN_001be0d0(uVar1,&DAT_0038d2b4,2,0);
  FUN_0001c73c(&DAT_003b7ebc);
}
