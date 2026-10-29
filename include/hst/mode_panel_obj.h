/* Two-mode panel object (receiver of the mode-switch and per-frame update sources): slot values, range records and a mode id. */
#ifndef HST_MODE_PANEL_OBJ_H
#define HST_MODE_PANEL_OBJ_H

struct Gfx; /* virtual interface object, defined where its methods are called */

enum { MODE_PANEL_MODE0 = 0, MODE_PANEL_MODE1 = 1 };

/* Entry holding one float value at +0x78. */
typedef struct ModeSlot {
  char pad00[0x78];
  float value; /* 0x78 */
} ModeSlot;

/* Start/end pair stored as shorts. */
typedef struct ModeRange {
  char pad00[4];
  short start; /* 0x4 */
  short pad06;
  short end;   /* 0x8 */
} ModeRange;

/* Object reached through the panel at +0x35c. */
typedef struct ModePanelTarget {
  char pad00[0xd8];
  int unkd8;   /* 0xd8 */
  int unkdc;   /* 0xdc */
  float unke0; /* 0xe0 */
} ModePanelTarget;

typedef struct ModePanel {
  char pad00[0x54];
  ModeSlot *slot54;      /* 0x54 */
  ModeSlot *slot58;      /* 0x58 */
  ModeSlot *slot5c;      /* 0x5c */
  char pad60[0x1d0 - 0x60];
  ModeRange *range1d0;   /* 0x1d0 */
  ModeRange *range1d4;   /* 0x1d4 */
  char pad1d8[0x358 - 0x1d8];
  struct Gfx *gfx;       /* 0x358 */
  ModePanelTarget *target;    /* 0x35c */
  char pad360[0x1361 - 0x360];
  char name1361[0x1664 - 0x1361]; /* 0x1361 text buffer */
  int mode;              /* 0x1664 current mode id */
  int unk1668;           /* 0x1668 */
  int unk166c;           /* 0x166c */
  int unk1670;           /* 0x1670 */
  int unk1674;           /* 0x1674 */
  char pad1678[0x1688 - 0x1678];
  int unk1688;           /* 0x1688 frame counter used by the pulse */
  int unk168c;           /* 0x168c */
  int unk1690;           /* 0x1690 */
} ModePanel;

#endif
