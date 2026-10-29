/* Target item table of the 0x261000 sources: three 0xf0-byte items, each tracking a position through a target and a float view. */
#ifndef HST_TARGET_ITEMS_H
#define HST_TARGET_ITEMS_H

#define TARGET_ITEM_COUNT 3
#define TARGET_ITEM_SIZE 0xf0         /* bytes per item */
#define TARGET_TINT_NEUTRAL 0x80808080 /* packed colour that leaves the target unchanged */

/* Tracked integer position. */
typedef struct Target {
  int unk0;                   /* 0x00 */
  short x;                    /* 0x04 */
  short y;                    /* 0x06 */
  short sum_x;                /* 0x08 accumulated movement in x */
  short sum_y;                /* 0x0a accumulated movement in y */
} Target;

/* Polymorphic object whose float position mirrors the item's integer one. */
typedef struct TargetView {
  void *vtable;               /* 0x00 */
  char pad04[0x5c];
  float fx;                   /* 0x60 */
  float fy;                   /* 0x64 */
} TargetView;

typedef struct TargetItem {
  Target *target;             /* 0x00 */
  TargetView *view;           /* 0x04 */
  short val_x;                /* 0x08 */
  short val_y;                /* 0x0a */
  int unk0c;                  /* 0x0c */
  int unk10;                  /* 0x10 */
  int unk14;                  /* 0x14 */
  int unk18;                  /* 0x18 */
  char pad1c[4];
  char inner[0x30];           /* 0x20 embedded object; the 4x4 float matrix follows it */
  float matrix[16];           /* 0x50 row-major, translation in the last row */
  char pad90[TARGET_ITEM_SIZE - 0x90];
} TargetItem;

typedef struct TargetCtx {
  TargetItem items[TARGET_ITEM_COUNT];
  int pad2d0[2];
  int unk2d8;                 /* 0x2d8 */
} TargetCtx;

#endif
