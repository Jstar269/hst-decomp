/* HSTMATCH module=EBOOT.BIN start=0x00110bfc end=0x00111010 symbol=FUN_00110bfc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/messe_layout.h"

struct GlobalState {
    char pad[0x86bd0];
    int diff_mode;
};

extern "C" {
extern GlobalState *DAT_003415a8;
extern int DAT_003417a4;
extern void FUN_00103128(void *);
extern void FUN_0010d4a8(MessePane *);
}

/* Move a pane to (x, y) and shift the pane's mirrored coordinates by the same deltas. */
static inline void place_pane(MessePane *pane, float x, short y)
{
    short new_x = (short)(int)x;
    short old_x = pane->pos_x;
    pane->pos_x = new_x;
    pane->unk100 += (new_x - old_x);
    short diff_y = y - pane->pos_y;
    pane->pos_y = y;
    pane->unk102 += diff_y;
}

/* Per-frame ticker update: advance the scroll state machine, then position both text panes. */
extern "C" void FUN_00110bfc(MesseLayout *self)
{
    int d = DAT_003415a8->diff_mode; /* picks the scroll speed */
    float step;
    if (d == 2) goto L4;
    if (d == 1) goto L3;
    switch (d) {
    case 0:
        step = 2.0f;
        goto Ldone;
    default:
        goto L3;
    }
L3:
    step = 3.0f;
    goto Ldone;
L4:
    step = 4.0f;
Ldone:

    FUN_00103128(self);

    switch (self->state) {
    case MESSE_WAIT: {
        self->pos0 = 480.0f;
        self->pos1 = self->gap + 480.0f;
        int count = self->timer - 1;
        self->timer = count;
        if (count <= 0) {
            self->timer = 0;
            self->state = MESSE_EASE_IN;
        }
        break;
    }
    case MESSE_EASE_IN: {
        float pos = self->pos0 * 0.5f + 10.0f;
        self->pos0 = pos;
        self->pos1 = pos + self->gap;
        if (self->pos0 < 20.1f) {
            self->pos0 = 20.1f;
            self->timer = 30;
            self->state = MESSE_HOLD;
        }
        break;
    }
    case MESSE_HOLD: {
        int count = self->timer - 1;
        self->timer = count;
        if (count <= 0 && self->width >= 460.0f) {
            self->timer = 0;
            self->state = MESSE_SCROLL;
        }
        break;
    }
    case MESSE_SCROLL:
        self->pos0 -= step;
        self->pos1 -= step;
        break;
    }

    switch (DAT_003417a4) {
    case 9: {
        MessePane *pane = self->text0;
        pane->unk108 = 0.8f;
        pane->unk10c = 0.8f;
        FUN_0010d4a8(pane);
        pane = self->text1;
        pane->unk108 = 0.8f;
        pane->unk10c = 0.8f;
        FUN_0010d4a8(pane);
        place_pane(self->text0, self->pos0, 2);
        place_pane(self->text1, self->pos1, 2);
        break;
    }
    case 10:
        place_pane(self->text0, self->pos0, 0);
        place_pane(self->text1, self->pos1, 0);
        break;
    default:
        place_pane(self->text0, self->pos0, 1);
        place_pane(self->text1, self->pos1, 1);
        break;
    }

    if (self->pos0 + self->width < 0.0f) {
        self->pos0 = self->pos1 + self->gap;
    }
    if (self->pos1 + self->width < 0.0f) {
        self->pos1 = self->pos0 + self->gap;
    }
}
