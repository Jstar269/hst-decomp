/* HSTMATCH module=hstp_trans_main.prx start=0x00177328 end=0x00177348 symbol=FUN_00177328 lang=c99 */
/* Clone of src/eboot/FUN_0016b164.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_00177d4c();

/* Returns the halfword setting at +0x103e. */
u16 FUN_00177328(void)
{
  SettingsBlock *settings;
  
  settings = FUN_00177d4c();
  return settings->unk103e;
}
