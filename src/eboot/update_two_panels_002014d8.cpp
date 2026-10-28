/* HSTMATCH module=EBOOT.BIN start=0x002014d8 end=0x00201604 symbol=FUN_002014d8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/game.h"

struct Widget {
  virtual void m0();
  virtual void SetVisible(int);
};
struct TwoPanelMenu {
  int source;      /* 0x00, passed to the lookup */
  int pad04[5];
  Widget *panelA;  /* 0x18 */
  Widget *panelB;  /* 0x1c */
};

/* Row/item bases passed to FUN_00201228 for each panel. */
enum { PANEL_A_FIRST_ROW = 0xd, PANEL_A_SECOND_ROW = 0x13, PANEL_A_ITEM_BASE = 2 };
enum { PANEL_B_FIRST_ROW = 0x1b, PANEL_B_SECOND_ROW = 0x21, PANEL_B_ITEM_BASE = 6 };

extern "C" {
extern Game *DAT_0034a13c;
void FUN_0019335c(int *, int *, int);
void FUN_00201228(TwoPanelMenu *, int, int, int, int);

/* Shows both panels, then hides and fills the ones whose lookup result is non-zero. */
void FUN_002014d8(TwoPanelMenu *self)
{
  int resultA = 0;
  int resultB = 0;
  FUN_0019335c(&resultA, &resultB, self->source);
  self->panelA->SetVisible(1);
  self->panelB->SetVisible(1);
  if (DAT_0034a13c->unkc4 == 0) {
    if (resultA != 0) {
      self->panelB->SetVisible(0);
      FUN_00201228(self, resultA, PANEL_B_FIRST_ROW, PANEL_B_SECOND_ROW, PANEL_B_ITEM_BASE);
    }
  } else if (DAT_0034a13c->unk54 != 0) {
    if (resultA != 0) {
      self->panelA->SetVisible(0);
      FUN_00201228(self, resultA, PANEL_A_FIRST_ROW, PANEL_A_SECOND_ROW, PANEL_A_ITEM_BASE);
    }
    if (resultB != 0) {
      self->panelB->SetVisible(0);
      FUN_00201228(self, resultB, PANEL_B_FIRST_ROW, PANEL_B_SECOND_ROW, PANEL_B_ITEM_BASE);
    }
  }
}
}
