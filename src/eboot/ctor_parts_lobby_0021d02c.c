/* HSTMATCH module=EBOOT.BIN start=0x0021d02c end=0x0021d15c symbol=FUN_0021d02c lang=c99 data=0x002f05f8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002f05f8-0x002f0615) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Same shape as src/eboot/ctor_models_002215b8.c (used as the template): base ctor, vtable-ish pointer, layout load, 3 widget lookups and 9 model lookups with byte-offset induction variables. */
#include "hst/parts_pane.h"

extern void FUN_00102e38(PartsPane *self);
extern void FUN_00104118(PartsPane *self, char *name, int flag);
extern void FUN_00103540(float value, PartsPane *self);
extern PartsLayer *FUN_001039d8(PartsPane *self, char *src, int flag);
extern PaneItem *FUN_001026b8(PartsLayer *layer, char *name);
extern void FUN_0021d340(PartsPane *self, int selected);
extern void FUN_0021d3c0(PartsPane *self);
extern char DAT_00309764[];
extern float DAT_002eff88;
extern char *DAT_002f0554[];
extern PaneItemDef DAT_002f057c[];

/* Parts pane constructor: loads partslay.lay with its three layers and nine items, then shows the first layer. */
PartsPane *FUN_0021d02c(PartsPane *self)
{
    char *bytes = (char *)self; /* byte offsets below: retail does not scale an index */
    FUN_00102e38(self);
    self->base.vtbl = &DAT_00309764;
    FUN_00104118(self, "data/menu/parts/partslay.lay", 0);
    FUN_00103540(10.0f + DAT_002eff88, self);
    int i = 0;
    char **src = DAT_002f0554;
    int off = 0;
    do {
        *(PartsLayer **)(bytes + off + 0x70) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < PARTS_LAYER_COUNT);
    int j = 0;
    PaneItemDef *e = DAT_002f057c;
    off = 0;
    do {
        PaneItem *h = FUN_001026b8(*(PartsLayer **)(bytes + e->layer * 4 + 0x70), e->name);
        *(PaneItem **)(bytes + off + 0x7c) = h;
        e->value = h->unk24;
        j++;
        off += 4;
        e++;
    } while (j < PARTS_ITEM_COUNT);
    self->mode = 0;
    self->variant = 0;
    self->timer = PARTS_TIMER_OFF;
    self->active = 0;
    self->sound = PARTS_NO_SOUND;
    FUN_0021d340(self, 0);
    FUN_0021d3c0(self);
    return self;
}
