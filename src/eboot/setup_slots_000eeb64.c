/* HSTMATCH module=EBOOT.BIN start=0x000eeb64 end=0x000eec94 symbol=FUN_000eeb64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"
#include "hst/info_rec.h"

typedef struct Cfg {
  char pad[0x1364];
  int idx;                      /* 0x1364 index of the selected record */
} Cfg;

extern Cfg *DAT_003402a0;
extern void *DAT_0034a7ec;
extern int DAT_002d6f64;
extern int DAT_002d6f70;
extern void FUN_000eecc4(SlotPane *);
extern void FUN_001036f8(SlotPane *, int);
extern InfoRec *FUN_0027edbc(void *, int);
extern int FUN_000ca4a4(void);
extern void FUN_000ffb3c(PaneItem *, int);

/* Sets both words of an item's range to the same value. */
static inline void SetRange(PaneItem *n, int v)
{
  n->unk24 = v;
  n->unk28 = v;
}

/* Resets the slot pane and lights as many slots in each row as the selected record says. */
void FUN_000eeb64(SlotPane *self)
{
  int mode;
  int idx;
  InfoRec *info;
  int slotsB, slotsA;
  int i;

  FUN_000eecc4(self);
  FUN_001036f8(self, 0);
  mode = 0;
  idx = DAT_003402a0->idx;
  i = idx - 1;
  info = FUN_0027edbc(DAT_0034a7ec, idx);
  slotsA = info->slotsA;
  slotsB = info->slotsB;
  switch (FUN_000ca4a4()) {
  case 1:
    mode = 1;
    break;
  case 0:
    mode = 2;
    break;
  case 2:
    break;
  }
  SetRange(self->item[SLOT_ITEM_NUMBER], DAT_002d6f64 + i);
  SetRange(self->item[SLOT_ITEM_MODE], DAT_002d6f70 + mode);
  for (i = 0; i < SLOT_PANE_COLUMNS; i++) {
    if (i < slotsA) {
      FUN_000ffb3c(self->item[SLOT_ITEM_ROW_A + i], 0);
    } else {
      FUN_000ffb3c(self->item[SLOT_ITEM_ROW_A + i], 1);
    }
    if (i < slotsB) {
      FUN_000ffb3c(self->item[SLOT_ITEM_ROW_B + i], 0);
    } else {
      FUN_000ffb3c(self->item[SLOT_ITEM_ROW_B + i], 1);
    }
  }
}
