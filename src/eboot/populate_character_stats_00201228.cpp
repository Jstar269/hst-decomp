/* HSTMATCH module=EBOOT.BIN start=0x00201228 end=0x002014d8 symbol=FUN_00201228 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a5/v18c/FUN_00201228.cpp (tag: a5) */
#include "hst/entry_records.h"
#include "hst/menu_rec.h"
#include "hst/game.h"

/* Virtual object driven by the second loop: virtual method 1 takes a 0/1 mode. */
struct Widget {
    virtual void d0();
    virtual void m(int mode);
    char pad04[0xf8 - 4];
    int unkf8;   /* 0xf8 */
    char padfc[0x138 - 0xfc];
    int unk138;  /* 0x138 */
};

/* The panel holds 0x14-byte table rows from offset 0x30 (a pointer to a Cell each) and 0x0c-byte items from 0x648
   (a Widget pointer at +4 each); both are walked with byte offsets below, as the layout is only partly known. */
#define PANEL_ROWS_OFFSET 0x30
#define PANEL_ROW_SIZE 0x14
#define PANEL_ITEMS_OFFSET 0x648
#define PANEL_ITEM_SIZE 0x0c

/* Iteration counts of the two loops, and the value ranges of the second one. */
enum { FIRST_LOOP_COUNT = 5, SECOND_LOOP_COUNT = 4 };
enum { RANGE_A_END = 0xd, RANGE_B_FIRST = 0xe, RANGE_B_END = 0x1b };

extern "C" {
extern char DAT_002ef198;
extern Game *DAT_0034a13c;
extern int FUN_00014d64(void *, void *);
extern void FUN_000d7d80(void *);
extern void FUN_000d7e30(void *, int);
extern void FUN_000ffb3c(Cell *, int);
extern void FUN_0010d4a8(void *);
extern Rec200 *FUN_00193474(int);
extern int FUN_001fea10(int, int, int);
extern void FUN_002045e8(void *, int, int, int, int, int, int, int, int);
extern int FUN_002181a4(unsigned int, int, void *, int, void *);
extern void FUN_002182a0(int *, unsigned int, int, void *);

void FUN_00201228(int panel, Rec200 *rec, int firstRow, int secondRow, int itemBase)
{
    int useAltKey;
    unsigned int key;
    void *str;
    int i;
    int addr;
    int *cur; /* row slot in the first loop, then walks picks */
    Cell **cellp;
    int delta;
    Rec200 scratch;
    int picks[4];

    addr = DAT_0034a13c->unk4c;
    FUN_000d7d80(&scratch);
    FUN_002045e8(&scratch, rec->ids[0], rec->ids[1], rec->ids[2], rec->ids[3],
                 rec->ids[4], rec->ids[5], rec->pairs[addr].unk0,
                 rec->pairs[addr].unk1);
    key = rec->ids[0];
    useAltKey = 0;
    if (FUN_00014d64(rec->str68, &DAT_002ef198) != 0) {
        useAltKey = 1;
        key = rec->unk20;
        str = rec->str68;
    } else {
        str = FUN_00193474(rec->ids[0])->str68;
    }
    i = 0;
    addr = panel + firstRow * PANEL_ROW_SIZE;
    do {
        delta = FUN_002181a4(key, useAltKey, str, i, &scratch);
        cur = (int *)(addr + PANEL_ROWS_OFFSET);
        i++;
        addr += PANEL_ROW_SIZE;
        ((Cell *)*cur)->unk24 = ((Cell *)*cur)->unk28 + delta;
    } while (i < FIRST_LOOP_COUNT);
    FUN_002182a0(picks, key, useAltKey, str);
    key = 0;
    cur = picks;
    do {
        cellp = (Cell **)(panel + (secondRow + (int)key) * PANEL_ROW_SIZE + PANEL_ROWS_OFFSET);
        addr = panel + (itemBase + (int)key) * PANEL_ITEM_SIZE + PANEL_ITEMS_OFFSET;
        delta = *cur;
        if (delta >= 0 && delta < RANGE_A_END) {
            FUN_000ffb3c(*cellp, 0);
            (*cellp)->unk24 = (*cellp)->unk28;
            ((Widget *)*(int *)(addr + 4))->m(0);
            int itemId = FUN_001fea10(0xb, 3, *cur);
            Widget *widget = (Widget *)*(int *)(addr + 4);
            widget->unkf8 = itemId;
            widget->unk138 = 1;
            FUN_0010d4a8(widget);
        } else if (delta >= RANGE_B_FIRST && delta < RANGE_B_END) {
            FUN_000ffb3c(*cellp, 0);
            (*cellp)->unk24 = (*cellp)->unk28 + 1;
            ((Widget *)*(int *)(addr + 4))->m(0);
            int itemId = FUN_001fea10(0xb, 3, *cur - RANGE_B_FIRST);
            Widget *widget = (Widget *)*(int *)(addr + 4);
            widget->unkf8 = itemId;
            widget->unk138 = 1;
            FUN_0010d4a8(widget);
        } else {
            FUN_000ffb3c(*cellp, 1);
            ((Widget *)*(int *)(addr + 4))->m(1);
        }
        key++;
        cur++;
    } while ((int)key < SECOND_LOOP_COUNT);
    FUN_000d7e30(&scratch, -1);
}
}
