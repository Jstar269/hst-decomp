/* HSTMATCH module=EBOOT.BIN start=0x00222bb8 end=0x00222f58 symbol=FUN_00222bb8 lang=c++ data=0x002f0fb4 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: #pragma opt_strength_reduction off with the pointer walks written out by hand [the panes loop walks a PrizeDisplay pointer by 4, the two 16-entry clears walk the row pointer by 0x30 and MWCC unrolls them 8x], the has_choice != 0 arm written first, the float defaults as ternaries 'alt_layout != 0 ? G : 0.0f', and sel_index declared before list); names and types await human review. Data: its string literals (2 strings, 0x002f0fb4-0x002f1000) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#pragma opt_strength_reduction off

#include "hst/prize_display.h"

struct Widget {
  virtual ~Widget();
};
struct Choice {
  virtual void m0();
  virtual void m1(int on);
};
struct Item {
  char pad[0x24];
  int f24;
  int f28;
};
struct ItemList {
  char pad[0x10];
  void **items;
  int count;
};
extern "C" {
extern int DAT_002eff90;
extern float DAT_002eff88;
extern char DAT_002f0190[];
extern char DAT_0030ebf4[];
extern float DAT_0034a270;
extern float DAT_0034a274;
extern float DAT_0034a280;
extern float DAT_002f0fac;
extern float DAT_002f0fb0;
extern PrizeRow *DAT_0034a268;
extern PrizeRow *DAT_0034a26c;
extern char DAT_0034179c[];
void FUN_00223094(PrizeDisplay *);
int FUN_000143b0(char *, const char *, ...);
void FUN_00218ae4(int *, int *, int);
void FUN_000ffb3c(void *, int);
int FUN_00014934(const char *, const char *);
void FUN_0001cad0(void *, int, char *);
void FUN_0001cb88(void *);
void *FUN_00050fc0(void *);
void FUN_000511c4(void *, char *, int);
void FUN_00051398(float, void *);
int FUN_001fea10(int, int, int);
void FUN_0010d4a8(void *);
void FUN_00103480(PrizeDisplay *);
int FUN_001b2af0(void *, int);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Reset the prize display: load the selected prize's info page (or the choice list), position the panes and clear the two row tables. */
extern "C" void FUN_00222bb8(PrizeDisplay *self, int value54, int alt_layout)
{
  char buf[256];
  self->state = DAT_002eff90;
  self->unk54 = value54;
  self->alt_layout = alt_layout;
  self->active = 1;
  self->selected = 0;
  self->scroll = 0;
  FUN_00223094(self);
  FUN_000143b0(buf, DAT_002f0190);
  if (self->info_widget != 0) {
    if (self->info_widget != 0) {
      delete self->info_widget;
      self->info_widget = 0;
    }
  }
  FUN_00218ae4(&self->selected, &self->scroll, self->unk54);
  if (self->has_choice != 0) {
    self->choice->m1(1);
    int sel_index = self->selected;
    ItemList *list = (ItemList *)self->choice;
    int i;
    for (i = 0; i < list->count; i++)
      FUN_000ffb3c(list->items[i], i != sel_index);
    Item *item = (Item *)((ItemList *)self->choice)->items[self->selected];
    item->f24 = item->f28 + self->scroll;
  }
  FUN_000143b0(buf, "data/menu/menu_common/info_kunsyou%03d", self->selected + 1);
  if (self->has_choice == 0) {
    if (FUN_00014934(buf, DAT_002f0190) != 0) {
      FUN_0001cad0(DAT_0030ebf4, 1, "game/700_prize/040_prize_display.xb");
      void *widget = ::operator new(0x48);
      if (widget != 0)
        widget = FUN_00050fc0(widget);
      self->info_widget = (Widget *)widget;
      FUN_000511c4(widget, buf, 0);
      FUN_00051398(10.0f + DAT_002eff88, self->info_widget);
      FUN_0001cb88(DAT_0030ebf4);
    }
  }
  int board_id = FUN_001fea10(9, 4, self->unk54);
  char *board_bytes = (char *)self->board;
  *(int *)(board_bytes + 0xf8) = board_id;
  *(int *)(board_bytes + 0x138) = 1;
  FUN_0010d4a8(board_bytes);
  int i = 0;
  PrizeDisplay *pane_walker = self;
  do {
    if (pane_walker->panes[0] != 0) {
      if (i == 0) {
        float dx = alt_layout != 0 ? DAT_0034a270 : 0.0f;
        pane_walker->panes[0]->x = self->base_x + dx;
        float dy = alt_layout != 0 ? DAT_0034a274 : 0.0f;
        pane_walker->panes[0]->y = self->base_y + dy;
      }
      float scale = alt_layout != 0 ? DAT_0034a280 : 1.0f;
      pane_walker->panes[0]->scale = Clamp(scale, DAT_002f0fac, DAT_002f0fb0);
    }
    i++;
    pane_walker = (PrizeDisplay *)((char *)pane_walker + 4);
  } while (i < PRIZE_PANE_COUNT);
  FUN_00103480(self);
  FUN_000ffb3c(self->color, 1);
  *self->color = 0xffffff;
  PrizeRow *row = DAT_0034a268;
  for (int n = 0; n < PRIZE_ROW_COUNT; n++) {
    row->shown = 0;
    row++;
  }
  row = DAT_0034a26c;
  for (int n = 0; n < PRIZE_ROW_COUNT; n++) {
    row->shown = 0;
    row++;
  }
  self->unk64 = FUN_001b2af0(DAT_0034179c, 12);
}
