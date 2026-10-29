/* Challenge menu object: layout panes and parts, character widgets, and ten selectable points. */
#ifndef HST_CHALLENGE_MENU_H
#define HST_CHALLENGE_MENU_H

#include "hst/types.h"

/* Array lengths of the menu. */
#define CHALLENGE_PANES 4          /* layout panes looked up by name */
#define CHALLENGE_PARTS 66         /* parts fetched from the panes */
#define CHALLENGE_CHARS 15         /* character widgets built from challenge_chaNN */
#define CHALLENGE_EXTRAS 10        /* widgets released with the menu */
#define POINT_COUNT 10             /* selectable points */

/* Index of the first point part inside the parts array. */
#define CHALLENGE_FIRST_POINT_PART 45

/* Part whose top-left corner gives a point's position. */
typedef struct PointPart {
  char pad00[4];
  short left;                      /* 0x04 */
  short top;                       /* 0x06 */
} PointPart;

typedef struct ChallengeMenu {
  u32 vtable;                      /* 0x00 */
  char pad04[0x50];
  void *panes[CHALLENGE_PANES];    /* 0x54 */
  void *parts[CHALLENGE_PARTS];    /* 0x64 */
  void *chars[CHALLENGE_CHARS];    /* 0x16c */
  void *extras[CHALLENGE_EXTRAS];  /* 0x1a8 */
  void *video;                     /* 0x1d0 */
  u32 unk1d4;                      /* 0x1d4 */
  u8 unk1d8;                       /* 0x1d8 */
  u8 unk1d9;                       /* 0x1d9 */
  u8 unk1da;                       /* 0x1da */
  char pad1db;
  int mode;                        /* 0x1dc 0 or 1; mode 1 notifies the selection handler */
  int selected;                    /* 0x1e0 index of the selected point */
  int unk1e4;                      /* 0x1e4 */
  u8 pending;                      /* 0x1e8 set when the nearest point should be selected */
  char pad1e9[3];
  float pos_x;                     /* 0x1ec x of the selected point */
  float pos_y;                     /* 0x1f0 y of the selected point */
  u32 unk1f4;                      /* 0x1f4 */
  u32 unk1f8;                      /* 0x1f8 */
  u32 unk1fc;                      /* 0x1fc */
  int count[POINT_COUNT];          /* 0x200 per-point count; 2 or more means the point is usable */
  u32 unk228[POINT_COUNT];         /* 0x228 */
  u32 unk250[POINT_COUNT];         /* 0x250 */
  u32 unk278[POINT_COUNT];         /* 0x278 */
  float x[POINT_COUNT];            /* 0x2a0 */
  float y[POINT_COUNT];            /* 0x2c8 */
} ChallengeMenu;

#endif
