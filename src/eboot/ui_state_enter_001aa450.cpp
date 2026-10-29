/* HSTMATCH module=EBOOT.BIN start=0x001aa450 end=0x001aa558 symbol=FUN_001aa450 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review (matching idiom: each live range is its own local with a typed struct view, no variable reuse as in Ghidra, and the widget member read twice through one pointer, `EntryItem *pp = &o->items[1];`; supersedes the near miss wip/ui_state_enter_001aa450.c). */
/* Looks up an item id through the context getter (second list cursor), stores a label computed from it into the text widget and updates the frame of the sprite in items[7]; then shows the sprite in items[1] and, when FUN_001a4b74(ctx, 3) holds and the context field after the id table is greater than 1, hides it. */
#include "hst/slot_select.h"
#include "hst/selection_panel.h"

/* The selection state plus the word that follows it. */
struct SelectCtx {
  SlotSelect base;
  int unk388;
};
extern "C" SelectCtx *FUN_0019d474(void);
extern "C" int FUN_001a49f4(SelectCtx *, int);
extern "C" int FUN_001a4b74(SelectCtx *, int);
extern "C" void *FUN_001fea10(int, int, int);
extern "C" void FUN_0010d4a8(EntryText *);
extern "C" void FUN_000ffb3c(EntrySprite *, int);

enum { LABEL_BANK_ITEMS = 5, LABEL_BANK_MISC = 0x13, LABEL_NO_ITEM = 5 };

extern "C" void FUN_001aa450(SelectionPanel *o)
{
  SelectCtx *c = FUN_0019d474();
  int idx = FUN_001a49f4(FUN_0019d474(), c->base.listCursor.index);
  if (idx == -1) {
    void *v = FUN_001fea10(LABEL_BANK_MISC, 0, LABEL_NO_ITEM);
    EntryText *s = o->text;
    s->str = (const char *)v;
    s->visible = 1;
    FUN_0010d4a8(s);
    o->items[7].spr->frame = o->items[7].spr->baseFrame + 8;
  } else {
    void *v = FUN_001fea10(LABEL_BANK_ITEMS, 0, idx);
    EntryText *s = o->text;
    s->str = (const char *)v;
    s->visible = 1;
    FUN_0010d4a8(s);
    o->items[7].spr->frame = o->items[7].spr->baseFrame + idx;
  }
  EntryItem *pp = &o->items[1];
  FUN_000ffb3c(pp->spr, 1);
  if (FUN_001a4b74(FUN_0019d474(), 3) != 0 && FUN_0019d474()->unk388 > 1) {
    FUN_000ffb3c(pp->spr, 0);
  }
}
