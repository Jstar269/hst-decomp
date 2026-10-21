/* HSTMATCH module=hstp_trans_main.prx start=0x001f0ffc end=0x001f12fc symbol=FUN_001f0ffc lang=c99 */
/* Clone of src/eboot/table_loops_001e2da8.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003eaaf0;
extern int DAT_002d8f18[];
extern int DAT_002d8f50[];
extern int DAT_002d8f90[];
extern int DAT_002d8fe8[];
extern int DAT_002d9020[];
extern int DAT_002d9058[];
extern void FUN_00105470(int, int);

void FUN_001f0ffc(char *self, int kind)
{
    unsigned char *flag = &DAT_003eaaf0;
    unsigned i;
    int *tab;
    int k;
    int *p;
    switch (kind) {
    case 1:
        if (*flag != 1) {
            i = 0;
            tab = DAT_002d8f18;
            do {
                FUN_00105470(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002d8f90;
            do {
                FUN_00105470(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 22);
            i = 0;
            tab = DAT_002d8fe8;
            do {
                FUN_00105470(*(int *)(self + *tab * 12 + 0x1398), 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002d9058;
            do {
                FUN_00105470(*(int *)(self + *tab * 12 + 0x1368), 1);
                i++;
                tab++;
            } while (i < 2);
        }
        break;
    case 2:
        if (*flag != 1) {
            i = 0;
            tab = DAT_002d8f50;
            do {
                FUN_00105470(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 16);
            i = 0;
            tab = DAT_002d8f90;
            do {
                FUN_00105470(*(int *)(self + *tab * 0x14 + 0x9cc), 1);
                i++;
                tab++;
            } while (i < 22);
            i = 0;
            tab = DAT_002d9020;
            do {
                FUN_00105470(*(int *)(self + *tab * 12 + 0x1398), 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002d9058;
            do {
                FUN_00105470(*(int *)(self + *tab * 12 + 0x1368), 1);
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
            FUN_00105470(*(int *)((char *)p + 0x9cc), 1);
            k++;
            p = (int *)((char *)p + 0x14);
        } while (k <= 0x76);
        self = self + 0x94c;
        k = 0x77;
        do {
            FUN_00105470(*(int *)(self + 0x9cc), 0);
            k++;
            self = self + 0x14;
        } while (k <= 0x7a);
    } else {
        k = 0x75;
        p = (int *)(self + 0x924);
        do {
            FUN_00105470(*(int *)((char *)p + 0x9cc), 0);
            k++;
            p = (int *)((char *)p + 0x14);
        } while (k <= 0x76);
        self = self + 0x94c;
        k = 0x77;
        do {
            FUN_00105470(*(int *)(self + 0x9cc), 1);
            k++;
            self = self + 0x14;
        } while (k <= 0x7a);
    }
}
