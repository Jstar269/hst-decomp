/* HSTMATCH module=EBOOT.BIN start=0x0010f5d4 end=0x0010f9d8 symbol=FUN_0010f5d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Digit {
    int pad0;
    short x0, y0, x1, y1;
    short padc;
    unsigned short flags;
    char pad10[0x14];
    int v24;
    int v28;
};
struct Number {
    char pad0[0x10];
    Digit **items;
    int count;
    char pad18[0xfc - 0x18];
    int base;
    int w;
    int h;
    int gap;
    int width;
    int pad110;
    unsigned char lead;
    char pad115[3];
    int align;
    char pad11c[8];
    int value;
};
extern int DAT_002c114c[];
extern volatile int DAT_002d9238;
extern "C" float fabsf(float);
extern "C" void FUN_000ffb3c(Digit *, bool);
extern "C" void FUN_000ffca4(Digit *);

static inline int DigitAt(const int &v, int k)
{
    return (v % DAT_002c114c[k]) / DAT_002c114c[k - 1];
}
extern "C" void FUN_0010f5d4(Number *o, int n)
{
    int first = -1;
    int cnt = 0;
    int off = o->gap / 2;
    bool neg = (float)n < 0.0f;
    int a = (int)fabsf((float)n);
    int count = o->count;
    int hi;
    if (count >= 10)
        hi = 0x7fffffff;
    else
        hi = DAT_002c114c[count] - 1;
    int v = DAT_002d9238;
    v = (a < DAT_002d9238) ? v : ((hi < a) ? hi : a);
    int i;
    if (neg) {
        for (i = 0; i < count; i++) {
            FUN_000ffb3c(o->items[i], i < count - 3);
            int val = o->value;
            Digit *e = o->items[i];
            e->v24 = val;
            e->v28 = val;
            if (!(o->items[i]->flags & 3)) {
                if (first < 0)
                    first = i;
                cnt++;
                FUN_000ffca4(o->items[i]);
                off += o->w + o->gap;
            }
        }
    } else {
        unsigned char lz = o->lead;
        for (i = 0; i < count; i++) {
            if (i == count - 1)
                lz = 0;
            int d = DigitAt(v, count - i);
            FUN_000ffb3c(o->items[i], d == 0 && lz);
            int val = o->base + d;
            Digit *e = o->items[i];
            e->v24 = val;
            e->v28 = val;
            if (!(o->items[i]->flags & 3)) {
                if (first < 0)
                    first = i;
                cnt++;
                FUN_000ffca4(o->items[i]);
                off += o->w + o->gap;
            }
            if (d != 0)
                lz = 0;
        }
    }
    int half = o->gap / 2;
    off += half;
    switch (o->align) {
    case 0:
        off = o->width - off;
        break;
    case 1:
        off = (o->width - off) / 2;
        break;
    case 2:
        off = 0;
        break;
    }
    Digit **it = o->items;
    short x = off + it[0]->x0 + half;
    short y = it[0]->y0;
    for (i = first; i < first + cnt; i++) {
        Digit *p = it[i];
        p->x0 += x;
        p->x1 += x;
        Digit *e = o->items[i];
        short d = y - e->y0;
        e->y0 = y;
        e->y1 += d;
        e = o->items[i];
        e->x1 = o->w + e->x0;
        e = o->items[i];
        e->y1 = o->h + e->y0;
        it = o->items;
        x = o->gap + it[i]->x1;
    }
}
