/* Result screen object and the widget tables it points at (only the fields the result-screen sources use). */
#ifndef HST_RESULT_SCREEN_H
#define HST_RESULT_SCREEN_H

#include "hst/types.h"

/* Object with a virtual setter taking one int (vtable slot 1); the class body lives in the C++ sources. */
typedef struct ResultSwitch ResultSwitch;

/* Display object with two integer values (numbers shown by the score pair). */
typedef struct ScoreBox {
  char pad00[0x24];
  int unk24; /* 0x24 */
  int unk28; /* 0x28 */
} ScoreBox;

/* Widget handles in the table at ResultScreen.ui. */
typedef struct ResultUi {
  char pad00[0x58];
  ResultSwitch *unk58; /* 0x58 */
  ResultSwitch *unk5c; /* 0x5c */
  ScoreBox *unk60;     /* 0x60 */
  void *unk64;         /* 0x64 */
  void *unk68;         /* 0x68 */
  void *unk6c;         /* 0x6c */
  void *unk70;         /* 0x70 */
  void *unk74;         /* 0x74 */
  void *unk78;         /* 0x78 */
  void *unk7c;         /* 0x7c */
  void *unk80;         /* 0x80 */
  void *unk84;         /* 0x84 */
  void *unk88;         /* 0x88 */
} ResultUi;

/* Object created by FUN_00216fb0 / FUN_00217188 and tweaked right after. */
typedef struct ResultObj {
  char pad00[0x64];
  float unk64; /* 0x64 */
  char pad68[0x70];
  int unkd8;   /* 0xd8 */
  char padDC[0x38];
  u8 unk114;   /* 0x114 */
} ResultObj;

/* One 0x14-byte row of the result screen's row table; only the widget handle is used here. */
typedef struct ResultRow {
  void *widget; /* 0x00 */
  char pad04[0x10];
} ResultRow;

/* One 12-byte cell; only the widget handle is used here. */
typedef struct ResultCell {
  void *widget; /* 0x00 */
  char pad04[8];
} ResultCell;

typedef struct ResultScreen {
  char pad00[0x3c];
  ResultUi *ui; /* 0x3c UI widget table */
  char pad40[0x1b4];
  void *unk1f4; /* 0x1f4 deleted at teardown */
  char pad1f8[0x618];
  void *unk810; /* 0x810 deleted at teardown */
  char pad814[0x1a0];
  void *unk9b4; /* 0x9b4 deleted at teardown */
  char pad9b8[0x14];
  ResultRow row[0x7b]; /* 0x9cc */
  ResultCell cellA[4]; /* 0x1368 */
  ResultCell cellB[14]; /* 0x1398 at least 14 entries are used */
  char pad1440[0x31c];
  void *unk175c; /* 0x175c deleted at teardown */
  char pad1760[0x1f4];
  void *unk1954; /* 0x1954 deleted at teardown */
  void *unk1958; /* 0x1958 deleted at teardown */
  char pad195c[0x408];
  void *unk1d64; /* 0x1d64 deleted at teardown (three-argument delete) */
  void *unk1d68; /* 0x1d68 deleted at teardown */
  char pad1d6c[0x478];
  void *return_lay; /* 0x21e4 layout of the return page */
  char unk21e8[4]; /* 0x21e8 */
  char unk21ec[0xc8]; /* 0x21ec */
  char unk22b4[4]; /* 0x22b4 */
  ResultObj *unk22b8; /* 0x22b8 */
  char pad22bc[0x4];
  ResultObj *unk22c0; /* 0x22c0 */
  char unk22c4[0x94]; /* 0x22c4 */
  int unk2358; /* 0x2358 */
  void *exhibition_lay; /* 0x235c layout of the exhibition page */
  char unk2360[4]; /* 0x2360 */
  char unk2364[0xf0]; /* 0x2364 */
  char unk2454[4]; /* 0x2454 */
  ResultObj *unk2458; /* 0x2458 */
  char pad245c[0x4];
  ResultObj *unk2460; /* 0x2460 */
  void *lay2464; /* 0x2464 layout loaded by FUN_001e248c */
  void *unk2468; /* 0x2468 */
  char unk246c[0x14]; /* 0x246c */
  char unk2480[0x8c]; /* 0x2480 */
  void *lose_lay; /* 0x250c layout of the lose page */
  void *unk2510; /* 0x2510 */
  char unk2514[0x18]; /* 0x2514 */
  char unk252c[0x8c]; /* 0x252c */
  void *overlay_lay; /* 0x25b8 layout of the result overlay */
  char unk25bc[0x14]; /* 0x25bc */
  char unk25d0[0x28]; /* 0x25d0 */
  void *unk25f8; /* 0x25f8 */
  char unk25fc[0x1a0]; /* 0x25fc */
  char unk279c[0x8c]; /* 0x279c */
  char unk2828[4]; /* 0x2828 */
} ResultScreen;

#endif
