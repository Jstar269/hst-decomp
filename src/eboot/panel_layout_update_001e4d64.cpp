/* HSTMATCH module=EBOOT.BIN start=0x001e4d64 end=0x001e5050 symbol=FUN_001e4d64 lang=c++ rodata=0x002c8c98 */
/* Hand-written reconstruction from the disassembly; matching idioms: the 20-byte UiSlot{item,val} array (here slots 5..11 of the array at +0x248) addressed as pointer locals &self->slot[k], float t first parameter (f12) passed to both lookup helpers, the non-zero mode arm written first, int sum computed before the item pointer is loaded; exact match verified; names and types await human review. */
#include "hst/ui_panel.h"

/* Virtual interface of the object at unk204. */
struct Ui {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void m8(int, short, short, short, short);
};

extern void *DAT_0034a77c;

extern "C" {
float FUN_0024de20(void *, float);
int FUN_0024dd40(void *, float);
void FUN_000ffb3c(UiItem *, int);
}

/* Sets both ints of the slot's item to the slot value plus an offset. */
#define SET_ITEM_VALUE(slot, offset) \
      v = (slot)->val + (offset); \
      o = (slot)->item; \
      o->unk24 = v; \
      o->unk28 = v

/* Updates the panel's items from the value kind returned by FUN_0024dd40 and the mode, and passes the interpolated span to the ui object. */
extern "C" void FUN_001e4d64(float t, UiPanel *self, int mode)
{
  float ratio = FUN_0024de20(DAT_0034a77c, t);
  int kind = FUN_0024dd40(DAT_0034a77c, t);
  UiSlot *slot6 = &self->slot[6];
  UiSlot *slot7 = &self->slot[7];
  if (kind == 9) {
    FUN_000ffb3c(slot6->item, 1);
    FUN_000ffb3c(slot7->item, 0);
  } else {
    FUN_000ffb3c(slot6->item, 0);
    FUN_000ffb3c(slot7->item, 1);
    int v = slot6->val + kind;
    UiItem *o = slot6->item;
    o->unk24 = v;
    o->unk28 = v;
  }
  ((Ui *)self->unk204)->m8(0, self->unk39c, (short)(self->unk3a8 - (int)(ratio * (float)(self->unk3a8 - self->unk3a0))), self->unk3a4, (short)self->unk3a8);
  UiSlot *slot5 = &self->slot[5];
  UiSlot *slot9 = &self->slot[9];
  UiSlot *slot11 = &self->slot[11];
  if (mode != 0) {
    FUN_000ffb3c(slot9->item, 0);
    FUN_000ffb3c(slot5->item, 0);
    UiItem *o;
    int v;
    switch (mode) {
    case 4:
    case 15:
      SET_ITEM_VALUE(slot5, 1);
      break;
    case 2:
      SET_ITEM_VALUE(slot5, 2);
      break;
    case 8:
      SET_ITEM_VALUE(slot5, 3);
      break;
    case 5:
      SET_ITEM_VALUE(slot5, 4);
      break;
    case 9:
      SET_ITEM_VALUE(slot5, 5);
      break;
    case 7:
      SET_ITEM_VALUE(slot5, 6);
      break;
    case 3:
      SET_ITEM_VALUE(slot5, 7);
      break;
    case 11:
      SET_ITEM_VALUE(slot5, 8);
      break;
    case 12:
      SET_ITEM_VALUE(slot5, 10);
      break;
    case 16:
      SET_ITEM_VALUE(slot5, 11);
      break;
    case 6:
      SET_ITEM_VALUE(slot5, 13);
      break;
    case 13:
      SET_ITEM_VALUE(slot5, 14);
      break;
    case 14:
      SET_ITEM_VALUE(slot5, 0);
      break;
    case 1:
    case 10:
    case 17:
      break;
    default:
      SET_ITEM_VALUE(slot5, 0);
      break;
    }
    FUN_000ffb3c(slot11->item, 0);
  } else {
    FUN_000ffb3c(slot9->item, 1);
    FUN_000ffb3c(slot5->item, 1);
    FUN_000ffb3c(slot11->item, 1);
  }
}
#undef SET_ITEM_VALUE
