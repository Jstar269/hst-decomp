/* HSTMATCH module=EBOOT.BIN start=0x001e2da8 end=0x001e30a8 symbol=FUN_001e2da8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003417b8;
extern int DAT_002c8ad8[];
extern int DAT_002c8b10[];
extern int DAT_002c8b50[];
extern int DAT_002c8ba8[];
extern int DAT_002c8be0[];
extern int DAT_002c8c18[];
extern void FUN_000ffb3c(int, int);

void FUN_001e2da8(char *self, int kind)
{
    unsigned char *flag = &DAT_003417b8;
    unsigned i;
    int *tab;
    int k;
    int *p;
    switch (kind) {
    case 1:
        if (*flag != 1) {
            i = 0;
            tab = DAT_002c8ad8;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002c8b50;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 22);
            i = 0;
            tab = DAT_002c8ba8;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 12 + 0x1398), 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002c8c18;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 12 + 0x1368), 1);
                i++;
                tab++;
            } while (i < 2);
        }
        break;
    case 2:
        if (*flag != 1) {
            i = 0;
            tab = DAT_002c8b10;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 16);
            i = 0;
            tab = DAT_002c8b50;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 22);
            i = 0;
            tab = DAT_002c8be0;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 12 + 0x1398), 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002c8c18;
            do {
                FUN_000ffb3c(*(int *)(self + *tab * 12 + 0x1368), 1);
                i++;
                tab++;
            } while (i < 2);
        }
        break;
    }
    if (*flag == 1) {
        k = 0x75;
        p = (int *)(self + 0x924);
        do {
            FUN_000ffb3c(*(int *)((char *)p + 0x9cc), 1);
            k++;
            p = (int *)((char *)p + 0x14);
        } while (k <= 0x76);
        self = self + 0x94c;
        k = 0x77;
        do {
            FUN_000ffb3c(*(int *)(self + 0x9cc), 0);
            k++;
            self = self + 0x14;
        } while (k <= 0x7a);
    } else {
        k = 0x75;
        p = (int *)(self + 0x924);
        do {
            FUN_000ffb3c(*(int *)((char *)p + 0x9cc), 0);
            k++;
            p = (int *)((char *)p + 0x14);
        } while (k <= 0x76);
        self = self + 0x94c;
        k = 0x77;
        do {
            FUN_000ffb3c(*(int *)(self + 0x9cc), 1);
            k++;
            self = self + 0x14;
        } while (k <= 0x7a);
    }
}
