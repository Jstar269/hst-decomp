/* Character model object of the 0x92000 sources: six model-item slots, a body-type id and its mesh object. */
#ifndef HST_CHAR_MODEL_H
#define HST_CHAR_MODEL_H

enum {
  CHAR_ITEM_SLOTS = 6,       /* model-item slots; slot 2 owns the extra index table, slot 5 the bone lookup */
  CHAR_INDEX_NONE = -1       /* "no entry" in the index words and in body_type */
};

struct List;

/* Bone controller of a model item; its list holds the named bones. */
typedef struct ModelCtrl {
  char pad00[8];
  struct List *list;         /* 0x08 */
} ModelCtrl;

/* Per-channel entry of a model item (stride 0x34). */
typedef struct ItemChan {
  int state;                 /* 0x00 */
  char pad04[0x34 - 4];
} ItemChan;

typedef struct ModelItem {
  char pad00[0x8c];
  ModelCtrl *ctrl;           /* 0x8c */
  char pad90[0xa0 - 0x90];
  int unka0;                 /* 0xa0 */
  char pada4[0xc0 - 0xa4];
  char unkc0;                /* 0xc0 */
  char padc1[3];
  float unkc4;               /* 0xc4 */
  char padc8[0xd0 - 0xc8];
  float unkd0;               /* 0xd0 */
  char padd4[0xf0 - 0xd4];
  ItemChan chan[2];          /* 0xf0 channels, at least two */
  char pad158[0x170 - 0x158];
  unsigned char unk170;      /* 0x170 */
  char pad171[0x1b4 - 0x171];
  unsigned id;               /* 0x1b4 key into the entry table */
} ModelItem;

struct ModelMesh;

typedef struct CharModel {
  char pad00[4];
  int index[7];              /* 0x04 reset to -1 when slot 2 is cleaned up */
  int unk20;                 /* 0x20 reset to -1 when slot 5 is cleaned up */
  char pad24[0x50 - 0x24];
  ModelItem *item[CHAR_ITEM_SLOTS]; /* 0x50 */
  int body_type;             /* 0x68 body type id, -1 when none loaded */
  struct ModelMesh *mesh;    /* 0x6c object built from the body-type file */
  void *unk70;               /* 0x70 released with slot 0 */
  char flags;                /* 0x74 */
  unsigned char unk75;       /* 0x75 */
} CharModel;

#endif
