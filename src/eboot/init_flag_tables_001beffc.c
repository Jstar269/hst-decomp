/* HSTMATCH module=EBOOT.BIN start=0x001beffc end=0x001bf1cc symbol=FUN_001beffc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: raw offsets replaced by a typed object (byte tables at +0xfcc, +0xfe1, +0x1025, five-byte cells at +0x3444), the dropped extra arguments of FUN_001be968 and FUN_001bebb0 restored; readability pass; exact match verified; names and types await human review. */
/* Matching idioms: the five-byte cell loop uses its own counter j (a shared i swaps s3/s4) and tests `enable` twice (kind, then the four flags), as retail does. */
#include "hst/flag_tables.h"

#define FLAG_SET 4 /* value stored in an enabled flag_a / flag_b / cell kind byte */

extern int DAT_0034a7ec;
extern void FUN_000114c0(void *, int, int);
extern void FUN_001bc7e0(void *, int);
extern void FUN_001be728();
extern void FUN_001be968();
extern void FUN_001bebb0();
extern void FUN_001bec74();
extern void FUN_001bed48();
extern void FUN_001bee20();
extern void FUN_001bef18();

/* State record found by index; negative state means unusable, 1 is set directly. */
struct Slot {
    char pad[4];
    short state;
};
struct Ent {
    char pad[0x7c];
    unsigned char unk7c;
};
extern struct Slot *FUN_0027edbc(int, int);
extern struct Ent *FUN_00193474(int);

/* Reset every table of the object: run the sub-initialisers, then rebuild the flag arrays and cells (all on when `enable`). */
void FUN_001beffc(FlagTables *self, int enable)
{
    int i;
    FUN_001be728(self, enable);
    FUN_001be968(self, enable, enable, enable);
    FUN_001bebb0(self, enable, enable);
    FUN_001bec74(self, enable);
    FUN_001bed48(self, enable);
    FUN_001bee20(self, enable);
    for (i = 0; i < FLAG_A_COUNT; i++) {
        struct Slot *e;
        self->flag_a[i] = 0;
        e = FUN_0027edbc(DAT_0034a7ec, i);
        if (e != 0 && e->state >= 0) {
            if (enable != 0)
                self->flag_a[i] = FLAG_SET;
            else if (e->state == 1)
                self->flag_a[i] = FLAG_SET;
        }
    }
    for (i = 0; i < FLAG_B_COUNT; i++) {
        self->flag_b[i] = 0;
        if (enable != 0)
            self->flag_b[i] = FLAG_SET;
        else if (i == 0)
            self->flag_b[i] = FLAG_SET;
    }
    FUN_001bc7e0(self->sub_block, enable);
    {
        int j;
        for (j = 0; j < CELL_COUNT; j++) {
            FlagCell *cell = &self->cells[j];
            cell->kind = 0;
            FUN_000114c0(cell->flags, 0, CELL_FLAG_COUNT);
            if (enable != 0)
                cell->kind = FLAG_SET;
            if (enable != 0) {
                cell->flags[0] = 1;
                cell->flags[1] = 1;
                cell->flags[2] = 1;
                cell->flags[3] = 1;
            }
        }
    }
    FUN_001bef18(self, enable);
    for (i = 0; i < FLAG_C_COUNT; i++)
        self->flag_c[i] = FUN_00193474(i)->unk7c;
}
