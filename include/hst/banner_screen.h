/* Banner menu screen: 27 banner objects, two helper objects and a 2 x 11 grid of icon handles. */
#ifndef HST_BANNER_SCREEN_H
#define HST_BANNER_SCREEN_H

#define BANNER_COUNT 27 /* entries in the banner table */
#define ICON_ROWS 2     /* icon sets */
#define ICON_COLS 11    /* icons per set */

typedef struct BannerScreen {
  char pad00[0x3c];
  void *unk3c;                              /* 0x3c owned helper, released with a deleting destructor */
  void *unk40;                              /* 0x40 owned helper, released with a deleting destructor */
  char pad44[4];
  struct Banner *banners[BANNER_COUNT];     /* 0x48 owned, deleted through their virtual destructor */
  char padb4[0x270 - 0xb4];
  void *icons[ICON_ROWS][ICON_COLS];        /* 0x270 */
} BannerScreen;

#endif
