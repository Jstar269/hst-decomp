/* HSTMATCH module=EBOOT.BIN start=0x00261e1c end=0x00261f7c symbol=FUN_00261e1c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/option_panel.h"

extern int DAT_00309380;
extern int DAT_00309a54;
extern int DAT_003386c8;
extern int DAT_002fdd78;
extern int DAT_002fdd98;
extern int DAT_002fdda4;
extern int DAT_002fddac;
extern int DAT_002fddb8;
extern int DAT_002fddc8;
extern int DAT_002fddd8;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void *FUN_001039d8(void *, void *, int);
extern "C" LayoutElem *FUN_001026b8(void *, void *);
extern "C" void FUN_000143b0(void *, void *, unsigned);

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

/* Slot pointer at a byte offset from the first slot. */
static inline LayoutElem **SlotOf(OptionPanel *s, int off) {
    return (LayoutElem **)((char *)s + off + 0x68);
}

/* Constructor: builds the option panel from its layout (sets the second vtable after the base). */
extern "C" OptionPanel *FUN_00261e1c(OptionPanel *self) {
    FUN_00102e38(self);
    self->vtable = &DAT_00309380;
    self->unk54 = 0;
    self->confirmed = 0;
    self->cursor = 0;
    self->vtable = &DAT_00309a54;
    OptionOwner *owner = *(OptionOwner **)(DAT_003386c8 + 0x40);
    self->owner = owner;
    FUN_00104118(self, &DAT_002fdd78, 0);
    self->pane = FUN_001039d8(self, &DAT_002fdd98, 0);
    LayoutElem *e = FUN_001026b8(self->pane, &DAT_002fdda4);
    CursorWidget *cursor = e->widget;
    self->cursor = cursor;
    cursor->unkd8 = 2;
    cursor->unk114 = 1;
    char buf[0x40];
    unsigned i = 0;
    unsigned off = 0;
    for (; i < OPTION_SLOT_COUNT; i++) {
        FUN_000143b0(buf, &DAT_002fddac, i);
        *SlotOf(self, off) = FUN_001026b8(self->pane, buf);
        off += 4;
    }
    self->unk78 = FUN_001026b8(self->pane, &DAT_002fddb8);
    self->unk7c = FUN_001026b8(self->pane, &DAT_002fddc8);
    LayoutElem *w = FUN_001026b8(self->pane, &DAT_002fddd8);
    self->value = w;
    self->base = w->unk24;
    self->page = 1;
    self->confirmed = 0;
    ((Base *)self)->m7();
    return self;
}
