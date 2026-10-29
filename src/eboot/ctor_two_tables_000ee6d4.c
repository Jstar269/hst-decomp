/* HSTMATCH module=EBOOT.BIN start=0x000ee6d4 end=0x000ee7f8 symbol=FUN_000ee6d4 lang=c99 data=0x002d6e6c */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling ctor_two_tables_000f13e8.cpp); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d6e6c-0x002d6e97) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/inp_panes.h"

extern void FUN_00102e38(ReplayPane *self);
extern void FUN_00104118(ReplayPane *self, char *name, int flag);
extern void FUN_00103540(ReplayPane *self, float value);
extern void FUN_001037c8(ReplayPane *self, int v);
extern PaneLayer *FUN_001039d8(ReplayPane *self, char *src, int flag);
extern PaneItem *FUN_001026b8(PaneLayer *layer, char *name);
extern void FUN_000ffc3c(PaneItem *item, int v);
extern void FUN_000ee860(ReplayPane *self);
extern char DAT_00307954[];
extern float DAT_002d6c9c;
extern char *DAT_002d6d3c[];
extern PaneItemDef DAT_002d6ddc[];

#define ITEM_PRIORITY (-250)

/* Replay pane constructor: loads inp_replay.lay, its five layers and twelve named items, then shows it. */
ReplayPane *FUN_000ee6d4(ReplayPane *self)
{
    char *bytes = (char *)self;
    FUN_00102e38(self);
    self->base.vtbl = &DAT_00307954;
    FUN_00104118(self, "data/menu/inpane/inp_replay/inp_replay.lay", 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    char **src = DAT_002d6d3c;
    int off = 0; /* byte offset into the layer / item arrays (kept as an offset: retail does not scale an index) */
    do {
        *(PaneLayer **)(bytes + off + 0x5c) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < REPLAY_LAYER_COUNT);
    int j = 0;
    PaneItemDef *e = DAT_002d6ddc;
    off = 0;
    do {
        PaneItem *h = FUN_001026b8(self->layer[e->layer], e->name);
        *(PaneItem **)(bytes + off + 0x70) = h;
        e->value = h->unk24;
        FUN_000ffc3c(*(PaneItem **)(bytes + off + 0x70), ITEM_PRIORITY);
        j++;
        e++;
        off += 4;
    } while (j < REPLAY_ITEM_COUNT);
    self->unkA0 = self->item[10]->unk20;
    FUN_000ee860(self);
    return self;
}
