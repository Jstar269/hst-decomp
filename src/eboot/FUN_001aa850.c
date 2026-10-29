/* HSTMATCH module=EBOOT.BIN start=0x001aa850 end=0x001aa9a8 symbol=FUN_001aa850 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/entry_panel.h"

extern u8 DAT_002e20d0;
extern void FUN_000ffb3c();
extern void FUN_0010d4a8();
extern u8 * FUN_001fea10();

/* Blanks one entry row: shows the placeholder frame and fills the labels with default text. */
void FUN_001aa850(EntryItem *item_a,EntryItem *item_b,EntryItem *item_c,EntryItem *item_d,
                  EntryLabel *label_a,EntryLabel *label_b,EntryLabel *label_c,EntryLabel *label_d,
                  EntryLabel *label_e)
{
  u32 text;
  EntryText *widget;
  
  FUN_000ffb3c(item_a->spr,1);
  FUN_000ffb3c(item_c->spr,0);
  FUN_000ffb3c(item_b->spr,0);
  item_b->spr->frame = item_b->spr->baseFrame + 0x11;
  text = (unsigned int)(FUN_001fea10(0x13,0,0));
  widget = label_a->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_0010d4a8();
  text = (unsigned int)(FUN_001fea10(0x13,0,0));
  widget = label_b->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_0010d4a8();
  widget = label_c->text;
  widget->str = (const char *)&DAT_002e20d0;
  widget->visible = 1;
  FUN_0010d4a8();
  text = (unsigned int)(FUN_001fea10(0x13,0,0));
  widget = label_d->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_0010d4a8();
  FUN_000ffb3c(item_d->spr,1);
  text = (unsigned int)(FUN_001fea10(0x13,0,0));
  widget = label_e->text;
  widget->str = (const char *)text;
  widget->visible = 1;
  FUN_0010d4a8();
}
