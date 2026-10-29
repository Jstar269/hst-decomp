/* HSTMATCH module=EBOOT.BIN start=0x0010b06c end=0x0010b150 symbol=FUN_0010b06c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mode_list.h"

#define COPY_COUNT 3 /* number of record copies registered */
#define COPY_ID_BASE 0x2c /* id given to the first copy; later copies count up */

/* Item description record (36 bytes). */
struct ItemSpec {
    int unk00;
    int unk04;
    int unk08;
    int id;             /* 0x0c */
    short unk10;
    short unk12;
    short unk14;
    short unk16;
    short unk18;
    short pad1a;
    int unk1c;
    int unk20;
};
extern void FUN_00101630(ModeList *, struct ItemSpec *, int);
extern void FUN_000ffca4(ModeItem *);
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off

/* Register COPY_COUNT copies of `spec` (numbered ids), then refresh every item. */
void FUN_0010b06c(ModeList *self, struct ItemSpec *spec)
{
    struct ItemSpec copies[COPY_COUNT];
    unsigned int i;
    struct ItemSpec *dst;
    int j;

    for (i = 0, dst = copies; i < COPY_COUNT; i++, dst++) {
        dst->unk00 = spec->unk00;
        dst->unk04 = spec->unk04;
        dst->unk08 = spec->unk08;
        dst->id = spec->id;
        dst->unk10 = spec->unk10;
        dst->unk12 = spec->unk12;
        dst->unk14 = spec->unk14;
        dst->unk16 = spec->unk16;
        dst->unk18 = spec->unk18;
        dst->unk1c = spec->unk1c;
        dst->unk20 = spec->unk20;
        dst->id = i + COPY_ID_BASE;
    }
    FUN_00101630(self, copies, COPY_COUNT);
    for (j = 0; j < self->item_count; j++)
        FUN_000ffca4(self->items[j]);
}
// Matching notes (lane fm6, unreviewed): the
// explicit `dst` pointer (with `opt_strength_reduction off`) is what reproduces retail's pointer
// induction (`addiu a2,sp,20` before the loop, `addiu a2,a2,36` in the `bnez` delay) AND the second
// loop's per-iteration `sll`; with strength reduction ON the first loop comes out right by itself
// (induction in a2) but the second loop becomes a byte-offset induction in s2 and costs two words.
// Ruled out: index form with the pragma off (no induction, 60 words), index form with it on (59,
// s2 frame), defining dst before i, `dst++, i++` order, incrementing i inside the body, and a
// `while` for the second loop.
