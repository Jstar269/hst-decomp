/* HSTMATCH module=hstp_trans_main.prx start=0x001d9fa0 end=0x001da030 symbol=FUN_001d9fa0 lang=c99 */
/* Clone of src/eboot/FUN_001cb7d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/panel_data.h"

extern u32 DAT_003ea8ec;
extern void FUN_00111aa4();
extern void FUN_0011e940();
extern void FUN_001d06dc();
extern void FUN_001dbf68();
extern u8 * FUN_00238a68();

/* Looks up the entry for key in the panel's map and, when found, shows it and queues the next step. */
void FUN_001d9fa0(PanelOwner *owner,u32 key)
{
  u8 *entry;
  PanelData *panel;
  
  panel = owner->panel;
  panel->unkb0 = 0;
  entry = FUN_00238a68(panel->map34,panel->bank,key,0);
  if (entry != 0) {
    FUN_0011e940(DAT_003ea8ec,1,entry,0,0);
    FUN_00111aa4(**(u32 **)(DAT_003ea8ec + 0x58),0,0);
    FUN_001dbf68(panel,4,1);
    FUN_001d06dc(panel);
  }
}
