/* HSTMATCH module=hstp_trans_main.prx start=0x001776b4 end=0x001776d4 symbol=FUN_001776b4 lang=c99 */
/* Clone of src/eboot/FUN_0016b4f0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_00177d4c();

/* Returns the halfword setting at +0x103a. */
u16 FUN_001776b4(void)
{
  SettingsBlock *settings;
  
  settings = FUN_00177d4c();
  return settings->unk103a;
}
