/* Option panel of the 0x261000 sources: a cursor widget, four option slots and a few layout elements. */
#ifndef HST_OPTION_PANEL_H
#define HST_OPTION_PANEL_H

#define OPTION_SLOT_COUNT 4   /* selectable option slots */

/* Cursor widget created by the panel's layout. */
typedef struct CursorWidget {
  char pad00[0xd8];
  int unkd8;                  /* 0xd8 */
  int selected;               /* 0xdc index of the highlighted slot */
  char pade0[8];
  unsigned char unke8;        /* 0xe8 */
  char pade9;
  unsigned char unkea;        /* 0xea */
  char padeb[0x114 - 0xeb];
  char unk114;                /* 0x114 */
} CursorWidget;

/* Named element of the panel layout. */
typedef struct LayoutElem {
  char pad00[0x20];
  CursorWidget *widget;       /* 0x20 */
  int unk24;                  /* 0x24 */
  int unk28;                  /* 0x28 */
} LayoutElem;

/* Part of the owning object that the panel writes its choice to. */
typedef struct OptionOwner {
  char pad00[0x80];
  int unk80;                  /* 0x80 */
  int unk84;                  /* 0x84 */
  char pad88[0x711 - 0x88];
  unsigned char unk711;       /* 0x711 */
  char pad712[0x831 - 0x712];
  unsigned char unk831;       /* 0x831 */
} OptionOwner;

typedef struct OptionPanel {
  void *vtable;               /* 0x00 */
  char pad04[0x50];
  unsigned char unk54;        /* 0x54 */
  unsigned char confirmed;    /* 0x55 */
  char pad56[2];
  CursorWidget *cursor;       /* 0x58 */
  OptionOwner *owner;         /* 0x5c */
  int tick;                   /* 0x60 frames since the panel opened */
  void *pane;                 /* 0x64 layout pane the elements are looked up in */
  LayoutElem *slots[OPTION_SLOT_COUNT]; /* 0x68 */
  LayoutElem *unk78;          /* 0x78 */
  LayoutElem *unk7c;          /* 0x7c */
  LayoutElem *value;          /* 0x80 */
  int base;                   /* 0x84 value element's initial word */
  int page;                   /* 0x88 */
} OptionPanel;

#endif
