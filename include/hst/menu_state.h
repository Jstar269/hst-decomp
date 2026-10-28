/* State-machine object (state id at +4, handlers FUN_001c2874..FUN_001c36d8) shared by its handlers. */
#ifndef HST_MENU_STATE_H
#define HST_MENU_STATE_H

typedef struct Vec4 {
  float x, y, z, w;
} Vec4;

/* Object that +0x1c points to; only its state word is read here. */
typedef struct StateSrc {
  int unk0;
  int state;                  /* 0x04 */
} StateSrc;

enum { MENU_STATE_COUNT = 13 };

typedef struct MenuState {
  void *vtbl;                 /* 0x00 */
  unsigned int state;         /* 0x04 current state id, selects the handler */
  int time;                   /* 0x08 compared with triggerTime */
  char pad0c[4];
  int unk10;
  char pad14[4];
  void *parent;               /* 0x18 owner passed to the parent-side helpers */
  StateSrc *src;              /* 0x1c */
  int unk20;
  int unk24;
  int unk28;
  int unk2c;
  int unk30;
  char sub34[0x54 - 0x34];    /* 0x34 sub-object (constructed and destroyed by helpers) */
  int unk54;
  int unk58;
  int unk5c;
  unsigned char unk60;
  unsigned char unk61;
  unsigned char unk62;
  unsigned char unk63;
  unsigned char unk64;
  unsigned char unk65;
  char pad66[2];
  int unk68;
  int unk6c;
  int unk70;
  int unk74;
  int unk78;
  char pad7c[0x90 - 0x7c];
  unsigned char unk90;
  unsigned char unk91;
  char pad92[2];
  int unk94;
  char unk98[0x10];           /* 0x98 cleared by the constructor */
  int unka8;
  int unkac;
  unsigned char unkb0;        /* 0xb0 */
  unsigned char triggered;    /* 0xb1 set once the timed event fired */
  char padb2[2];
  int nextState;              /* 0xb4 state entered after the timed event */
  int effectId;               /* 0xb8 effect to start, < 0 for none */
  int unkbc;
  int triggerTime;            /* 0xc0 time at which the event fires, -1 when none */
  char padc4[0xc];
  Vec4 effectPos;             /* 0xd0 */
  int unke0;
  unsigned char unke4;
  char pade5[3];
  int unke8;
  int unkec;
  unsigned char unkf0;
  unsigned char unkf1;
  char padf2[2];
  int unkf4;
  int unkf8;
  int unkfc;
  int unk100;
  unsigned char unk104;
} MenuState;

#endif
