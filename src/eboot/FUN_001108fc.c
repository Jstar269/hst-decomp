/* HSTMATCH module=EBOOT.BIN start=0x001108fc end=0x00110a78 symbol=FUN_001108fc lang=c99 data=0x002d9264 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001108fc.c) corrected by hand: used float member copies, volatile flag rereads, and a shared post-cleanup object load; readability pass; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002d9264-0x002d92b0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/messe_layout.h"

/* Result of a by-name child lookup. */
typedef struct MesseRef {
  char pad00[0x20];
  MessePane *pane;      /* 0x20 */
} MesseRef;

extern u8 DAT_002d9210;
extern u8 DAT_00307dd4;
extern MesseRef *FUN_001026b8();
extern MesseLayout * FUN_00102e38();
extern void FUN_00103480();
extern MessePane *FUN_001039d8();
extern void FUN_00104118();
extern void FUN_0010d4a8(MessePane *);

/* Construct the info message layout: load it and set up its two text panes (text1 copies text0's position). */
MesseLayout * FUN_001108fc(MesseLayout *self)
{
  MessePane *pane;
  
  FUN_00102e38(self);
  self->vtable = (u32 *)&DAT_00307dd4;
  self->unk54 = &DAT_002d9210;
  self->state = MESSE_WAIT;
  self->unk64 = 0;
  self->timer = 0;
  self->gap = 0.0f;
  self->width = 0.0f;
  FUN_00104118(self,"data/menu/menu_common/info_messe_layout.lay",0);
  pane = FUN_001039d8(self,"messe",0);
  pane = FUN_001026b8(pane,"messe_text0")->pane;
  self->text0 = pane;
  pane = FUN_001039d8(self,"messe",0);
  pane = FUN_001026b8(pane,"messe_text1")->pane;
  self->text1 = pane;
  pane->x = self->text0->x;
  self->text1->y = self->text0->y;
  FUN_00103480(self);
  pane = self->text0;
  pane->flag = 1;
  if (pane->flag == 0) {
    FUN_0010d4a8(pane);
    pane = self->text1;
  }
  else {
    pane = self->text1;
  }
  pane->flag = 1;
  if (pane->flag == 0) {
    FUN_0010d4a8(pane);
  }
  pane = self->text0;
  pane = self->text0;
  pane->unk13c = 0x3f800000;
  pane->unk140 = 0;
  pane = self->text1;
  pane->unk13c = 0x3f800000;
  pane->unk140 = 0;
  pane = self->text0;
  pane->unkf8 = &DAT_002d9210;
  pane->unk138 = 0;
  FUN_0010d4a8(pane);
  pane = self->text1;
  pane->unkf8 = &DAT_002d9210;
  pane->unk138 = 0;
  FUN_0010d4a8(pane);
  self->pos0 = 480.0f;
  self->pos1 = 480.0f;
  return self;
}
