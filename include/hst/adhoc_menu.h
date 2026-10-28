/* Ad-hoc (wireless) game-setup menu object: layout shared by its constructor, reset and sub-screen helpers. */
#ifndef HST_ADHOC_MENU_H
#define HST_ADHOC_MENU_H

typedef struct Group Group; /* named set of screen items, looked up with FUN_001026b8 */

/* Screen widget; only the fields the menu sets are named (it has a vtable at 0). */
typedef struct UiWidget {
  char pad0[0xd8];
  int unkd8;                    /* 0xd8 */
  char paddc[0xf8 - 0xdc];
  void *unkf8;                  /* 0xf8 */
  char padfc[0x114 - 0xfc];
  unsigned char unk114;         /* 0x114 */
  char pad115[0x138 - 0x115];
  int unk138;                   /* 0x138 */
} UiWidget;

/* Named item found in a group. */
typedef struct Item {
  char pad0[4];
  short value;                  /* 0x04 */
  char pad6[0x20 - 6];
  UiWidget *widget;             /* 0x20 */
  int unk24;                    /* 0x24 */
  int unk28;                    /* 0x28 */
} Item;

/* Animated arrow helper (initialised by FUN_0027fed8). */
typedef struct ArrowAnim {
  int unk0;
  short unk4;
  short pad6;
  int unk8;
  unsigned char unkc;
  char padd[3];
} ArrowAnim;

enum {
  ADHOC_PARA_BALLS = 10,        /* crparaball0..9 */
  ADHOC_KOUMOKU = 3,            /* koumoku0..2 */
  ADHOC_MEMBERS = 4,            /* sankasyaname/rank/regulation 0..3 */
  ADHOC_ROOMNUMS = 4,           /* roomnum10/11/30/31 */
  ADHOC_NODATES = 8             /* nodate0..7 */
};

typedef struct AdhocMenu {
  void *vtbl;                   /* 0x00 */
  char pad4[0x54 - 4];
  unsigned char unk54;
  unsigned char unk55;
  char pad56[2];
  UiWidget *unk58;              /* 0x58 */
  void *unk5c;                  /* 0x5c */
  char pad60[4];
  int unk64;
  Group *grpRoom;               /* 0x68 */
  Group *grpCourt;              /* 0x6c main group: court/match settings items */
  Group *grpItems;              /* 0x70 */
  Group *grpMembers;            /* 0x74 */
  Group *grpArrows;             /* 0x78 */
  UiWidget *unk7c;
  UiWidget *unk80;
  int unk84;
  UiWidget *crbg;               /* 0x88 */
  Item *crtype;                 /* 0x8c */
  int crtypeValue;              /* 0x90 */
  Item *crparaball[ADHOC_PARA_BALLS]; /* 0x94 */
  char padbc[0x114 - 0xbc];
  Item *sankaNum;               /* 0x114 */
  int sankaNumValue;
  Item *shiaiType;              /* 0x11c */
  int shiaiTypeValue;
  Item *sdType;                 /* 0x124 */
  int sdTypeValue;
  Item *shiaiBg;                /* 0x12c */
  int shiaiBgValue;
  Item *rangerL0;               /* 0x134 */
  Item *rangerL1;
  Item *rangerR0;
  Item *rangerR1;
  short rangerL0Value;          /* 0x144 */
  short rangerL1Value;
  short rangerR0Value;
  short rangerR1Value;
  int rangerBase;               /* 0x14c */
  UiWidget *courtName;          /* 0x150 */
  Item *yajirushiL;             /* 0x154 */
  Item *yajirushiR;             /* 0x158 */
  ArrowAnim arrowL;             /* 0x15c */
  ArrowAnim arrowR;             /* 0x16c */
  UiWidget *koumoku[ADHOC_KOUMOKU]; /* 0x17c */
  char pad188[4];
  int unk18c;
  Item *iromonoBg0;             /* 0x190 */
  Item *iromonoBg1;             /* 0x194 */
  int iromonoBgValue;           /* 0x198 */
  UiWidget *iromonoInfo0;       /* 0x19c */
  UiWidget *iromonoInfo1;       /* 0x1a0 */
  char pad1a4[0x1f8 - 0x1a4];
  UiWidget *memberName[ADHOC_MEMBERS]; /* 0x1f8 */
  Item *rank[ADHOC_MEMBERS];    /* 0x208 */
  int rankValue;                /* 0x218 */
  UiWidget *regulation[ADHOC_MEMBERS]; /* 0x21c */
  char pad22c[0x38c - 0x22c];
  Item *roomnum[ADHOC_ROOMNUMS]; /* 0x38c */
  short roomnumValue[ADHOC_ROOMNUMS]; /* 0x39c */
  Item *nodate[ADHOC_NODATES];  /* 0x3a4 */
  Item *titleBg;                /* 0x3c4 */
  int unk3c8;
} AdhocMenu;

#endif
