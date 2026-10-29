/* HSTMATCH module=EBOOT.BIN start=0x00200df0 end=0x00200f48 symbol=FUN_00200df0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00200df0.c (tag: a1) */
#define QUAD_ENTRY_STRIDE 0x14 /* bytes between the two entries of each pane group */
#define QUAD_ENTRY_COUNT 2

/* Pane record: only the two words the update touches. */
typedef struct Pane {
    char pad00[0x24];
    int unk24; /* 0x24 */
    int unk28; /* 0x28 */
} Pane;

#include "hst/quad_config.h"

extern QuadConfig *DAT_0034a13c;
extern void FUN_000ffb3c(Pane *, int);
extern void FUN_0010b8cc(int, int, int);

/* For each of the two entries, shows one pane pair and hides the other depending on whether the entry
   is the current one; the hidden pane of the A/B pair also gets unk24 set from unk28 plus (1 - i). */
void FUN_00200df0(int self)
{
    int current;
    Pane **paneD;
    int i;
    int off;
    Pane **paneA;
    Pane **paneB;
    Pane **paneC;

    current = DAT_0034a13c->unk50;
    FUN_0010b8cc(*(int *)(self + 0x708), current, 2);
    i = 0;
    off = 0;
    do {
        paneA = (Pane **)((int *)(self + (off + 0x550)) + 0xc);
        paneB = (Pane **)((int *)(self + (off + 0x578)) + 0xc);
        paneC = (Pane **)((int *)(self + (off + 0x5a0)) + 0xc);
        paneD = (Pane **)((int *)(self + (off + 0x5c8)) + 0xc);
        if (current == i) {
            FUN_000ffb3c(*paneA, 0);
            (*paneA)->unk24 = (*paneA)->unk28 + (1 - i);
            FUN_000ffb3c(*paneC, 0);
            FUN_000ffb3c(*paneB, 1);
            FUN_000ffb3c(*paneD, 1);
        } else {
            FUN_000ffb3c(*paneA, 1);
            FUN_000ffb3c(*paneC, 1);
            FUN_000ffb3c(*paneB, 0);
            (*paneB)->unk24 = (*paneB)->unk28 + (1 - i);
            FUN_000ffb3c(*paneD, 0);
        }
        i = i + 1;
        off = off + QUAD_ENTRY_STRIDE;
    } while (i < QUAD_ENTRY_COUNT);
}
