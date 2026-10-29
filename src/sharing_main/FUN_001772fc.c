/* HSTMATCH module=hstp_trans_main.prx start=0x001772fc end=0x0017731c symbol=FUN_001772fc lang=c99 */
/* Clone of src/eboot/FUN_0016b138.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_00177d4c();

/* Returns the halfword setting at +0x1036. */
u16 FUN_001772fc(void)
{
  SettingsBlock *settings;
  
  settings = FUN_00177d4c();
  return settings->unk1036;
}
