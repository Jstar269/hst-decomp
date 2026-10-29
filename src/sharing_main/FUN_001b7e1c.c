/* HSTMATCH module=hstp_trans_main.prx start=0x001b7e1c end=0x001b7f74 symbol=FUN_001b7e1c lang=c99 */
/* Clone of src/eboot/FUN_001aa850.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/entry_panel.h"

extern u8 DAT_003899a0;
extern void FUN_00105470();
extern void FUN_00113a50();
extern u8 * FUN_0020d1e0();

/* Blanks one entry row: shows the placeholder frame and fills the labels with default text. */
void FUN_001b7e1c(EntryItem *item_a,EntryItem *item_b,EntryItem *item_c,EntryItem *item_d,
                  EntryLabel *label_a,EntryLabel *label_b,EntryLabel *label_c,EntryLabel *label_d,
                  EntryLabel *label_e)
{
  u32 text;
  EntryText *widget;
  
  FUN_00105470(item_a->spr,1);
  FUN_00105470(item_c->spr,0);
  FUN_00105470(item_b->spr,0);
  item_b->spr->frame = item_b->spr->baseFrame + 0x11;
  text = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  widget = label_a->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_00113a50();
  text = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  widget = label_b->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_00113a50();
  widget = label_c->text;
  widget->str = (const char *)&DAT_003899a0;
  widget->visible = 1;
  FUN_00113a50();
  text = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  widget = label_d->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_00113a50();
  FUN_00105470(item_d->spr,1);
  text = (unsigned int)(FUN_0020d1e0(0x13,0,0));
  widget = label_e->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_00113a50();
}
