/* Screen object of the 0x263000 sources (created by the 0x1e50-byte constructor) with its panel, part and item views. */
#ifndef HST_SCREEN_OBJ_H
#define HST_SCREEN_OBJ_H

#include "hst/types.h"

#define RING_SIZE 32 /* length of the ring the update advances through */

/* Polymorphic widget; each C++ source declares the virtual slots it calls. */
typedef struct Widget Widget;

/* Helper object at 0x58 of the screen. */
typedef struct ScreenPart {
  void *vtable;       /* 0x00 */
  char pad04[0xd4];
  int unkd8;          /* 0xd8 */
  int unkdc;          /* 0xdc */
  char pade0[0x34];
  char unk114;        /* 0x114 */
} ScreenPart;

/* Item with a pair of counters (unk24 is kept one ahead of unk28 when shown). */
typedef struct ScreenItem {
  char pad00[0xe];
  u16 unk0e;          /* 0x0e low two bits are tested */
  char pad10[0x14];
  int unk24;          /* 0x24 */
  int unk28;          /* 0x28 */
} ScreenItem;

/* Panel object at 0x640 of the screen. */
typedef struct ScreenPanel {
  char pad00[0x5c];
  int unk5c;          /* 0x5c */
  char pad60[0x14];
  int unk74;          /* 0x74 */
  int unk78;          /* 0x78 */
  char pad7c[4];
  int unk80;          /* 0x80 mode (1, 2 and 3 are tested) */
  char pad84[0x4d0 - 0x84];
  u8 unk4d0;          /* 0x4d0 */
  char pad4d1[0x616 - 0x4d1];
  u8 unk616;          /* 0x616 */
  u8 unk617;          /* 0x617 */
  char pad618[4];
  int unk61c;         /* 0x61c */
  char pad620[0x736 - 0x620];
  u8 unk736;          /* 0x736 */
  u8 unk737;          /* 0x737 */
  char pad738[0x856 - 0x738];
  u8 unk856;          /* 0x856 */
  u8 unk857;          /* 0x857 */
  char pad858[0x2c02 - 0x858];
  u8 unk2c02;         /* 0x2c02 */
} ScreenPanel;

/* Environment object (DAT_00338ac4): only two fields are read. */
typedef struct ScreenEnv {
  char pad00[0x28];
  int unk28;          /* 0x28 */
  char pad2c[0x178 - 0x2c];
  u8 unk178;          /* 0x178 */
} ScreenEnv;

/* Ring record the update writes into. */
typedef struct ScreenRing {
  char pad00[0x24];
  int unk24;          /* 0x24 base + index */
  int unk28;          /* 0x28 base */
} ScreenRing;

typedef struct ScreenObj {
  void *vtable;       /* 0x00 */
  char pad04[0x50];
  u8 unk54;           /* 0x54 */
  u8 unk55;           /* 0x55 */
  char pad56[2];
  ScreenPart *part;   /* 0x58 */
  char pad5c[0x640 - 0x5c];
  ScreenPanel *panel; /* 0x640 */
  u8 unk644;          /* 0x644 selects which widgets are shown */
  char pad645[0x658 - 0x645];
  Widget *unk658;     /* 0x658 */
  Widget *unk65c;     /* 0x65c */
  char pad660[0x66c - 0x660];
  Widget *unk66c;     /* 0x66c */
  char pad670[0x67c - 0x670];
  Widget *unk67c;     /* 0x67c */
  Widget *unk680;     /* 0x680 */
  char pad684[0x69c - 0x684];
  ScreenItem *item;   /* 0x69c */
  Widget *unk6a0;     /* 0x6a0 */
  int unk6a4;         /* 0x6a4 */
  char pad6a8[0x6d8 - 0x6a8];
  int unk6d8;         /* 0x6d8 */
  int unk6dc;         /* 0x6dc */
  int unk6e0;         /* 0x6e0 */
  char pad6e4[0x1850 - 0x6e4];
  int unk1850;        /* 0x1850 */
  int unk1854;        /* 0x1854 */
  int unk1858;        /* 0x1858 counter bumped by the ring update */
  char pad185c[4];
  ScreenRing *ring;   /* 0x1860 first word of the member built at 0x1860 */
  int ring_index;     /* 0x1864 */
  char pad1868[0x1e40 - 0x1868];
  u8 unk1e40;         /* 0x1e40 */
  char pad1e41[3];
  int unk1e44;        /* 0x1e44 */
  int unk1e48;        /* 0x1e48 */
  char pad1e4c[4];
} ScreenObj;          /* size 0x1e50 */

#endif
