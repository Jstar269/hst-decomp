/* HSTMATCH module=EBOOT.BIN start=0x001e2da8 end=0x001e30a8 symbol=FUN_001e2da8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/result_screen.h"

extern unsigned char DAT_003417b8;
extern int DAT_002c8ad8[];
extern int DAT_002c8b10[];
extern int DAT_002c8b50[];
extern int DAT_002c8ba8[];
extern int DAT_002c8be0[];
extern int DAT_002c8c18[];
extern void FUN_000ffb3c(void *, int);

/* self is walked in bytes by the loops at the end, so the table loops cast it. */
#define SCREEN(p) ((ResultScreen *)(p))

/* Row ranges toggled by the flag: rows 0x75-0x76 and rows 0x77-0x7a get opposite values. */
enum { ROW_FIRST_A = 0x75, ROW_LAST_A = 0x76, ROW_FIRST_B = 0x77, ROW_LAST_B = 0x7a };

/* Show or hide the screen's widgets for the given kind, using the id tables below. */
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
                FUN_000ffb3c(SCREEN(self)->row[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002c8b50;
            do {
                FUN_000ffb3c(SCREEN(self)->row[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 22);
            i = 0;
            tab = DAT_002c8ba8;
            do {
                FUN_000ffb3c(SCREEN(self)->cellB[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002c8c18;
            do {
                FUN_000ffb3c(SCREEN(self)->cellA[*tab].widget, 1);
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
                FUN_000ffb3c(SCREEN(self)->row[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 16);
            i = 0;
            tab = DAT_002c8b50;
            do {
                FUN_000ffb3c(SCREEN(self)->row[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 22);
            i = 0;
            tab = DAT_002c8be0;
            do {
                FUN_000ffb3c(SCREEN(self)->cellB[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 14);
            i = 0;
            tab = DAT_002c8c18;
            do {
                FUN_000ffb3c(SCREEN(self)->cellA[*tab].widget, 1);
                i++;
                tab++;
            } while (i < 2);
        }
        break;
    }
    if (*flag == 1) {
        k = ROW_FIRST_A;
        p = (int *)(self + 0x924);
        do {
            FUN_000ffb3c(*(void **)((char *)p + 0x9cc), 1);
            k++;
            p = (int *)((char *)p + 0x14);
        } while (k <= ROW_LAST_A);
        self = self + 0x94c;
        k = ROW_FIRST_B;
        do {
            FUN_000ffb3c(*(void **)(self + 0x9cc), 0);
            k++;
            self = self + 0x14;
        } while (k <= ROW_LAST_B);
    } else {
        k = ROW_FIRST_A;
        p = (int *)(self + 0x924);
        do {
            FUN_000ffb3c(*(void **)((char *)p + 0x9cc), 0);
            k++;
            p = (int *)((char *)p + 0x14);
        } while (k <= ROW_LAST_A);
        self = self + 0x94c;
        k = ROW_FIRST_B;
        do {
            FUN_000ffb3c(*(void **)(self + 0x9cc), 1);
            k++;
            self = self + 0x14;
        } while (k <= ROW_LAST_B);
    }
}
