/* Selection menu object (seven item slots, a cursor, widget handles) and the small state holder that wraps it. */
#ifndef HST_SELECTION_MENU_H
#define HST_SELECTION_MENU_H

#define SELECTION_SLOT_COUNT 7
#define SELECTION_ITEM_NONE 7 /* item value whose widgets are handled differently from the others */

typedef struct SelectionMenu {
  const void *vtable;                    /* 0x00 */
  char pad04[0x50];
  unsigned char unk54;                   /* 0x54 set by the update, cleared when the state holder consumes it */
  char pad55[0x64 - 0x55];
  void *unk64[SELECTION_SLOT_COUNT];     /* 0x64 */
  void *unk80[SELECTION_SLOT_COUNT];     /* 0x80 */
  void *unk9c[SELECTION_SLOT_COUNT];     /* 0x9c */
  char padb8[4];
  void *unkbc;                           /* 0xbc */
  char padc0[0xe0 - 0xc0];
  void *text;                            /* 0xe0 object that receives the item string, has virtual methods */
  void *unke4;                           /* 0xe4 handle set to the cursor value */
  int cursor;                            /* 0xe8 selected slot, wraps at count */
  int item[SELECTION_SLOT_COUNT];        /* 0xec item value per slot */
  int count;                             /* 0x108 number of slots the cursor moves over */
  int unk10c;                            /* 0x10c tested with button mask 16, set to -1 at the first slot */
  int unk110;                            /* 0x110 tested with button mask 64, set to -1 at the last slot */
} SelectionMenu;

/* Holder of the menu and its current state id. */
typedef struct SelectionState {
  SelectionMenu *menu;  /* 0x00 */
  int state;            /* 0x04 */
} SelectionState;

#endif
