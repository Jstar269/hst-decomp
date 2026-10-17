/* HSTMATCH module=EBOOT.BIN start=0x00283660 end=0x00283874 symbol=FUN_00283660 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: recovered loop order and slot initialization branches; exact match verified; names and types await human review. */

typedef unsigned char uchar;
typedef unsigned int uint;

extern char * DAT_00338ac4;
extern char * DAT_003415a8;
extern void FUN_000133f4(uint);
extern uint FUN_0001342c(void);
extern void * FUN_0008d0cc(void *, void *);
extern void * FUN_0008d0e4(void *, void *);
extern void FUN_0008d114(void *);
extern void FUN_0008d2ec(void *);
extern int FUN_000bd378(void *, void *, int);
extern int FUN_000bd480(void *, int, void *, int);
extern uint FUN_002b78f8(void);

void FUN_00283660(char *param_1)
{
    int i = 0;
    int off = 0;
    char *p = param_1;

    do {
        if ((*(uchar *)(DAT_00338ac4 + off + 0x5e) != 0) && (*(uchar *)(p + 0xa6d) == 0)) {
            if (i == *(int *)(DAT_00338ac4 + 0x198)) {
                if ((uchar)FUN_000bd378(DAT_00338ac4, p + 0x940, 0x458)) {
                    uint k = 0;
                    char *q = p;
                    do {
                        k++;
                        *(int *)(q + 0x940) = -1;
                        q += 4;
                    } while (k < 4);
                    *(int *)(p + 0x950) = -1;
                    *(uchar *)(p + 0x954) = 0;
                    FUN_0008d114(p + 0x958);
                    FUN_0008d2ec(p + 0x980);
                    *(uchar *)(p + 0xa4c) = 0;
                    FUN_0008d2ec(p + 0xaa0);
                    FUN_0008d2ec(p + 0xbc0);
                    *(uchar *)(p + 0xb6c) = 0;
                    *(uchar *)(p + 0xc8c) = 0;
                    FUN_0008d0e4(p + 0xa88, DAT_003415a8 + 4);
                    FUN_0008d0cc(p + 0xa98, DAT_003415a8 + 0x18);
                    *(uchar *)(p + 0xa6d) = 1;
                    FUN_000133f4(FUN_002b78f8());
                    *(uint *)(p + 0xa84) = FUN_0001342c();
                    *(uchar *)(param_1 + 0x615) = 1;
                    FUN_000133f4(FUN_002b78f8());
                    *(uint *)(param_1 + 0x62c) = FUN_0001342c();
                }
            } else {
                if ((uchar)FUN_000bd480(DAT_00338ac4, i, p + 0x940, 0x458)) {
                    uint k = 0;
                    char *q = p;
                    do {
                        k++;
                        *(int *)(q + 0x940) = -1;
                        q += 4;
                    } while (k < 4);
                    *(int *)(p + 0x950) = -1;
                    *(uchar *)(p + 0x954) = 0;
                    FUN_0008d114(p + 0x958);
                    FUN_0008d2ec(p + 0x980);
                    *(uchar *)(p + 0xa4c) = 0;
                    FUN_0008d2ec(p + 0xaa0);
                    FUN_0008d2ec(p + 0xbc0);
                    *(uchar *)(p + 0xb6c) = 0;
                    *(uchar *)(p + 0xc8c) = 0;
                    FUN_0008d0e4(p + 0xa88, DAT_003415a8 + 4);
                    FUN_0008d0cc(p + 0xa98, DAT_003415a8 + 0x18);
                    *(uchar *)(p + 0xa6d) = 1;
                    FUN_000133f4(FUN_002b78f8());
                    *(uint *)(p + 0xa84) = FUN_0001342c();
                }
            }
        }
        i++;
        off += 7;
        p += 0x458;
    } while (i < 4);
}
