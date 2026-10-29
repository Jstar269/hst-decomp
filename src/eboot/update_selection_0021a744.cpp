/* HSTMATCH module=EBOOT.BIN start=0x0021a744 end=0x0021a9ec symbol=FUN_0021a744 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/selection_menu.h"

/* Config byte with a 2-bit field at bits 2..3 (read as signed). */
struct ConfigBits {
    char pad[0x8b];
    signed char unk8b;
};

/* Chain of records reached from the global at DAT_003415ac; the last holds a halfword of flags. */
struct FlagRec {
    unsigned short pad[7];
    unsigned short flags;  /* 0x0e */
};

struct ChainC {
    FlagRec *rec;          /* 0x00 */
};

struct ChainB {
    char pad[0x10];
    ChainC *unk10;         /* 0x10 */
};

struct ChainA {
    char pad[0x54];
    ChainB *unk54;         /* 0x54 */
};

/* Virtual interface of the menu's text object. */
struct TextObj {
    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
};

extern "C" {
extern ConfigBits *DAT_002cfc8c;
extern void *DAT_002efb40[];
extern ChainA *DAT_003415ac;
extern int DAT_0034179c;

bool FUN_001fe080(void *, int, int);
void FUN_001b1c44(void *, int);
void FUN_0010b980(void *, int, int);
void *FUN_001fea10(int, int, void *);
void FUN_00110a78(void *, void *, int);
void FUN_000ffb3c(void *, int);
void FUN_00103128(void *);
}

/* Moves the cursor from the two input tests (wrapping at count), refreshes the slot widgets and the text. */
extern "C" void FUN_0021a744(SelectionMenu *self)
{
    int prev_cursor = self->cursor;
    bool backward = FUN_001fe080(&self->unk10c, 16, 0);
    bool forward = FUN_001fe080(&self->unk110, 64, 0);

    if (backward) {
        int next = self->cursor - 1;
        self->cursor = next;
        if (next < 0) {
            self->cursor = self->count - 1;
        } else if (next == 0) {
            self->unk10c = -1;
        }
    } else if (forward) {
        int next = self->cursor + 1;
        self->cursor = next;
        if (next >= self->count) {
            self->cursor = 0;
        } else if (next == self->count - 1) {
            self->unk110 = -1;
        }
    } else {
        if ((((int)DAT_002cfc8c->unk8b << 28) >> 30 == 0) && self->unk54 == 0) {
            self->unk54 = 1;
            FUN_001b1c44(&DAT_0034179c, 3);
        }
    }

    if (prev_cursor != self->cursor) {
        FUN_001b1c44(&DAT_0034179c, 1);
        FUN_0010b980(self->unke4, self->cursor, 0);
        if (self->text != 0) {
            void *item_str = FUN_001fea10(18, 33, DAT_002efb40[self->item[self->cursor]]);
            FUN_00110a78(self->text, item_str, 0);
        }
    }

    /* Three passes over the slots; the later passes count i from SELECTION_SLOT_COUNT and 2x that
       (the slot is i minus the pass start), which is the form that compiles to retail. */
    for (int i = 0; i <= SELECTION_SLOT_COUNT - 1; i++) {
        if (self->item[i] != SELECTION_ITEM_NONE) {
            FUN_000ffb3c(self->unk64[i], i == self->cursor);
        } else {
            FUN_000ffb3c(self->unk64[i], 1);
        }
    }

    for (int i = SELECTION_SLOT_COUNT; i <= 2 * SELECTION_SLOT_COUNT - 1; i++) {
        if (self->item[i - SELECTION_SLOT_COUNT] != SELECTION_ITEM_NONE) {
            FUN_000ffb3c(self->unk80[i - SELECTION_SLOT_COUNT], (i - SELECTION_SLOT_COUNT) != self->cursor);
        } else {
            FUN_000ffb3c(self->unk80[i - SELECTION_SLOT_COUNT], 1);
        }
    }

    for (int i = 2 * SELECTION_SLOT_COUNT; i <= 3 * SELECTION_SLOT_COUNT - 1; i++) {
        FUN_000ffb3c(self->unk9c[i - 2 * SELECTION_SLOT_COUNT], (i - 2 * SELECTION_SLOT_COUNT) != self->cursor);
    }

    FUN_000ffb3c(self->unkbc, ((DAT_003415ac->unk54->unk10->rec->flags & 3) != 0) ^ 1);

    if (self->text != 0) {
        ((TextObj *)self->text)->Method2();
    }

    FUN_00103128(self);
}
