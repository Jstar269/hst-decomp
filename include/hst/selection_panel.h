/* Selection panel of the 0x1aa000 sources: sprite items, a cursor sprite, a text widget and a list of sprites. */
#ifndef HST_SELECTION_PANEL_H
#define HST_SELECTION_PANEL_H

#include "hst/types.h"
#include "hst/entry_panel.h"

enum {
  SELPANEL_FIRST_ITEM_OFFSET = 0x70, /* items[] start inside the panel */
  SELPANEL_ITEM_COUNT = 22           /* items used by the sources */
};

/* List of sprites, one per selectable row. */
typedef struct SelList {
  char pad00[0x10];
  EntrySprite **data;       /* 0x10 */
  int count;                /* 0x14 */
} SelList;

typedef struct SelectionPanel {
  char pad00[SELPANEL_FIRST_ITEM_OFFSET];
  EntryItem items[SELPANEL_ITEM_COUNT]; /* 0x70 sprite items (stride 0x14) */
  char pad228[0x3e8 - 0x228];
  EntryText *text;          /* 0x3e8 */
  char pad3ec[0x3f4 - 0x3ec];
  SelList *list;            /* 0x3f4 */
} SelectionPanel;

#endif
