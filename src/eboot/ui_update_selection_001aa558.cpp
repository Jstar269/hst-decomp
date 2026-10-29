/* HSTMATCH module=EBOOT.BIN start=0x001aa558 end=0x001aa770 symbol=FUN_001aa558 lang=c++ */
/* Hand-written reconstruction from the disassembly (sibling of ui_state_enter_001aa450.cpp and update_slots_001aa770.cpp); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

#include "hst/slot_select.h"
#include "hst/selection_panel.h"

/* Per-choice record: a frame offset and two counts (the row of marks shown for each). */
struct ChoiceInfo {
    char pad[10];
    short frame_offset;  /* 0x0a */
    short count_a;       /* 0x0c marks shown in row A */
    short count_b;       /* 0x0e marks shown in row B */
};

enum {
    MARK_COUNT = 5,          /* marks per row */
    MARKS_A_FIRST_ITEM = 11, /* items[] index of the first mark in row A */
    MARKS_B_FIRST_ITEM = 16, /* items[] index of the first mark in row B */
    FRAME_ITEM = 21,         /* item whose sprite frame follows the selection */
    ARROW_ITEM_LEFT = 9,
    ARROW_ITEM_RIGHT = 10
};

extern "C" {
extern int DAT_002e20a0;
extern int DAT_002e20a4;
extern void *DAT_0034a7ec;
extern void FUN_000ffb3c(void *, int);
extern SlotSelect *FUN_0019d474();
extern int FUN_001a49dc(SlotSelect *, int);
extern int FUN_001a4b74(SlotSelect *, int);
extern ChoiceInfo *FUN_0027edbc(void *, int);
}

inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

/* Refreshes the panel for the current choice: highlights the row, shows the marks, sets the frame. */
extern "C" void FUN_001aa558(SelectionPanel *self)
{
    SlotSelect *state = FUN_0019d474();
    int choice = FUN_001a49dc(FUN_0019d474(), state->cursor.index);
    int sel = Clamp(choice - 1, DAT_002e20a0, DAT_002e20a4);

    ChoiceInfo *info = FUN_0027edbc(DAT_0034a7ec, choice);
    int count_a = info->count_a;
    int count_b = info->count_b;
    int frame_offset = info->frame_offset;

    SelList *l = self->list;
    int i = 0;
    if (l->count > 0) {
        do {
            FUN_000ffb3c(l->data[i], i != sel);
            i++;
        } while (i < l->count);
    }

    for (int j = 0, offset = 0; j < MARK_COUNT; ++j, offset += 20) {
        char *row = (char *)self + (offset + 300);
        EntryItem *item = (EntryItem *)(row + 32);
        if (j < count_a) {
            FUN_000ffb3c(item->spr, 0);
        } else {
            FUN_000ffb3c(item->spr, 1);
        }
    }

    for (int k = 0, offset = 0; k < MARK_COUNT; ++k, offset += 20) {
        char *row = (char *)self + (offset + 400);
        EntryItem *item = (EntryItem *)(row + 32);
        if (k < count_b) {
            FUN_000ffb3c(item->spr, 0);
        } else {
            FUN_000ffb3c(item->spr, 1);
        }
    }

    EntryItem *frame_item = &self->items[FRAME_ITEM];
    FUN_000ffb3c(frame_item->spr, 0);
    EntrySprite *frame_spr = frame_item->spr;
    EntryItem *left = &self->items[ARROW_ITEM_LEFT];
    int sum = frame_spr->baseFrame + frame_offset;
    EntryItem *right = &self->items[ARROW_ITEM_RIGHT];
    frame_spr->frame = sum;
    if (FUN_001a4b74(FUN_0019d474(), 2)) {
        FUN_000ffb3c(left->spr, 0);
        FUN_000ffb3c(right->spr, 0);
    } else {
        FUN_000ffb3c(left->spr, 1);
        FUN_000ffb3c(right->spr, 1);
    }
}
