/* HSTMATCH module=EBOOT.BIN start=0x000f2410 end=0x000f2548 symbol=FUN_000f2410 lang=c99 data=0x002d79b4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d79b4-0x002d79e0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/sabu_pane.h"

extern void FUN_00102e38(SabuPane *self);
extern void FUN_00104118(SabuPane *self, char *name, int flag);
extern void FUN_00103540(SabuPane *self, float value);
extern void FUN_001037c8(SabuPane *self, int value);
extern PosLayer *FUN_001039d8(SabuPane *self, char *src, int flag);
extern PaneItem *FUN_001026b8(PosLayer *layer, char *name);
extern void FUN_000f2550(SabuPane *self);
extern char DAT_00307814[];
extern float DAT_002d6c9c;
extern char *DAT_002d78f4[];
extern PaneItemDef DAT_002d7948[];

/* Sabu pane constructor: loads inpane_sabu.lay, its three layers and nine named items. */
SabuPane *FUN_000f2410(SabuPane *self)
{
    char *bytes = (char *)self;
    FUN_00102e38(self);
    self->vtbl = &DAT_00307814;
    FUN_00104118(self, "data/menu/inpane/inp_ingame/inpane_sabu.lay", 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    char **src = DAT_002d78f4;
    int off = 0; /* byte offset into the layer / item arrays */
    do {
        *(PosLayer **)(bytes + off + 0x54) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < SABU_LAYER_COUNT);
    int j = 0;
    PaneItemDef *e = DAT_002d7948;
    off = 0;
    do {
        PaneItem *h = FUN_001026b8(self->layer[e->layer], e->name);
        *(PaneItem **)(bytes + off + 0x60) = h;
        e->value = h->unk24;
        j++;
        off += 4;
        e++;
    } while (j < SABU_ITEM_COUNT);
    self->unk88 = 0;
    self->unk8c = 0;
    self->unk94 = 0;
    self->unka0 = 0;
    self->unk98 = 0;
    self->unka1 = 0;
    self->unk9c = 0;
    self->unka2 = 0;
    self->unk90 = 2;
    self->unka4 = 0;
    FUN_000f2550(self);
    return self;
}
