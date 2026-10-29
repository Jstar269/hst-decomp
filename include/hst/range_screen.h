/* Screen object with member objects, a range target and the record read by its update. */
#ifndef HST_RANGE_SCREEN_H
#define HST_RANGE_SCREEN_H

/* Record with three ints read by the update. */
typedef struct RangeRec {
  char pad00[0x14];
  int unk14;                      /* 0x14 */
  int unk18;                      /* 0x18 */
  int unk1c;                      /* 0x1c */
} RangeRec;

typedef struct RangeScreen {
  char pad00[4];
  void *unk04;                    /* 0x04 object with virtual methods */
  void *unk08;                    /* 0x08 object with virtual methods */
  char pad0c[0x20 - 0x0c];
  float *unk20;                   /* 0x20 float block, words 0x18 and 0x19 are written by the update */
  char pad24[4];
  void *unk28;                    /* 0x28 object with virtual methods */
  char pad2c[0x11b8 - 0x2c];
  void *range_obj;                /* 0x11b8 object that gets a (first, last) range, after virtual slot 1 is called with 0 */
  char pad11bc[0x14c0 - 0x11bc];
  RangeRec *rec;                  /* 0x14c0 */
  char pad14c4[0x1750 - 0x14c4];
  void *unk1750;                  /* 0x1750 object with virtual methods; may be null */
} RangeScreen;

#endif
