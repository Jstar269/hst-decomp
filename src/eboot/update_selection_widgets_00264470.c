/* HSTMATCH module=EBOOT.BIN start=0x00264470 end=0x00264550 symbol=FUN_00264470 lang=c99 */
/* Hand-written reconstruction from the disassembly (twin of src/sharing_main/update_selection_widgets_002752ec.c with the callee address substituted); exact match verified; names and types await human review. */
/* Two selections (ints at +0x74 and +0x78 of the object at +0x640, each 0..2) drive six widgets
   through FUN_000ffb3c(widget, on) (sets or clears bit 0 of the widget's halfword at +0xe, then
   calls a virtual method of the widget's +0x20 object when there is one): every widget whose index
   differs from the selection gets on = 1. Two items then get base (+0x6e4) + selection in both
   their words at +0x24 and +0x28. */
typedef struct Item { char pad[0x24]; int f24; int f28; } Item;
typedef struct Sel { char pad[0x74]; int a; int b; } Sel;
typedef struct Self {
  char pad[0x640];
  Sel *sel;
  char pad644[0x6c0 - 0x644];
  void *widgets[6];
  Item *item_a;
  Item *item_b;
  char pad6e0[4];
  int base;
} Self;

extern void FUN_000ffb3c(void *widget, int on);

void FUN_00264470(Self *self)
{
  int v;
  Item *it;

  FUN_000ffb3c(self->widgets[0], self->sel->a != 0);
  FUN_000ffb3c(self->widgets[1], self->sel->a != 1);
  FUN_000ffb3c(self->widgets[2], self->sel->a != 2);
  FUN_000ffb3c(self->widgets[3], self->sel->b != 0);
  FUN_000ffb3c(self->widgets[4], self->sel->b != 1);
  FUN_000ffb3c(self->widgets[5], self->sel->b != 2);
  v = self->base + self->sel->a;
  it = self->item_a;
  it->f24 = v;
  it->f28 = v;
  v = self->base + self->sel->b;
  it = self->item_b;
  it->f24 = v;
  it->f28 = v;
}
