/* Owner of a name panel: item list, two short name buffers and the panel pointer. */
#ifndef HST_NAME_BOX_OWNER_H
#define HST_NAME_BOX_OWNER_H

#include "hst/panel_data.h"

/* Name buffers hold fewer than this many characters. */
#define NAME_BOX_NAME_LIMIT 0x10

typedef struct NameBoxItem {
  char pad00[0x34];
  int kind;                    /* 0x34 index of the item name in its text bank */
} NameBoxItem;

typedef struct NameBoxOwner {
  char pad00[0x4c];
  NameBoxItem **items;         /* 0x4c */
  char pad50[0x104 - 0x50];
  char nameA[NAME_BOX_NAME_LIMIT];  /* 0x104 */
  char nameB[NAME_BOX_NAME_LIMIT];  /* 0x114 */
  char pad124[0x15c - 0x124];
  PanelData *panel;            /* 0x15c */
} NameBoxOwner;

#endif
