/* HSTMATCH module=EBOOT.BIN start=0x0025eca0 end=0x0025efd4 symbol=FUN_0025eca0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Option-menu refresh (6 rows). Matching idioms: rows are `items[i + 1]` of a 7-entry array that starts at 0xc8 (items[0].value is the cursor at 0xe0);
   the inline bit test `Bits32::test` aborts through FUN_0025efd4 (fprintf) / FUN_0000d518 when pos >= 32; the third kind dispatch passes the kind as the
   (ignored) argument of FUN_00253a68, which is what puts it in a0; `bool ok` is set to false in the else arm of `if (i != LAST_ROW)` so the last-row flag test is out of line. */
extern char DAT_002c6a78[];

#define MENU_ROWS 6        /* rows refreshed */
#define LAST_ROW 5         /* row whose value is a bit set instead of a plain index */
#define BIT_COUNT 19       /* bit positions scanned for the last row */
#define BIT_WORD_LIMIT 32  /* bit positions a Bits32 can hold */
#define KIND_SUB 2         /* row kind that maps its value through the sub-object */
#define KIND_BITS 6        /* row kind that maps its value through the bit set */

struct Widget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void SetFlags(unsigned f);
    char pad[0xf8 - 4];
    const char *text;
    char pad3[0x138 - 0xfc];
    int dirty;
};
struct Reent { int pad[3]; void *err; };
extern "C" {
Reent *FUN_0000fe3c(void);
int FUN_0025efd4(void *stream, const char *format, ...);
void FUN_0000d518(void);
unsigned FUN_0025395c(void *a, int b);
int FUN_002535e0(void *a, int b);
int FUN_002535f0(void *a, int b);
const char *FUN_00253974(int kind, int v);
int FUN_00253628(void *a);
int FUN_0025396c(void *a);
int FUN_00253a68(int kind);
void FUN_0010d4a8(Widget *w);
void FUN_000ffb3c(Widget *w, int f);
}

struct Bits32 {
    unsigned bits;
    bool test(unsigned pos) const
    {
        if (pos >= BIT_WORD_LIMIT) {
            FUN_0025efd4(FUN_0000fe3c()->err, DAT_002c6a78);
            FUN_0000d518();
        }
        return (bits & (1u << pos)) != 0;
    }
};

/* One menu row: three marker widgets, the text widget, its kind, the current value and the two mapping sources. */
struct Row {
    Widget *a;
    Widget *b;
    Widget *c;
    int pad;
    Widget *obj;
    int kind;
    int value;
    void *p1;   /* source for KIND_SUB */
    void *p2;   /* source for KIND_BITS */
};

struct Menu {
    char pad0[0x64];
    unsigned char unk64;
    char pad1[0xc8 - 0x65];
    Row items[7];
    char sub[0x250 - 0x1c4];
    Bits32 bits;
    char pad3[0x2c8 - 0x254];
    int unk2c8;
    int vals[MENU_ROWS];   /* 0x2cc value of each row */
};

extern "C" void FUN_0025f000(Menu *m, int f);

/* Refreshes all rows from the stored values: each row's text widget gets the mapped value's text; the last row first finds the first set bit and its index. */
extern "C" void FUN_0025eca0(Menu *m)
{
    m->items[0].value = m->unk2c8;
    for (int i = 0; i < MENU_ROWS; i++) {
        if (i == LAST_ROW) {
            m->bits.bits = m->vals[i];
            for (int pos = 0; pos < BIT_COUNT; pos++) {
                if (m->bits.test(pos)) {
                    int k = 0;
                    do {
                        if (pos == FUN_0025395c(&m->bits, k)) break;
                        k++;
                    } while (k < 5);
                    Row *r = &m->items[i + 1];
                    r->value = k;
                    int v = k;
                    if (r->kind == KIND_SUB) {
                        v = FUN_002535e0(r->p1, k);
                    } else if (r->kind == KIND_BITS) {
                        v = FUN_0025395c(r->p2, k);
                    }
                    const char *t = FUN_00253974(r->kind, v);
                    Widget *w = r->obj;
                    w->text = t;
                    w->dirty = 1;
                    FUN_0010d4a8(w);
                    FUN_000ffb3c(r->a, 0);
                    bool ok;
                    if (i != LAST_ROW) {
                        ok = false;
                    } else {
                        int q = FUN_0025395c(&m->bits, m->items[i + 1].value);
                        ok = m->unk64 != 0 && q >= 16 && q <= 18;
                    }
                    if (ok) {
                        r->obj->SetFlags(0x40000000);
                        FUN_0025f000(m, 1);
                    } else {
                        r->obj->SetFlags(0x80000000);
                        FUN_0025f000(m, 0);
                    }
                    break;
                }
            }
        } else {
            if (i == 1) {
                m->items[i + 1].value = FUN_002535f0(&m->sub, m->vals[i]);
            } else {
                m->items[i + 1].value = m->vals[i];
            }
            Row *r = &m->items[i + 1];
            r->p1 = &m->sub;
            r->p2 = &m->bits;
            int v = r->value;
            if (r->kind == KIND_SUB) {
                v = FUN_002535e0(r->p1, v);
            } else if (r->kind == KIND_BITS) {
                v = FUN_0025395c(r->p2, v);
            }
            const char *t = FUN_00253974(r->kind, v);
            Widget *w = r->obj;
            w->text = t;
            w->dirty = 1;
            FUN_0010d4a8(w);
            FUN_000ffb3c(r->a, 0);
            FUN_000ffb3c(r->b, r->value == 0);
            int n;
            if (r->kind == KIND_SUB) {
                n = FUN_00253628(r->p1);
            } else if (r->kind == KIND_BITS) {
                n = FUN_0025396c(r->p2);
            } else {
                n = FUN_00253a68(r->kind);
            }
            FUN_000ffb3c(r->c, r->value == n - 1);
        }
    }
}
