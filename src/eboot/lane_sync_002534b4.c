/* HSTMATCH module=EBOOT.BIN start=0x002534b4 end=0x002535e0 symbol=FUN_002534b4 lang=c99 */
/* Hand-written reconstruction from the disassembly (restructured from a near-miss wip draft); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"
#include "hst/info_rec.h"

/* Widget array and its length at 0x10 / 0x14. */
typedef struct WidgetList {
    char pad0[0x10];
    void **widgets;             /* 0x10 */
    int count;                  /* 0x14 */
} WidgetList;

#define LANE_SLOTS 5

typedef struct LaneSync {
    WidgetList *tabs;           /* 0x00 one widget per record id, hidden unless it is the selected record's */
    PaneItem *item;             /* 0x04 item whose range follows the selection */
    int base;                   /* 0x08 */
    void *rowA[LANE_SLOTS];     /* 0x0c slot widgets of the first row */
    void *rowB[LANE_SLOTS];     /* 0x20 slot widgets of the second row */
    char pad34[8];
    int record[1];              /* 0x3c record id of each lane */
} LaneSync;

extern void *DAT_0034a7ec;
extern InfoRec *FUN_0027edbc(void *, int);
extern void FUN_000ffb3c(void *, int);

/* Shows only the selected record's tab widget, moves the item range to base + the record's first value and lights the slots
   of both rows up to the record's counts. */
void FUN_002534b4(LaneSync *self, int lane)
{
    int record = self->record[lane];
    InfoRec *info = FUN_0027edbc(DAT_0034a7ec, record);
    int a = 0;
    int b = 0;
    int c = 0;
    WidgetList *g;
    PaneItem *t;
    int i;
    unsigned j;
    int sum;

    if (info != 0) {
        a = info->unkA;
        b = info->slotsA;
        c = info->slotsB;
    }
    g = self->tabs;
    /* matching idiom: the unsigned index keeps MWCC from strength-reducing this loop (retail recomputes the offset) */
    for (i = 0; i < g->count; i++)
        FUN_000ffb3c(g->widgets[(unsigned)i], i != record - 1);
    sum = self->base + a;
    t = self->item;
    t->unk24 = sum;
    t->unk28 = sum;
    for (j = 0; j < LANE_SLOTS; j++)
        FUN_000ffb3c(self->rowA[j], (int)j >= b);
    for (j = 0; j < LANE_SLOTS; j++)
        FUN_000ffb3c(self->rowB[j], (int)j >= c);
}
