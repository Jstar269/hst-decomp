/* HSTMATCH module=EBOOT.BIN start=0x001fb008 end=0x001fb374 symbol=FUN_001fb008 lang=c99 helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_panel.h"

extern int *DAT_00338b08; /* table of entry lists, indexed by kind */
extern char DAT_002eed78[];
extern char DAT_002eed8c[];
extern char DAT_002eeda0[];
extern char DAT_002eedb0[];

extern void FUN_0022c1c4(void);
extern int FUN_000d8bfc(void *table, int mode);
extern void *FUN_000d8c24(void *table, int mode, int index);

enum { SCRATCH_SIZE = 40 };
extern void *FUN_000114c0(void *dst, int value, int size);
extern void FUN_001fac7c(void *panel, void *names, void *values,
                         int *count_a, int *count_b, int mode,
                         void *entry, int index);

static void FUN_001ef3f8(...) { } /* empty debug-print stub */

/* Rebuilds the panel's entry tables: clears every row entry and the extra list, lets FUN_001fac7c fill
   them from the four entry kinds (1, 2, 3 and 5, handed on as mode 1..4), then logs the non-empty entries. */
void FUN_001fb008(void *panel)
{
    char names[SCRATCH_SIZE] = {0};
    char values[SCRATCH_SIZE] = {0};
    int count_a = 0;
    int count_b = 0;
    FUN_0022c1c4();

    {
        int row_index;
        int item_index;
        char *row;
        char *item;
        for (row_index = 0, row = (char *)panel; row_index < PANEL_ROWS;
             row_index++, row += PANEL_ROW_SIZE) {
            for (item_index = 0, item = row; item_index < PANEL_ROW_ENTRIES;
                 item_index++, item += PANEL_ENTRY_SIZE) {
                FUN_000114c0(item + PANEL_ROWS_OFFSET, 0, PANEL_ENTRY_SIZE);
            }
        }
    }

    {
        int item_index;
        char *item;
        for (item_index = 0, item = (char *)panel; item_index < PANEL_ROW_ENTRIES;
             item_index++, item += PANEL_ENTRY_SIZE) {
            FUN_000114c0(item + PANEL_LIST_OFFSET, 0, PANEL_ENTRY_SIZE);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 1);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 1, item_index);
            if (entry != 0)
                FUN_001fac7c(panel, names, values, &count_a, &count_b, 1, entry, item_index);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 2);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 2, item_index);
            if (entry != 0)
                FUN_001fac7c(panel, names, values, &count_a, &count_b, 2, entry, item_index);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 3);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 3, item_index);
            if (entry != 0)
                FUN_001fac7c(panel, names, values, &count_a, &count_b, 3, entry, item_index);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 5);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 5, item_index);
            if (entry != 0)
                FUN_001fac7c(panel, names, values, &count_a, &count_b, 4, entry, item_index);
        }
    }

    {
        int row_index;
        int item_index;
        char *row;
        char *item;
        row_index = 0;
        row = (char *)panel;
        while (row_index < PANEL_ROWS) {
            for (item_index = 0, item = row; item_index < PANEL_ROW_ENTRIES;
                 item_index++, item += PANEL_ENTRY_SIZE) {
                PanelEntry *record = (PanelEntry *)(item + PANEL_ROWS_OFFSET);
                if (record->active == 0)
                    continue;
                FUN_001ef3f8(DAT_002eed78, row_index, item_index, record);
                FUN_001ef3f8(DAT_002eed8c, record->unk04, record->unk08);
                FUN_001ef3f8(DAT_002eeda0, record->unk0c, record->unk10);
            }
            row_index++;
            row += PANEL_ROW_SIZE;
        }
    }

    {
        int item_index;
        for (item_index = 0; item_index < PANEL_ROW_ENTRIES;
             item_index++, panel = (char *)panel + PANEL_ENTRY_SIZE) {
            if (*(unsigned char *)((char *)panel + PANEL_LIST_OFFSET) != 0) {
                PanelEntry *record = (PanelEntry *)((char *)panel + PANEL_LIST_OFFSET);
                FUN_001ef3f8(DAT_002eedb0, item_index);
                FUN_001ef3f8(DAT_002eed8c, record->unk04, record->unk08);
                FUN_001ef3f8(DAT_002eeda0, record->unk0c, record->unk10);
            }
        }
    }
}
