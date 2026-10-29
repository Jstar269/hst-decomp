/* HSTMATCH module=hstp_trans_main.prx start=0x00177c3c end=0x00177c64 symbol=FUN_00177c3c lang=c99 */
/* Clone of src/eboot/FUN_0016ba78.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_00177d4c();

/* Stores the flag byte at +0x103c. */
void FUN_00177c3c(u8 value)
{
  SettingsBlock *settings;
  
  settings = FUN_00177d4c();
  settings->unk103c = value;
}
