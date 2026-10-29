/* HSTMATCH module=EBOOT.BIN start=0x000eed74 end=0x000eee60 symbol=FUN_000eed74 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern "C" PaneItemDef DAT_002d7054[];
extern "C" float DAT_002d6c9c;
extern "C" char DAT_002d7084[];
extern "C" char DAT_002d7028[];
extern "C" char DAT_00307914[];

extern "C" void FUN_00102e38();
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" PaneLayer *FUN_001039d8(void *, void *, int);
extern "C" PaneItem *FUN_001026b8(void *, void *);
extern "C" void FUN_000eee98(void *);

/* SmallPane constructor: loads the layout, its layer and 4 named items, then shows the pane. */
extern "C" SmallPane *FUN_000eed74(SmallPane *self) {
    int i;
    PaneItemDef *e;
    int off;
    char *bytes = (char *)self;
    FUN_00102e38();
    self->base.vtbl = &DAT_00307914;
    FUN_00104118(self, DAT_002d7084, 0);
    FUN_00103540(self, DAT_002d6c9c);
    FUN_001037c8(self, 0xffffff05);
    {
    void **pq = (void **)&DAT_002d7028;
    int j;
    for (j = 0; j < 1; j++) {}
    self->layer = FUN_001039d8(self, *pq, 0);
    }
    i = 0;
    e = DAT_002d7054;
    off = 0;
    do {
        PaneItem *q = FUN_001026b8(*(void **)(bytes + 0x58 + e->layer * 4), e->name);
        *(PaneItem **)(bytes + 0x5c + off) = q;
        i = i + 1;
        off = off + 4;
        e->value = q->unk24;
        e++;
    } while (i < 4);
    FUN_000eee98(self);
    return self;
}
// near miss from lane ds7 (unreviewed)
