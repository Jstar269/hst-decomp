/* HSTMATCH module=EBOOT.BIN start=0x001fb008 end=0x001fb374 symbol=FUN_001fb008 lang=c99 helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int *DAT_00338b08;
extern char DAT_002eed78[];
extern char DAT_002eed8c[];
extern char DAT_002eeda0[];
extern char DAT_002eedb0[];

extern void FUN_0022c1c4(void);
extern int FUN_000d8bfc(void *table, int mode);
extern void *FUN_000d8c24(void *table, int mode, int index);
extern void *FUN_000114c0(void *dst, int value, int size);
extern void FUN_001fac7c(void *self, void *names, void *values,
                         int *count_a, int *count_b, int mode,
                         void *entry, int index);

static void FUN_001ef3f8(...) { }

void FUN_001fb008(void *self)
{
    char names[40] = {0};
    char values[40] = {0};
    int count_a = 0;
    int count_b = 0;
    FUN_0022c1c4();

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
        int count = FUN_000d8bfc(DAT_00338b08, 1);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 1, item_index);
            if (entry != 0)
                FUN_001fac7c(self, names, values, &count_a, &count_b, 1, entry, item_index);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 2);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 2, item_index);
            if (entry != 0)
                FUN_001fac7c(self, names, values, &count_a, &count_b, 2, entry, item_index);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 3);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 3, item_index);
            if (entry != 0)
                FUN_001fac7c(self, names, values, &count_a, &count_b, 3, entry, item_index);
        }
    }

    {
        int count = FUN_000d8bfc(DAT_00338b08, 5);
        int item_index;
        for (item_index = 0; item_index < count; item_index++) {
            void *entry = FUN_000d8c24(DAT_00338b08, 5, item_index);
            if (entry != 0)
                FUN_001fac7c(self, names, values, &count_a, &count_b, 4, entry, item_index);
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
                FUN_001ef3f8(DAT_002eed78, row_index, item_index, record);
                FUN_001ef3f8(DAT_002eed8c,
                             *(int *)(record + 4), *(int *)(record + 8));
                FUN_001ef3f8(DAT_002eeda0,
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
                FUN_001ef3f8(DAT_002eedb0, item_index);
                FUN_001ef3f8(DAT_002eed8c,
                             *(int *)(record + 4), *(int *)(record + 8));
                FUN_001ef3f8(DAT_002eeda0,
                             *(int *)(record + 12), *(int *)(record + 16));
            }
        }
    }
}
