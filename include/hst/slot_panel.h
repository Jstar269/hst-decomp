/* Large slot-holding object of the 0x1fb000 sources: four slot pointers, two records, a handle with a countdown, entry tables. */
#ifndef HST_SLOT_PANEL_H
#define HST_SLOT_PANEL_H

enum {
  PANEL_SLOT_COUNT = 4,      /* slot pointers (and ids) per panel */
  PANEL_REC_COUNT = 2,       /* records, selected by the current record index */
  PANEL_CELL_COUNT = 5,      /* eight-word cells reset to -1 */
  PANEL_ROWS = 10,           /* entry rows */
  PANEL_ROW_ENTRIES = 128,   /* entries per row, and in the extra list */
  PANEL_ENTRY_SIZE = 20,
  PANEL_ROW_SIZE = 0xa00,    /* PANEL_ROW_ENTRIES * PANEL_ENTRY_SIZE */
  PANEL_ROWS_OFFSET = 0x136c,
  PANEL_LIST_OFFSET = 0x776c
};

/* Object a slot pointer refers to; only its flag is read. */
typedef struct PanelSlot {
  char pad00[0x58];
  int unk58;                 /* 0x58 nonzero = slot is live */
} PanelSlot;

/* 0xe4-byte record; FUN_001fb8a0 bumps its counter. */
typedef struct PanelRec {
  char pad00[0x1c];
  int mode;                  /* 0x1c */
  char pad20[0xe0 - 0x20];
  int unke0;                 /* 0xe0 counter */
} PanelRec;

/* 20-byte table entry: active byte, then four words. */
typedef struct PanelEntry {
  unsigned char active;      /* 0x00 */
  char pad01[3];
  int unk04;
  int unk08;
  int unk0c;
  int unk10;
} PanelEntry;

typedef struct SlotPanel {
  char pad000[0x3a0];
  PanelSlot *slots[PANEL_SLOT_COUNT]; /* 0x3a0 */
  int ids[PANEL_SLOT_COUNT];          /* 0x3b0 */
  char pad3c0[4];
  PanelSlot *p3c4;           /* 0x3c4 slot filter used when record 0 is current */
  PanelSlot *p3c8;           /* 0x3c8 slot filter used when record 1 is current */
  char pad3cc[0x510 - 0x3cc];
  void *unk510;              /* 0x510 */
  char pad514[0x5b8 - 0x514];
  int unk5b8;                /* 0x5b8 */
  char pad5bc[0xf90 - 0x5bc];
  int cells[PANEL_CELL_COUNT][8]; /* 0xf90 */
  int unk1030;               /* 0x1030 */
  int unk1034;               /* 0x1034 counter */
  char pad1038[0x10fc - 0x1038];
  PanelRec recs[PANEL_REC_COUNT]; /* 0x10fc */
  int unk12c4;               /* 0x12c4 */
  int cur_rec;               /* 0x12c8 index into recs */
  int unk12cc;               /* 0x12cc */
  int handle;                /* 0x12d0 -1 when none */
  int count;                 /* 0x12d4 countdown for the handle */
  unsigned char flag;        /* 0x12d8 */
} SlotPanel;

#endif
