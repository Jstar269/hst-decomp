/* Manager object of the gimmick/gizmo sources: its state object, slot table and registered items. */
#ifndef HST_GIMMICK_MGR_H
#define HST_GIMMICK_MGR_H

/* Item registered in the manager: carries its slot index. */
typedef struct MgrItem {
  char pad00[0x30];
  unsigned int index; /* 0x30 */
  int unk34;          /* 0x34 */
} MgrItem;

typedef struct StateSub {
  char pad00[0x54];
  int unk54;          /* 0x54 */
} StateSub;

/* State object owned by the manager. */
typedef struct GimmickState {
  char pad00[4];
  int kind;           /* 0x4 */
  char pad08[0x20 - 8];
  StateSub *sub;      /* 0x20 */
  char pad24[0x58 - 0x24];
  void *unk58;        /* 0x58 */
  char pad5c[0x6c - 0x5c];
  int unk6c;          /* 0x6c */
} GimmickState;

typedef struct GimmickMgr {
  char pad00[0x7c];
  MgrItem **slots;    /* 0x7c slot table */
  unsigned int slot_count; /* 0x80 */
  char pad84[0x154 - 0x84];
  int unk154;         /* 0x154 */
  char pad158[4];
  GimmickState *state;/* 0x15c */
} GimmickMgr;

#endif
