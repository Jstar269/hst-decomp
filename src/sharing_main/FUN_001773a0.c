/* HSTMATCH module=hstp_trans_main.prx start=0x001773a0 end=0x001773c0 symbol=FUN_001773a0 lang=c99 */
/* Clone of src/eboot/FUN_0016b1dc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsEntry * FUN_001773e0();

/* Returns the flag byte of entry `index` of the settings block. */
u8 FUN_001773a0(int index)
{
  SettingsEntry *e;
  
  e = FUN_001773e0(index);
  return e->unk1;
}
