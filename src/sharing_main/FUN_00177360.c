/* HSTMATCH module=hstp_trans_main.prx start=0x00177360 end=0x00177380 symbol=FUN_00177360 lang=c99 */
/* Clone of src/eboot/FUN_0016b19c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsEntry * FUN_001773e0();

/* Returns the 16-bit id of entry `index` of the settings block. */
int FUN_00177360(int index)
{
  SettingsEntry *e;
  
  e = FUN_001773e0(index);
  return (int)e->unk2;
}
