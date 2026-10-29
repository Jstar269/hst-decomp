/* Prize screen object: the fields its start-up, mode handler and per-frame helpers use. */
#ifndef HST_PRIZE_SCREEN_H
#define HST_PRIZE_SCREEN_H

#define PRIZE_MODE_ENTER 18   /* mode that turns the screen on */
#define PRIZE_MODE_LEAVE 19   /* mode that turns it off again */
#define PRIZE_PLAYER_COUNT 4  /* entries in the player table read on leaving */
#define PRIZE_BLOCK_BYTES 840 /* size of the block cleared at 0x54 */

/* Embedded sub-object at the start of the screen's own data: a word and the current mode. */
typedef struct PrizeSub {
  int unk0;       /* 0x0 */
  int mode;       /* 0x4 */
} PrizeSub;

/* Object reached through the screen at 0x584. */
typedef struct PrizeInner {
  char pad00[0x90];
  void *unk90;                  /* 0x90 object with a virtual destructor, deleted by the reset */
  char pad94[0xf0 - 0x94];
  float unkf0;                  /* 0xf0 start of a block handed to a helper */
} PrizeInner;

typedef struct PrizeScreen {
  char pad00[0x3c];
  PrizeSub sub;                 /* 0x3c */
  int unk44;                    /* 0x44 zero on the first frame */
  char pad48[0x54 - 0x48];
  char unk54[PRIZE_BLOCK_BYTES]; /* 0x54 cleared by the reset */
  char pad39c[0x3e8 - 0x39c];
  int unk3e8;                   /* 0x3e8 cleared by start-up */
  int unk3ec;                   /* 0x3ec */
  int unk3f0;                   /* 0x3f0 */
  int unk3f4;                   /* 0x3f4 */
  int unk3f8;                   /* 0x3f8 */
  int unk3fc;                   /* 0x3fc */
  int unk400;                   /* 0x400 */
  int unk404;                   /* 0x404 */
  char pad408[0x510 - 0x408];
  void *unk510;                 /* 0x510 object with a virtual destructor */
  unsigned char active;         /* 0x514 set while the screen is on */
  unsigned char unk515;         /* 0x515 */
  unsigned char unk516;         /* 0x516 */
  unsigned char unk517;         /* 0x517 */
  char pad518[4];
  int unk51c;                   /* 0x51c counter, bumped by the reset */
  unsigned char unk520;         /* 0x520 */
  char pad521[0x558 - 0x521];
  int unk558;                   /* 0x558 */
  char pad55c[0x564 - 0x55c];
  void *obj;                    /* 0x564 allocated by start-up, passed to the per-frame helper */
  char pad568[0x584 - 0x568];
  PrizeInner *inner;            /* 0x584 */
  char pad588[8];
  int unk590;                   /* 0x590 */
  char pad594[0x816c - 0x594];
  int unk816c;                  /* 0x816c */
  char pad8170[4];
  int unk8174;                  /* 0x8174 */
  char pad8178[4];
  int unk817c;                  /* 0x817c */
  char pad8180[0x8198 - 0x8180];
  unsigned char unk8198;        /* 0x8198 */
} PrizeScreen;

#endif
