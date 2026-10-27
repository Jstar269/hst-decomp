/* HSTMATCH module=hstp_trans_main.prx start=0x0013d738 end=0x0013d980 symbol=FUN_0013d738 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: both lists are cleared through local pointers (`l1 = &c->list13fc; l1->data = 0; ...`), and MWCC reuses l1's address computation for the later grow argument `&c->list13fc`, which puts retail's `addiu a0,s0,5116` into the g_pCourt assertion's delay slot (clearing the members directly, or through an inline init helper, computes it at the call: 8 words off); exact match verified; names and types await human review. */
/* Court.cpp (file name and the g_pCourt name from the assert strings): constructor of the court object (two polymorphic
   bases: FUN_0001ec44 at +0, FUN_0014b1a4 at +0x40, vtables DAT_003b14d8 / DAT_003b14f4), registers itself as g_pCourt,
   reserves 16 entries in both lists. Debug build of the EBOOT twin src/eboot/court_ctor_00132180.c (same source, the
   assertion is kept here). */
extern void FUN_0013d9d8(const char *, ...);
extern const char DAT_003824e4[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00382510[];   /* "g_pCourt == 0" */
extern const char DAT_00382520[];   /* "Court.cpp" */
#define HST_ASSERT(cond, text, file, line) do { if (!(cond)) { FUN_0013d9d8(DAT_003824e4, text, file, line); for (;;) {} } } while (0)

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

extern char DAT_003b14d8[];
extern char DAT_003b14f4[];
extern unsigned char DAT_003e19f8;
extern Court *DAT_003e95e0;     /* g_pCourt */
extern int DAT_003eaafc;
extern unsigned char DAT_003eab04;
extern void FUN_0001ec44(Court *);
extern void FUN_0014b1a4(void *);
extern void FUN_000c78a8(List *, unsigned int);
extern void FUN_00137eb8(List *, unsigned int);
extern int FUN_002c7698(void);
extern void FUN_000133f4(int);
extern int FUN_0001342c(void);
extern void FUN_0013df58(Court *, int);

Court *FUN_0013d738(Court *c)
{
    unsigned int m;
    List *l1;
    List *l2;

    FUN_0001ec44(c);
    FUN_0014b1a4(&c->vptr1);
    c->vptr = DAT_003b14d8;
    c->vptr1 = DAT_003b14f4;
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
    HST_ASSERT(DAT_003e95e0 == 0, DAT_00382510, DAT_00382520, 157);
    DAT_003e95e0 = c;
    if (c->list13fc.capacity < 16) {
        FUN_000c78a8(&c->list13fc, 16);
    }
    if (c->list1430.capacity < 16) {
        FUN_00137eb8(&c->list1430, 16);
    }
    if (DAT_003e19f8 != 0) {
        c->m1360 = DAT_003eaafc;
    } else {
        FUN_000133f4(FUN_002c7698());
        c->m1360 = FUN_0001342c();
    }
    m = DAT_003eab04;
    c->mode = m;
    if (m == 0 || m - 10 < 3) {
        c->mode = 1;
    }
    FUN_0013df58(c, c->mode);
    c->m13c8 = 0;
    return c;
}
