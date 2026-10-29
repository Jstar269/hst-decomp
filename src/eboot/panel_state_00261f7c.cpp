/* HSTMATCH module=EBOOT.BIN start=0x00261f7c end=0x002621ac symbol=FUN_00261f7c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_00103128(void *);
void FUN_001b1c44(void *, int);
int FUN_0010ba20(void *, void *, int, int);
void FUN_000ffb3c(void *, int);
void FUN_0025336c(int, int);
void *FUN_0008d994(void *);
void FUN_00103628(void *, int);
extern void *DAT_003386c0;
extern void *DAT_003386c8;
extern char DAT_0034179c;
}

/* Per-frame update of the open panel: sounds for cursor moves and confirm, slot highlights, value element. */
extern "C" void FUN_00261f7c(OptionPanel *self)
{
  int sel;
  int i;
  LayoutElem *value;

  if (((PanelVirt *)self)->v8() == 0) {
    return;
  }
  ((Sng *)DAT_003386c0)->m6(99980.0f);
  ((Sng *)DAT_003386c0)->m5(-256);
  ((Sng *)DAT_003386c0)->m11();
  FUN_00103540(99990.0f, self);
  FUN_001037c8(self, -1);
  FUN_00103128(self);
  sel = self->cursor->selected;
  if (self->cursor->unkea != 0) {
    FUN_001b1c44(&DAT_0034179c, 1);
  }
  if (self->cursor->unke8 != 0) {
    FUN_001b1c44(&DAT_0034179c, 3);
    self->confirmed = 1;
    self->owner->unk80 = sel;
    self->owner->unk84 = self->page;
    self->cursor->unke8 = 0;
  } else {
    if (sel == 3 && FUN_0010ba20(self->cursor, &self->page, 4, 0) != 0) {
      FUN_001b1c44(&DAT_0034179c, 1);
    }
  }
  for (i = 0; i < (unsigned)OPTION_SLOT_COUNT; i++) {
    if (i == 0) {
      int sum = self->base + self->page;
      value = self->value;
      value->unk24 = sum;
      value->unk28 = sum;
    }
    FUN_000ffb3c(self->slots[i], i == sel);
  }
  FUN_000ffb3c(self->unk78, self->page == 0);
  FUN_000ffb3c(self->unk7c, self->page == 3);
  self->owner->unk711 = 0;
  self->owner->unk831 = 0;
  FUN_0025336c(10, 0);
  FUN_00103628(FUN_0008d994(DAT_003386c8), 0);
  ((Ret *)FUN_0008d994(DAT_003386c8))->g2();
  self->tick = self->tick + 1;
}
