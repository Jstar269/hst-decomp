/* HSTMATCH module=EBOOT.BIN start=0x00132180 end=0x00132390 symbol=FUN_00132180 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: both lists are cleared through local pointers (`l1 = &c->list13fc; l1->data = 0; ...`), and MWCC reuses l1's address computation for the later grow argument `&c->list13fc`, which puts retail's `addiu a0,s0,5116` into the capacity test's beqz delay slot (clearing the members directly computes it at the call and turns the test into beqzl: 46 words off); exact match verified; names and types await human review. */
/* Court.cpp (file name and the g_pCourt name from the assert strings of the debug-build twin): constructor of the court
   object (two polymorphic bases: FUN_0001f06c at +0, FUN_0013fb58 at +0x40, vtables DAT_0030820c / DAT_00308228),
   registers itself as g_pCourt, reserves 16 entries in both lists. Release build of src/sharing_main/court_ctor_0013d738.c
   (same source; the g_pCourt assertion compiles away here). */
#define HST_ASSERT(cond) do { } while (0)

typedef struct List {
    void *data;
    int size;
    unsigned int capacity;
} List;

typedef struct Court {
    void *vptr;                 /* 0x0000 */
    char base0[0x3c];
    void *vptr1;                /* 0x0040: second base */
    char base1[0x1360 - 0x44];
    int m1360;
    int mode;                   /* 0x1364 */
    unsigned char m1368;
    int m136c;
    int m1370[5];
    int m1384[17];
    unsigned char m13c8;
    int m13cc[12];
    List list13fc;              /* 0x13fc: 4-byte elements */
    int m1408[3];
    unsigned char m1414;
    unsigned char m1415;
    int m1418;
    unsigned char m141c;
    unsigned char m141d;
    unsigned char m141e;
    unsigned char m141f;
    char pad1420[0xc];
    unsigned char m142c;
    List list1430;              /* 0x1430: 16-byte elements */
    int m143c;
    unsigned char m1440;
    int m1444;
    int m1448;
    int m144c;
    int m1450;
    int m1454;
    int m1458;
    int m145c;
    char pad1460[0x50];
    unsigned char m14b0;
    unsigned char m14b1;
    unsigned char m14b2;
    int m14b4;
} Court;

extern char DAT_0030820c[];
extern char DAT_00308228[];
extern unsigned char DAT_003386b8;
extern Court *DAT_003402a0;     /* g_pCourt */
extern int DAT_003417c4;
extern unsigned char DAT_003417cc;
extern void FUN_0001f06c(Court *);
extern void FUN_0013fb58(void *);
extern void FUN_000c4040(List *, unsigned int);
extern void FUN_0012ca4c(List *, unsigned int);
extern int FUN_002b78f8(void);
extern void FUN_000133f4(int);
extern int FUN_0001342c(void);
extern void FUN_0013293c(Court *, int);

Court *FUN_00132180(Court *c)
{
    unsigned int m;
    List *l1;
    List *l2;

    FUN_0001f06c(c);
    FUN_0013fb58(&c->vptr1);
    c->vptr = DAT_0030820c;
    c->vptr1 = DAT_00308228;
    c->m1360 = 1;
    c->mode = 1;
    c->m1368 = 0;
    c->m136c = 0;
    c->m1370[0] = -1;
    c->m1370[1] = -1;
    c->m1370[2] = -1;
    c->m1370[3] = -1;
    c->m1370[4] = -1;
    c->m1384[0] = 0;
    c->m1384[1] = 0;
    c->m1384[2] = 0;
    c->m1384[3] = 0;
    c->m1384[4] = 0;
    c->m1384[5] = 0;
    c->m1384[6] = 0;
    c->m1384[7] = 0;
    c->m1384[8] = 0;
    c->m1384[9] = 0;
    c->m1384[10] = 0;
    c->m1384[11] = 0;
    c->m1384[12] = 0;
    c->m1384[13] = 0;
    c->m1384[14] = 0;
    c->m1384[15] = 0;
    c->m1384[16] = 0;
    c->m13cc[0] = 0;
    c->m13cc[1] = 0;
    c->m13cc[2] = 0;
    c->m13cc[3] = 0;
    c->m13cc[4] = 0;
    c->m13cc[5] = 0;
    c->m13cc[6] = 0;
    c->m13cc[7] = 0;
    c->m13cc[8] = 0;
    c->m13cc[9] = 0;
    c->m13cc[10] = 0;
    c->m13cc[11] = 0;
    l1 = &c->list13fc;
    l1->data = 0;
    l1->size = 0;
    l1->capacity = 0;
    c->m1408[0] = 0;
    c->m1408[1] = 0;
    c->m1408[2] = 0;
    c->m1414 = 1;
    c->m1415 = 1;
    c->m1418 = 0;
    c->m141c = 0;
    c->m141d = 1;
    c->m141e = 0;
    c->m141f = 1;
    c->m142c = 0;
    l2 = &c->list1430;
    l2->data = 0;
    l2->size = 0;
    l2->capacity = 0;
    c->m143c = 0;
    c->m1440 = 1;
    c->m1444 = 0;
    c->m1448 = -1;
    c->m144c = -1;
    c->m1450 = 0;
    c->m1454 = 0;
    c->m1458 = 0;
    c->m145c = -1;
    c->m14b0 = 0;
    c->m14b1 = 0;
    c->m14b2 = 0;
    c->m14b4 = 0;
    HST_ASSERT(DAT_003402a0 == 0);
    DAT_003402a0 = c;
    if (c->list13fc.capacity < 16) {
        FUN_000c4040(&c->list13fc, 16);
    }
    if (c->list1430.capacity < 16) {
        FUN_0012ca4c(&c->list1430, 16);
    }
    if (DAT_003386b8 != 0) {
        c->m1360 = DAT_003417c4;
    } else {
        FUN_000133f4(FUN_002b78f8());
        c->m1360 = FUN_0001342c();
    }
    m = DAT_003417cc;
    c->mode = m;
    if (m == 0 || m - 10 < 3) {
        c->mode = 1;
    }
    FUN_0013293c(c, c->mode);
    c->m13c8 = 0;
    return c;
}
