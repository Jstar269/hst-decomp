/* HSTMATCH module=EBOOT.BIN start=0x00186378 end=0x0018659c symbol=FUN_00186378 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: 3-way mode switch with case-scoped loop induction variables, Table5 struct copy, pragma opt_strength_reduction off for indexed access; readability pass; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

#include "hst/types.h"
#include "hst/slide_screen.h"

typedef struct {
    int v[5];
} Table5;

extern Table5 DAT_002e0988;
extern void FUN_000ffb3c(u32, int);
extern int FUN_0016bc70(void);

/* Shows or hides groups of slot widgets according to the per-category counts of the current mode (1: one slot each, 2: two, 3: three). */
void FUN_00186378(SlideScreen *self)
{
    int *counts = (int *)(FUN_0016bc70() + 0x588);
    Table5 order = DAT_002e0988;  /* category index of each of the five columns */

    switch (*(int *)(FUN_0016bc70() + 0x584)) {  /* current mode */
    case 1: {
        int i;
        int off;
        const int *cat;

        i = 0;
        off = 0;
        cat = order.v;
        for (; i < 5; i++, off += 20, cat++) {
            int off1 = off + 1420;  /* 20 * (71 + i): slot table index, base added below */
            char *p = (char *)self + off1;
            u32 *handle = (u32 *)(p + 8052);
            if (counts[*cat] > 0) {
                FUN_000ffb3c(*handle, 0);
            } else {
                FUN_000ffb3c(*handle, 1);
            }
        }
        break;
    }
    case 2: {
        int i;
        int j;
        const int *cat;
        int idx;

        i = 0;
        cat = order.v;
        for (; i < 5; i++, cat++) {
            j = 0;
            idx = i + 78;
            for (; j < 2; j++, idx += 5) {
                u32 *handle = &self->slots[idx].handle;
                if (counts[*cat] >= j + 1) {
                    FUN_000ffb3c(*handle, 0);
                } else {
                    FUN_000ffb3c(*handle, 1);
                }
            }
        }
        break;
    }
    case 3: {
        int i;
        int j;
        const int *cat;
        int idx;

        i = 0;
        cat = order.v;
        for (; i < 5; i++, cat++) {
            j = 0;
            idx = i + 91;
            for (; j < 3; j++, idx += 5) {
                u32 *handle = &self->slots[idx].handle;
                if (counts[*cat] >= j + 1) {
                    FUN_000ffb3c(*handle, 0);
                } else {
                    FUN_000ffb3c(*handle, 1);
                }
            }
        }
        break;
    }
    }
}
