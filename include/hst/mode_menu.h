/* Menu page object with four modes, each keeping its own cursor, previous cursor and scroll value. */
#ifndef HST_MODE_MENU_H
#define HST_MODE_MENU_H

typedef struct ModeMenuSub {
  char pad0[0xdc];
  int cursor;              /* 0xdc */
} ModeMenuSub;

typedef struct ModeMenuSlot {
  void *left;              /* 0x0 */
  void *right;             /* 0x4 */
  char pad8[8];
} ModeMenuSlot;

typedef struct ModeMenu {
  char pad0[0x3c];
  char widgets[0x104 - 0x3c];  /* 0x3c embedded widget tree, used by address */
  int mode;                /* 0x104 active mode, 1..4 */
  char pad108[0x10];
  int cursor[4];           /* 0x118 per mode (index mode - 1) */
  int cursorOld[4];        /* 0x128 */
  int scroll[4];           /* 0x138 */
  char pad148[0x28];
  unsigned char unk170[8]; /* 0x170 */
  char pad178[2];
  unsigned char unk17a;    /* 0x17a */
  unsigned char unk17b;    /* 0x17b */
  char pad17c;
  unsigned char unk17d;    /* 0x17d */
  char pad17e[0x454 - 0x17e];
  unsigned char timedOut;  /* 0x454 set when the countdown runs out */
  char pad455[7];
  int countdown;           /* 0x45c */
  char pad460[0x474 - 0x460];
  ModeMenuSub *sub;        /* 0x474 */
  char pad478[0x4b8 - 0x478];
  ModeMenuSlot slots[16];  /* 0x4b8 */
} ModeMenu;

#endif
