/* Layout of the screen whose widgets slide in and out; only the fields the slide sources use. */
#ifndef HST_SLIDE_SCREEN_H
#define HST_SLIDE_SCREEN_H

#include "hst/types.h"

enum {
  SLIDE_ITEM_COUNT = 9,        /* sliding elements, laid out one after another */
  SLIDE_SLOT_COUNT = 106,      /* highest slot index used + 1 */
  SLIDE_SCREEN_WIDTH = 480     /* distance an element travels from off screen */
};

/* Position holder; the coordinates are read as floats. */
typedef struct SlidePos {
  char pad00[0x60];
  float x;   /* 0x60 */
  float y;   /* 0x64 */
} SlidePos;

/* One sliding element (0x8c bytes). */
typedef struct SlideItem {
  int unk00;
  int unk04;
  short x, y;       /* 0x08 */
  int unk0c, unk10;
  short x2, y2;     /* 0x14 */
  char pad18[0x8c - 0x18];
} SlideItem;

/* Slot record (0x14 bytes) whose first word is a handle. */
typedef struct SlideSlot {
  u32 handle;       /* 0x00 */
  char pad04[0x14 - 4];
} SlideSlot;

/* Pane whose embedded sub-object starts at 0xd0. */
typedef struct SlidePane {
  char pad00[0xd0];
  char sub0d0[1];   /* 0xd0, start of an embedded object */
} SlidePane;

/* Object with a float field at 0xe0. */
typedef struct SlideCursor {
  char pad00[0xe0];
  float unke0;      /* 0xe0 */
} SlideCursor;

typedef struct SlideScreen {
  char pad00[0x20];
  SlidePos *pos20;                         /* 0x20 */
  int pad24;
  SlidePos *pos28;                         /* 0x28 */
  char pad2c[0x1238 - 0x2c];
  int base;                                /* 0x1238 */
  int step;                                /* 0x123c */
  int unk1240;                             /* 0x1240 */
  int unk1244;                             /* 0x1244 */
  int unk1248;                             /* 0x1248 */
  int unk124c;                             /* 0x124c */
  u8 unk1250;                              /* 0x1250 */
  char pad1251[3];
  SlideItem items[SLIDE_ITEM_COUNT];       /* 0x1254 */
  char pad1740[0x1f74 - 0x1740];
  SlideSlot slots[SLIDE_SLOT_COUNT];       /* 0x1f74 */
  char pad27bc[0x285c - 0x27bc];
  u32 unk285c;                             /* 0x285c */
  SlideCursor *cursor;                     /* 0x2860 */
  char pad2864[0x2878 - 0x2864];
  SlidePane *pane2878;                     /* 0x2878 */
  char pad287c[4];
  SlidePane *pane2880;                     /* 0x2880 */
  char pad2884[4];
  SlidePane *pane2888;                     /* 0x2888 */
  char pad288c[0x2894 - 0x288c];
  SlidePane *pane2894;                     /* 0x2894 */
  char pad2898[0x28a0 - 0x2898];
  SlidePane *pane28a0;                     /* 0x28a0 */
  char pad28a4[4];
  SlidePane *pane28a8;                     /* 0x28a8 */
} SlideScreen;

#endif
