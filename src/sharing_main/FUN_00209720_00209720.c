/* HSTMATCH module=hstp_trans_main.prx start=0x00209720 end=0x00209a8c symbol=FUN_00209720 lang=c99 helpers=FUN_001fbc18@0x001fbc18-0x001fbc44 */
/* Clone of src/eboot/FUN_001fb008_001fb008.c (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int *DAT_003e1e48;
extern char DAT_00396db4[];
extern char DAT_00396dc8[];
extern char DAT_00396ddc[];
extern char DAT_00396dec[];

extern void FUN_0023bc78(void);
extern int FUN_000dca08(void *table, int mode);
extern void *FUN_000dca74(void *table, int mode, int index);
extern void *FUN_000114c0(void *dst, int value, int size);
extern void FUN_00209394(void *self, void *names, void *values,
                         int *count_a, int *count_b, int mode,
                         void *entry, int index);

static void FUN_001fbc18(...) { }

void FUN_00209720(void *self)
{
    char names[40] = {0};
    char values[40] = {0};
    int count_a = 0;
    int count_b = 0;
    FUN_0023bc78();

    {
        int row_index;
        int item_index;
        char *row;
        char *item;
        for (row_index = 0, row = (char *)self; row_index < 10;
             row_index++, row += 0xa00) {
            for (item_index = 0, item = row; item_index < 128;
                 item_index++, item += 20) {
                FUN_000114c0(item + 0x136c, 0, 20);
            }
        }
    }

    {
        int item_index;
        char *item;
        for (item_index = 0, item = (char *)self; item_index < 128;
             item_index++, item += 20) {
            FUN_000114c0(item + 0x776c, 0, 20);
        }
    }

    {
        int count = FUN_000dca08(DAT_003e1e48, 1);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000dca74(DAT_003e1e48, 1, item_index);
            if (entry != 0)
                FUN_00209394(self, names, values, &count_a, &count_b, 1, entry, item_index);
        }
    }

    {
        int count = FUN_000dca08(DAT_003e1e48, 2);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000dca74(DAT_003e1e48, 2, item_index);
            if (entry != 0)
                FUN_00209394(self, names, values, &count_a, &count_b, 2, entry, item_index);
        }
    }

    {
        int count = FUN_000dca08(DAT_003e1e48, 3);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000dca74(DAT_003e1e48, 3, item_index);
            if (entry != 0)
                FUN_00209394(self, names, values, &count_a, &count_b, 3, entry, item_index);
        }
    }

    {
        int count = FUN_000dca08(DAT_003e1e48, 5);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000dca74(DAT_003e1e48, 5, item_index);
            if (entry != 0)
                FUN_00209394(self, names, values, &count_a, &count_b, 4, entry, item_index);
        }
    }

    {
        int row_index;
        int item_index;
        char *row;
        char *item;
        row_index = 0;
        row = (char *)self;
        while (row_index < 10) {
            for (item_index = 0, item = row; item_index < 128;
                 item_index++, item += 20) {
                char *record = item + 0x136c;
                if (*(unsigned char *)(item + 0x136c) == 0)
                    continue;
                FUN_001fbc18(DAT_00396db4, row_index, item_index, record);
                FUN_001fbc18(DAT_00396dc8,
                             *(int *)(record + 4), *(int *)(record + 8));
                FUN_001fbc18(DAT_00396ddc,
                             *(int *)(record + 12), *(int *)(record + 16));
            }
            row_index++;
            row += 0xa00;
        }
    }

    {
        int item_index;
        for (item_index = 0; item_index < 128;
             item_index++, self = (char *)self + 20) {
            if (*(unsigned char *)((char *)self + 0x776c) != 0) {
                char *record = (char *)self + 0x776c;
                FUN_001fbc18(DAT_00396dec, item_index);
                FUN_001fbc18(DAT_00396dc8,
                             *(int *)(record + 4), *(int *)(record + 8));
                FUN_001fbc18(DAT_00396ddc,
                             *(int *)(record + 12), *(int *)(record + 16));
            }
        }
    }
}
