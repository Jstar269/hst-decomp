/* HSTMATCH module=EBOOT.BIN start=0x002a2488 end=0x002a2694 symbol=FUN_002a2488 lang=c99 rodata=0x002cc010 helpers=FUN_002a0b30@0x002a0b30-0x002a0b5c */
extern void FUN_002a1898(void *, int, int);
static void FUN_002a0b30(...)
{
}
extern void FUN_0021bf00(float, float, int);
extern void FUN_0021bf24(int, int, int);
extern void FUN_002216cc(int);
extern int DAT_003415a8;
extern char DAT_002cc1c4;

struct StampMgr {
    char pad0[0x1b0];
    int mode;      /* 1b0 */
    int f1b4;
    int idx;       /* 1b8 */
    char pad1[8];
    int f1c4;
    char pad2[4];
    int *tbl;      /* 1cc */
    char pad3[4];
    int *state;    /* 1d4 */
    char pad4[0xc];
    unsigned char f1e4;
    char pad5[0x17];
    unsigned char f1fc;
};

struct StateRec {
    int f0;
    int f4;
    int f8;
};

void FUN_002a2488(struct StampMgr *p, int mode)
{
    int *rec;
    struct StateRec *st;
    unsigned char *e;
    int n;

    p->mode = mode;
    p->f1b4 = 0;
    switch (p->mode) {
    case 0:
        p->f1e4 = 0;
        break;
    case 1:
        p->f1c4 = 0;
        p->f1fc = 0;
        FUN_002a1898(p, (p->f1c4 + *(int *)(p->idx * 4 + (char *)p->tbl + 0xc)) * 0x10 + *(int *)(p->tbl + 1), 0);
        return;
    case 3:
        break;
    case 2:
        rec = (int *)(*(int *)(p->tbl + 1) + (p->f1c4 + *(int *)(p->idx * 4 + (char *)p->tbl + 0xc)) * 0x10);
        n = rec[3];
        if (n > 0)
            FUN_002a0b30(&DAT_002cc1c4);
        st = (struct StateRec *)p->state;
        n = n - 1;
        st->f8 = n;
        if (n == 2) {
            /* nothing */
        } else if (n == 1) {
            e = (n < 0 || n >= 12) ? 0 : (unsigned char *)(DAT_003415a8 + 0x34c4 + n * 5);
            *e = 4;
        } else if (n == 0) {
            *(unsigned char *)(DAT_003415a8 + 0x1073) = 4;
            *(unsigned char *)(DAT_003415a8 + 0x1074) = 4;
        }
        FUN_0021bf00(100.0f, 136.0f, st->f0);
        if (n == 2)
            FUN_002216cc(st->f4);
        else if (n == 1)
            FUN_0021bf24(st->f0, 13, 0);
        else if (n == 0)
            FUN_0021bf24(st->f0, 8, 0);
        break;
    case 5:
        break;
    case 4:
        p->f1c4 = 0;
        FUN_002a1898(p, *(int *)(p->idx * 4 + (char *)p->tbl + 0xc) * 0x10 + *(int *)(p->tbl + 1), 1);
        break;
    }
}

// 132/131 words, 108 differ. The same-file static stub works: `static void
// FUN_002a0b30(...) { }` (unnamed ellipsis, C is fine) + helpers= gives an exact
// helper AND retail's v1/a1 allocation in the caller. Remaining delta: the case-1/4
// offset operand loads in the order tbl, idx, f1c4 here and idx, tbl, f1c4 in retail
// (retail computes the tbl[idx].off addend before loading tbl->f4), and the case-2
// block is one word wider; the jump table, dispatch and every store already match.
// near miss from lane fm8 (unreviewed)
