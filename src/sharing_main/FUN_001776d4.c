/* HSTMATCH module=hstp_trans_main.prx start=0x001776d4 end=0x001776f8 symbol=FUN_001776d4 lang=c99 */
/* Clone of src/eboot/FUN_0016b510.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/settings_block.h"

extern SettingsBlock * FUN_00177d4c();

/* Returns whether the flag byte at +0x103c is set. */
bool FUN_001776d4(void)
{
  SettingsBlock *settings;
  
  settings = FUN_00177d4c();
  return settings->unk103c != '\0';
}
