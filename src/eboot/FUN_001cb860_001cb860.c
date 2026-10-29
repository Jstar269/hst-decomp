/* HSTMATCH module=EBOOT.BIN start=0x001cb860 end=0x001cb980 symbol=FUN_001cb860 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/panel_data.h"

extern u8 DAT_002ea308;
extern void FUN_0018a950();
extern TextBank * FUN_0018c9f4();
extern void FUN_001cd88c();
extern u32 FUN_0022977c();

/* Shows the text for (group, index) from a bank, then resets the panel's selection. */
void FUN_001cb860(PanelOwner *owner,int key_group,int key_index,int bank_id)
{
  TextBank *bank;
  u8 *text;
  TextGroup *group;
  PanelData *panel;
  int group_ok;
  int index_ok;
  int group_offset;
  
  panel = owner->panel;
  if (bank_id < 0) {
    bank = panel->bank;
  }
  else {
    bank = FUN_0018c9f4(bank_id);
  }
  panel->unk63 = 0;
  panel->unk64 = 0;
  if (bank->loaded == 0) {
    text = (u8 *)DAT_002c0e20;
  }
  else if ((key_group < 0) || ((group_ok = key_group < bank->header->groupCount) == 0)) {
    text = (u8 *)DAT_002c0e1c;
  }
  else if ((key_index < 0) ||
          (group = (TextGroup *)(group_offset = key_group * 0xc, group_offset + (int)bank->groups),
           (index_ok = key_index < group->count) == 0)) {
    text = (u8 *)DAT_002c0e18;
  }
  else {
    text = (u8 *)group->strings[key_index];
  }
  panel->text = text;
  panel->unk6c = 0;
  panel->unk70 = 0;
  FUN_0018a950(panel->unk20,&DAT_002ea308);
  FUN_001cd88c(panel,2,1);
  panel->unk74 = -1;
  panel->unk78 = -1;
  FUN_0022977c(panel->map34,key_group,key_index);
}
