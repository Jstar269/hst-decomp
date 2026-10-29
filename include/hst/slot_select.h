/* Slot-selection menu object: a cursor triple with a saved copy, mode flags and two id tables. */
#ifndef HST_SLOT_SELECT_H
#define HST_SLOT_SELECT_H

#include "hst/types.h"

/* Cursor over a scrolling list: row inside the window, selected index and first visible entry. */
typedef struct SelCursor {
  int row;                /* 0x0 row of the selection inside the visible window */
  int index;              /* 0x4 selected list index */
  int top;                /* 0x8 index of the first visible entry */
} SelCursor;

typedef struct SlotSelect {
  char pad00[0x4f];
  u8 autoPick;            /* 0x4f nonzero: pick by lookup instead of at random */
  char pad50[4];
  int unk54;              /* 0x54 base offset used when reading per-entry bytes */
  char pad58[0x2c0 - 0x58];
  SelCursor cursor;       /* 0x2c0 current cursor of the slot list */
  SelCursor cursorSaved;  /* 0x2cc copy made when the screen is entered */
  char pad2d8[0xc];
  int unk2e4;             /* 0x2e4 */
  int unk2e4Saved;        /* 0x2e8 copy of unk2e4 */
  int unk2ec;             /* 0x2ec */
  int unk2ecSaved;        /* 0x2f0 copy of unk2ec */
  int mode;               /* 0x2f4 0 or 1 */
  int modeSaved;          /* 0x2f8 copy of mode */
  SelCursor listCursor;   /* 0x2fc cursor of the second list; index selects an entry of idTable */
  SelCursor listCursorSaved; /* 0x308 copy of listCursor */
  char pad314[0x378 - 0x314];
  int **slots;            /* 0x378 array of pointers to slot records; first word is the slot id */
  int slotCount;          /* 0x37c number of entries in slots */
  char pad380[4];
  int **idTable;          /* 0x384 array of pointers to id records; first word is the id, -1 when unset */
} SlotSelect;

/* Slot ids accepted by the selection; 0 asks for an automatic pick. */
enum {
  SLOT_SELECT_AUTO = 0,
  SLOT_SELECT_DEFAULT = 1,
  SLOT_SELECT_ID_LIMIT = 0x15, /* ids 1..20 are valid */
  SLOT_SELECT_VISIBLE_ROWS = 6
};

#define SLOT_SELECT_ID_NONE (-1)

#endif
