/* HSTMATCH module=EBOOT.BIN start=0x0010e5b8 end=0x0010ea04 symbol=FUN_0010e5b8 rodata=0x002c1104 lang=c++ */
#pragma opt_strength_reduction off
struct Item {
    int pad0;
    short x0, y0, x1, y1;
};
struct Panel {
    char pad0[0x10];
    Item **items;
};
extern "C" void FUN_000ffb3c(Item *, int);

static inline short Width(const Item *it)
{
    return it->x1 - it->x0;
}
static inline short Height(const Item *it)
{
    return it->y1 - it->y0;
}
static inline void SetX(Item *it, short x)
{
    short d = x - it->x0;
    it->x0 = x;
    it->x1 += d;
}
static inline void SetY(Item *it, short y)
{
    short d = y - it->y0;
    it->y0 = y;
    it->y1 += d;
}

extern "C" void FUN_0010e5b8(Panel *p, short x, short y, short w, short h, short l, short t, int n)
{
    int i = 0;
    if (n > 0) {
        int xl = x + l;
        int yt = y + t;
        int xr = x + w;
        int yb = y + h;
        do {
            FUN_000ffb3c(p->items[i], 0);
            switch (i) {
            case 0: {
                Item *it = p->items[0];
                SetX(it, xl);
                SetY(it, yt);
                break;
            }
            case 1: {
                Item *it = p->items[2];
                SetX(it, l + (xr - Width(it)));
                SetY(it, yt);
                break;
            }
            case 2:
                p->items[1]->x0 = p->items[0]->x1;
                p->items[1]->x1 = p->items[2]->x0;
                SetY(p->items[1], yt);
                break;
            case 3: {
                Item *it = p->items[6];
                SetX(it, xl);
                SetY(it, t + (yb - Height(it)));
                break;
            }
            case 4: {
                Item *it = p->items[8];
                SetX(it, l + (xr - Width(it)));
                SetY(it, t + (yb - Height(it)));
                break;
            }
            case 5: {
                p->items[7]->x0 = p->items[6]->x1;
                p->items[7]->x1 = p->items[8]->x0;
                Item *it = p->items[7];
                SetY(it, t + (yb - Height(it)));
                break;
            }
            case 6:
                SetX(p->items[3], xl);
                p->items[3]->y0 = p->items[0]->y1;
                p->items[3]->y1 = p->items[6]->y0;
                break;
            case 7: {
                Item *it = p->items[5];
                SetX(it, l + (xr - Width(it)));
                p->items[5]->y0 = p->items[2]->y1;
                p->items[5]->y1 = p->items[8]->y0;
                break;
            }
            case 8:
                p->items[4]->x0 = p->items[3]->x1;
                p->items[4]->x1 = p->items[5]->x0;
                p->items[4]->y0 = p->items[3]->y0;
                p->items[4]->y1 = p->items[5]->y1;
                break;
            }
            i++;
        } while (i < n);
    }
}
// NEAR 137 words (same length, 275/275): only register allocation differs. Retail spills the int yb (y + h) to sp+56 and keeps
// the seh'd copies of xl and yt in s6/s7. Ours spills seh(yt) and keeps yb in a register, so every case that touches these
// values shifts its registers. Already tried: all 24 declaration orders, short-typed locals or reassigned params,
// int/short/const-ref helper parameters, locals inside the loop body, and explicit short copies. The control flow, the
// jump table and the instruction selection all match.
// near miss from lane ol3 (unreviewed)
