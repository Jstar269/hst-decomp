/* HSTMATCH module=hstp_trans_main.prx start=0x001a1630 end=0x001a1644 symbol=FUN_001a1630 lang=c99 */
/* Clone of src/eboot/FUN_00194e20.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/settings_block.h"

extern SettingsBlock * DAT_003eb004;
extern void FUN_001a13b4();

/* Call FUN_001a13b4 with the object, the halfword setting at 0x1034 and the constant 0x20. */
void FUN_001a1630(u32 obj)
{
  FUN_001a13b4(obj,DAT_003eb004->unk1034,0x20);
}
