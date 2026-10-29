/* HSTMATCH module=EBOOT.BIN start=0x0021e2d4 end=0x0021e4cc symbol=FUN_0021e2d4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0c/FUN_0021e2d4.c (tag: a1) */
#include "hst/digit_panel.h"

/* Glyph table: ints, DIGIT_TABLE_STRIDE per row; the tens and ones digit bases are at these indices. */
enum { DIGIT_TABLE_TENS = 2, DIGIT_TABLE_ONES = 5, DIGIT_TABLE_STRIDE = 0x12 };

/* Word index of LayerGroup.layer[0], used while walking the group as an int array. */
enum { GROUP_LAYER_WORD = 0x1c };

extern "C" {
extern int DAT_002f0694[];
extern void FUN_000ffb3c(PaneItem *, int);

/* Select layer `cursor` (show it, hide the others) and refresh that layer's two digits from `value`. */
void FUN_0021e2d4(DigitPanel *self, int cursor)
{
    DigitPanel *layer_base; /* advanced one layer slot (4 bytes) per pass */
    int i;
    int row;
    int j;
    DigitPanel *row_base; /* advanced one DigitRow per pass */
    int *table;
    int dec;

    self->cursor = cursor;
    LayerGroup *group = self->group;
    group->cur = cursor;
    j = 0;
    table = (int *)group;
    do {
        ((PosLayer *)table[GROUP_LAYER_WORD])->set_hidden(1);
        j++;
        table++;
    } while (j < DIGIT_PANEL_ROWS);
    group->layer[group->cur]->set_hidden(0);
    i = 0;
    layer_base = self;
    do {
        layer_base->layer[0]->set_hidden(i != self->cursor);
        if (i == self->cursor) {
            dec = self->value - 1;
            if (dec != -1) {
                self->value = dec + 1;
            }
            row = 0;
            row_base = self;
            table = DAT_002f0694;
            do {
                if (dec == -1) {
                    FUN_000ffb3c(row_base->row[0].tens, 1);
                    int v = 10 + table[DIGIT_TABLE_ONES];
                    PaneItem *w = row_base->row[0].ones;
                    w->unk24 = v;
                    w->unk28 = v;
                } else {
                    int hide = self->value < 10;
                    if (hide == 0) {
                        hide = row != self->cursor;
                    }
                    FUN_000ffb3c(row_base->row[0].tens, hide);
                    int v = self->value / 10 + table[DIGIT_TABLE_TENS];
                    PaneItem *w = row_base->row[0].tens;
                    w->unk24 = v;
                    w->unk28 = v;
                    v = self->value % 10 + table[DIGIT_TABLE_ONES];
                    w = row_base->row[0].ones;
                    w->unk24 = v;
                    w->unk28 = v;
                }
                row++;
                row_base = (DigitPanel *)((char *)row_base + sizeof(DigitRow));
                table += DIGIT_TABLE_STRIDE;
            } while (row < DIGIT_PANEL_ROWS);
        }
        i++;
        layer_base = (DigitPanel *)((char *)layer_base + 4);
    } while (i < DIGIT_PANEL_ROWS);
    self->unk1d4 = (self->cursor == 2) ? 84.0f : 95.0f;
}
}
