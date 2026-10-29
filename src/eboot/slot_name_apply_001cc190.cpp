/* HSTMATCH module=EBOOT.BIN start=0x001cc190 end=0x001cc354 symbol=FUN_001cc190 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (mechanical draft inputs/generated/FUN_001cc190.c, generator tag not recorded) corrected by hand: bounds test respelled as `iVar2 < 0 || !(iVar2 < size)`; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

#define SLOT_NAME_BANK 7       /* text bank the item names are looked up in */
#define NAME_KEY_SIZE 256

extern "C" {
extern u8 DAT_002ea308;
extern void FUN_0018a950(u32, u8 *);
extern TextBank * FUN_0018c9f4(int);
extern void FUN_001cb5ec(NameBoxOwner *, void *, int, u32);
extern void FUN_001cd88c(PanelData *, int, int);
extern u8 * FUN_002294f4(void *, TextBank *, void *, int);
extern u32 FUN_002297d8(void *, void *, int);
}

/* Name for string index idx of group 0 in a bank (placeholder strings when unloaded or out of range). */
static inline u8 *Lookup(TextBank *bank, int idx)
{
  if (bank->loaded == 0)
    return (u8 *)DAT_002c0e20;
  if (bank->header->groupCount < 1)
    return (u8 *)DAT_002c0e1c;
  if (idx < 0 || !(idx < bank->groups[0].count))
    return (u8 *)DAT_002c0e18;
  return (u8 *)bank->groups[0].strings[idx];
}

/* Shows the name built from `source`/`arg` on the panel: the default text when index < 0, otherwise the text for the indexed item (which is also stored as the panel selection). */
extern "C" void FUN_001cc190(NameBoxOwner *self,int source,u32 arg,int index)
{
  u8 *found;
  PanelData *panel;
  register NameBoxItem *item;
  u8 *text;
  u8 keyBuf [NAME_KEY_SIZE];
  
  if (source != 0) {
    FUN_001cb5ec(self,keyBuf,source,arg);
    if (index < 0) {
      panel = self->panel;
      found = FUN_002294f4(panel->map34,panel->bank,keyBuf,0);
      if (found != 0) {
        panel->unk63 = 0;
        panel->unk64 = 0;
        panel->text = found;
        panel->unk6c = 0;
        panel->unk70 = 0;
        FUN_0018a950(panel->unk20,&DAT_002ea308);
        FUN_001cd88c(panel,2,1);
      }
      panel->unk74 = -1;
      panel->unk78 = -1;
      FUN_002297d8(panel->map34,keyBuf,0);
    }
    else {
      item = self->items[index];
      text = Lookup(FUN_0018c9f4(SLOT_NAME_BANK),item->kind);
      panel = self->panel;
      found = FUN_002294f4(panel->map34,panel->bank,keyBuf,0);
      if (found != 0) {
        panel->unk63 = 0;
        panel->unk64 = 0;
        panel->text = found;
        panel->unk6c = 0;
        panel->unk70 = 0;
        FUN_0018a950(panel->unk20,text);
        FUN_001cd88c(panel,2,1);
      }
      panel->unk74 = -1;
      panel->unk78 = -1;
      FUN_002297d8(panel->map34,keyBuf,0);
      self->panel->unk5c = item;
    }
  }
}
