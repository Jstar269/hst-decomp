/* Menu entry panel widgets: sprite items, text labels and the text widget behind each label. */
#ifndef HST_ENTRY_PANEL_H
#define HST_ENTRY_PANEL_H

#include "hst/types.h"

/* Text widget: string pointer and a visible flag. */
typedef struct EntryText {
  char pad0[0xf8];
  const char *str;      /* 0xf8 */
  char padfc[0x138 - 0xfc];
  int visible;          /* 0x138 */
} EntryText;

typedef struct EntryLabel {
  int unk0;
  EntryText *text;      /* 0x04 */
  int unk8;
} EntryLabel;           /* size 0x0c */

typedef struct EntrySprite {
  char pad0[0x24];
  int frame;            /* 0x24 current frame */
  int baseFrame;        /* 0x28 first frame of the animation */
} EntrySprite;

typedef struct EntryItem {
  EntrySprite *spr;     /* 0x00 */
  char pad4[0x10];
} EntryItem;            /* size 0x14 */

/* One of the eight id bytes in an info record. */
typedef struct EntrySlot {
  unsigned char v;
  unsigned char pad[2];
} EntrySlot;

/* Info record of an entry (id, rank, kind and a table of slot ids). */
typedef struct EntryInfo {
  short id;              /* 0x00 */
  char pad2[8];
  short rank;            /* 0x0a */
  char padc[2];
  unsigned char kind;    /* 0x0e */
  char padf[0x20 - 0xf];
  unsigned short unk20;  /* 0x20 */
  char pad22[0x7c - 0x22];
  unsigned char unk7c;   /* 0x7c */
  EntrySlot slots[8];    /* 0x7d */
} EntryInfo;

/* One entry record of the manager (stride 0x30). */
typedef struct EntryRec {
  int unk0;
  EntryInfo *info;       /* 0x04 */
  unsigned char unk8;    /* 0x08 */
  unsigned char unk9;    /* 0x09 */
  unsigned char unka;    /* 0x0a nonzero when the entry is marked */
  char padb[5];
  char name[0x20];       /* 0x10 */
} EntryRec;

typedef struct EntryFlags {
  char pad0[0x10];
  unsigned char unk10[4]; /* 0x10 */
  unsigned char unk14[4]; /* 0x14 */
} EntryFlags;

/* Global manager object (fields used by the entry panel sources). */
typedef struct EntryMgr {
  char pad0[0x58];
  unsigned char unk58;   /* 0x58 */
  char pad59[0x64 - 0x59];
  int unk64;             /* 0x64 */
  char pad68[0x88 - 0x68];
  EntryFlags *flags;     /* 0x88 */
  char pad8c[0x160 - 0x8c];
  EntryRec *recs;        /* 0x160 */
  char pad164[0x2a4 - 0x164];
  unsigned char unk2a4;  /* 0x2a4 */
  unsigned char unk2a5;  /* 0x2a5 */
} EntryMgr;

/* Entry panel: sprite items and text labels. */
typedef struct EntryPanel {
  char pad0[0x2c];
  EntryItem items[104];  /* 0x2c */
  EntryLabel labels[8];  /* 0x84c */
} EntryPanel;

#endif
