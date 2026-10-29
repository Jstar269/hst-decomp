/* HSTMATCH module=EBOOT.BIN start=0x000f0644 end=0x000f0754 symbol=FUN_000f0644 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v3) corrected by hand: materialized the inverted byte gate, typed float fields, and expressed the final virtual call; readability pass; exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern u8 * DAT_00338b44;
extern "C" void FUN_000f0754(AcePane *pane);
extern "C" void FUN_000f0968(AcePane *pane);
extern "C" void FUN_000ffb3c(PaneQuad *item,int hide);

struct VTable { virtual void slot0(); virtual void slot1(); };

/* Hide the ace pane's items (colour reset) and, when the global flag is clear, shift each pair down 20 pixels. */
extern "C" void FUN_000f0644(AcePane *pane)
{
  PaneQuad *item;
  int i;
  
  FUN_000f0968(pane);
  i = 0;
  do {
    int shifted = (*(u8 *)(DAT_00338b44 + 0x45) != 0) ^ 1;
    if (shifted != 0) {
      item = pane->item[i];
      item->y0 = item->y0 + 0x14;
      item->y1 = item->y1 + 0x14;
      item = pane->item[i + 2];
      item->y0 = item->y0 + 0x14;
      item->y1 = item->y1 + 0x14;
      pane->item_y[i] = pane->item_y[i] + 20.0f;
      pane->item_y[i + 2] = pane->item_y[i + 2] + 20.0f;
      item = pane->item[i];
    }
    else {
      item = pane->item[i];
    }
    FUN_000ffb3c(item,1);
    pane->item[i]->color = 0x808080;
    FUN_000ffb3c(pane->item[i + 2],1);
    pane->item[i + 2]->color = 0x808080;
    i = i + 1;
  } while (i < 2);
  FUN_000f0754(pane);
  ((VTable *)pane)->slot1();
}
