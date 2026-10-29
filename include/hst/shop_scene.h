/* Shop scene object (layout pane, camera, models, item list and digit display) shared by the shop scene sources. */
#ifndef HST_SHOP_SCENE_H
#define HST_SHOP_SCENE_H

#include "hst/types.h"

#define DIGIT_COUNT 7                /* digit parts per number */
#define DIGIT_FIRST_DIVISOR 1000000  /* place value of the first digit */
#define SCROLL_PARAM_COUNT 3         /* values read from the chrsel scroll table */
#define SHOP_PANE_SIZE 0x54          /* size of the embedded layout pane */
#define SHOP_NO_VALUE (-1)           /* sentinel stored in the field at 0x180 */

struct ShopWidget; /* layout widget with virtual methods; C++ sources define it */
struct ShopModel;  /* model object with a virtual Load; C++ sources define it */

/* Layout part for one digit: its value is the base value plus the digit. */
typedef struct DigitPart {
  char pad0[0x24];
  int unk24;           /* 0x24 value shown */
  int unk28;           /* 0x28 base value */
} DigitPart;

/* Entry of the item list. */
typedef struct ShopItem {
  u8 byte0;            /* 0x00 */
  u8 small;            /* 0x01 */
  u8 flag;             /* 0x02 */
  char pad03[0x11];
  int type;            /* 0x14 */
  int subtype;         /* 0x18 */
} ShopItem;

/* Counted array of item pointers. */
typedef struct ShopItemVec {
  ShopItem **data;     /* 0x00 */
  unsigned int count;  /* 0x04 */
} ShopItemVec;

/* Object that exposes an item count at 0xdc. */
typedef struct ShopSource {
  char pad0[0xdc];
  int count;           /* 0xdc */
} ShopSource;

/* Camera sub-object: two 4-float setup vectors, field of view, clip distances and the tangent of half the field of view. */
typedef struct ShopCamera {
  char pad0[0x1d0];
  float vec1d0[4];     /* 0x1d0 */
  float vec1e0[4];     /* 0x1e0 */
  char pad1f0[0x200 - 0x1f0];
  float fov;           /* 0x200 degrees */
  float near_z;        /* 0x204 */
  float far_z;         /* 0x208 */
  char pad20c[0x214 - 0x20c];
  float tan_half_fov;  /* 0x214 */
} ShopCamera;

typedef struct ShopScene {
  char pad0[0x3c];
  char pane[SHOP_PANE_SIZE];       /* 0x3c layout pane */
  char pad90[4];
  int unk94;                       /* 0x94 */
  char pad98[0xac - 0x98];
  int unkac;                       /* 0xac */
  char padb0[0xb8 - 0xb0];
  int unkb8;                       /* 0xb8 */
  char padbc[0xc4 - 0xbc];
  int unkc4;                       /* 0xc4 */
  char padc8[0xd8 - 0xc8];
  ShopItemVec items;               /* 0xd8 */
  char pade0[0xf0 - 0xe0];
  void *unkf0;                     /* 0xf0 model drawn by the cleanup */
  struct ShopModel *model;         /* 0xf4 model loaded by the init */
  u8 unkf8;                        /* 0xf8 */
  char padf9[0xfc - 0xf9];
  struct ShopWidget *widget_fc;    /* 0xfc */
  struct ShopWidget *widget_100;   /* 0x100 */
  int state;                       /* 0x104 */
  int prev_state;                  /* 0x108 state before the last change */
  char pad10c[4];
  u8 unk110;                       /* 0x110 */
  char pad111[3];
  int unk114;                      /* 0x114 */
  char pad118[0x180 - 0x118];
  int unk180;                      /* 0x180 */
  char pad184[0x190 - 0x184];
  ShopCamera camera;               /* 0x190 */
  char pad3a8[0x458 - 0x3a8];
  int unk458;                      /* 0x458 */
  char pad45c[0x474 - 0x45c];
  ShopSource *source;              /* 0x474 */
  char pad478[0x488 - 0x478];
  u32 layout;                      /* 0x488 layout whose parts are looked up by name */
  char pad48c[0x8bc - 0x48c];
  u32 unk8bc;                      /* 0x8bc */
  char pad8c0[0x8c3 - 0x8c0];
  u8 unk8c3;                       /* 0x8c3 */
  u8 unk8c4;                       /* 0x8c4 */
  u8 unk8c5;                       /* 0x8c5 */
  char pad8c6[0x8c8 - 0x8c6];
  u32 unk8c8;                      /* 0x8c8 */
  char pad8cc[0x8ce - 0x8cc];
  u8 unk8ce;                       /* 0x8ce */
  char pad8cf[0x920 - 0x8cf];
  char sub920[1];                  /* 0x920 sub-object initialised by the init */
  char pad921[0x98c - 0x921];
  int scroll_params[SCROLL_PARAM_COUNT]; /* 0x98c read from the chrsel scroll table */
  u32 unk998;                  /* 0x998 */
  u32 unk99c;                      /* 0x99c */
  u32 unk9a0;                      /* 0x9a0 */
  u32 unk9a4;                      /* 0x9a4 */
  u32 unk9a8;                      /* 0x9a8 */
  u32 unk9ac;                      /* 0x9ac */
  char pad9b0[0xa0c - 0x9b0];
  struct ShopWidget *widget_a0c;   /* 0xa0c */
  char pada10[0xa3c - 0xa10];
  struct ShopWidget *widget_a3c;   /* 0xa3c */
} ShopScene;

#endif
