/* HSTMATCH module=hstp_trans_main.prx start=0x00272da4 end=0x00272fd4 symbol=FUN_00272da4 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/panel_state_00261f7c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/option_panel.h"

/* Virtual view of the panel: slot 8 reports whether the panel is active. */
struct PanelVirt {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual int v8();
};

/* Singleton with the draw-order setters (slots 5, 6 and 11 are used). */
struct Sng {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5(int);
  virtual void m6(float);
  virtual void m7();
  virtual void m8();
  virtual void m9();
  virtual void m10();
  virtual void m11();
};

struct Ret {
  virtual void g0();
  virtual void g1();
  virtual void g2();
};

extern "C" {
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
void FUN_00108a2c(void *);
void FUN_001bfc3c(void *, int);
int FUN_00111bf8(void *, void *, int, int);
void FUN_00105470(void *, int);
void FUN_002636c0(int, int);
void *FUN_0008f170(void *);
void FUN_00108f54(void *, int);
extern void *DAT_003e1a00;
extern void *DAT_003e1a08;
extern char DAT_003eaad8;
}

/* Per-frame update of the open panel: sounds for cursor moves and confirm, slot highlights, value element. */
extern "C" void FUN_00272da4(OptionPanel *self)
{
  int sel;
  int i;
  LayoutElem *value;

  if (((PanelVirt *)self)->v8() == 0) {
    return;
  }
  ((Sng *)DAT_003e1a00)->m6(99980.0f);
  ((Sng *)DAT_003e1a00)->m5(-256);
  ((Sng *)DAT_003e1a00)->m11();
  FUN_00108e6c(99990.0f, self);
  FUN_001090f4(self, -1);
  FUN_00108a2c(self);
  sel = self->cursor->selected;
  if (self->cursor->unkea != 0) {
    FUN_001bfc3c(&DAT_003eaad8, 1);
  }
  if (self->cursor->unke8 != 0) {
    FUN_001bfc3c(&DAT_003eaad8, 3);
    self->confirmed = 1;
    self->owner->unk80 = sel;
    self->owner->unk84 = self->page;
    self->cursor->unke8 = 0;
  } else {
    if (sel == 3 && FUN_00111bf8(self->cursor, &self->page, 4, 0) != 0) {
      FUN_001bfc3c(&DAT_003eaad8, 1);
    }
  }
  for (i = 0; i < (unsigned)OPTION_SLOT_COUNT; i++) {
    if (i == 0) {
      int sum = self->base + self->page;
      value = self->value;
      value->unk24 = sum;
      value->unk28 = sum;
    }
    FUN_00105470(self->slots[i], i == sel);
  }
  FUN_00105470(self->unk78, self->page == 0);
  FUN_00105470(self->unk7c, self->page == 3);
  self->owner->unk711 = 0;
  self->owner->unk831 = 0;
  FUN_002636c0(10, 0);
  FUN_00108f54(FUN_0008f170(DAT_003e1a08), 0);
  ((Ret *)FUN_0008f170(DAT_003e1a08))->g2();
  self->tick = self->tick + 1;
}
