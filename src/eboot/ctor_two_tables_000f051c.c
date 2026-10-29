/* HSTMATCH module=EBOOT.BIN start=0x000f051c end=0x000f0644 symbol=FUN_000f051c lang=c99 data=0x002d7428 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d7428-0x002d7453) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/ingame_panes.h"

extern void FUN_00102e38(AcePane *self);
extern void FUN_00104118(AcePane *self, char *name, int flag);
extern void FUN_00103540(AcePane *self, float value);
extern void FUN_001037c8(AcePane *self, int value);
extern PaneLayer *FUN_001039d8(AcePane *self, char *src, int flag);
extern PaneQuad *FUN_001026b8(PaneLayer *layer, char *name);
extern void FUN_000f0938(AcePane *self);
extern char DAT_003078b4[];
extern float DAT_002d6c9c;
extern char *DAT_002d73dc[];
extern PaneItemDef DAT_002d73f8[];

/* Ace pane constructor: loads inpane_ace.lay, its two layers and four named quad items. */
AcePane *FUN_000f051c(AcePane *self)
{
    char *bytes = (char *)self;
    FUN_00102e38(self);
    self->base.vtbl = &DAT_003078b4;
    FUN_00104118(self, "data/menu/inpane/inp_ingame/inpane_ace.lay", 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    char **src = DAT_002d73dc;
    int off = 0; /* byte offset into the layer / item arrays (kept as an offset, as in the sibling constructors) */
    do {
        *(PaneLayer **)(bytes + off + 0x58) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < ACE_LAYER_COUNT);
    int j = 0;
    PaneItemDef *e = DAT_002d73f8;
    off = 0;
    do {
        PaneQuad *h = FUN_001026b8(self->layer[e->layer], e->name);
        *(PaneQuad **)(bytes + off + 0x60) = h;
        e->value = h->value;
        *(float *)(bytes + off + 0x70) = (float)(*(PaneQuad **)(bytes + off + 0x60))->y0;
        j++;
        off += 4;
        e++;
    } while (j < ACE_ITEM_COUNT);
    FUN_000f0938(self);
    self->unk80 = 0x3f800000;
    return self;
}
