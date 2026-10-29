/* HSTMATCH module=EBOOT.BIN start=0x001e0ab0 end=0x001e0ba0 symbol=FUN_001e0ab0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001e0ab0.c (tag: a1) */
#include "hst/result_scene.h"
#include "hst/adhoc_net.h"

/* The two parts as far as this function sees them. */
typedef struct PartAt40 {
    char pad00[0x54];
    int unk54;      /* 0x54 */
} PartAt40;
typedef struct PartAt3c {
    char pad00[0x8c];
    int unk8c;      /* 0x8c */
} PartAt3c;

struct Arr6 {
    int v[6];
};
extern struct Arr6 DAT_002ebb1c;
extern AdhocNet *DAT_00338ac4;
extern void FUN_001eaad8(int, int, int);

/* Store the pair index in the part at 0x40, then pass the matching table entries (index and 5 - index) on,
   paired with the parity of a counter. */
void FUN_001e0ab0(ResultScene *self, int index)
{
    int count;
    int parity;
    struct Arr6 table;

    ((PartAt40 *)self->part40)->unk54 = index;
    table = DAT_002ebb1c;
    if (DAT_00338ac4 != 0) {
        count = DAT_00338ac4->unk198;
    } else {
        count = 0;
    }
    parity = count % 2;
    FUN_001eaad8(((PartAt3c *)self->part3c)->unk8c, parity, table.v[index]);
    FUN_001eaad8(((PartAt3c *)self->part3c)->unk8c, parity ^ 1, table.v[5 - index]);
}
