/* HSTMATCH module=EBOOT.BIN start=0x001e722c end=0x001e73d8 symbol=FUN_001e722c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

/* Text-like widget: font/resource slot and a refresh flag. */
struct Other_001e722c {
    char pad0[0xf8];
    void *font;
    char pad1[0x138 - 0xfc];
    int dirty;
};

extern "C" {
extern void *DAT_0034189c;
void FUN_0010d4a8(Other_001e722c *other);
void FUN_000ffb3c(void *elem, int flag);
}

/* Display element: current value and the base it is offset from. */
struct Target_001e722c {
    char pad[0x24];
    int value;
    int base;
};

/* Start of a 0x14-byte entry: its element and the base value it shows. */
struct Sub_001e722c {
    Target_001e722c *ptr;
    int off;
};

struct Obj_001e722c {
    char pad0[0x818];
    Sub_001e722c sub0;
    int pad_sub0[3];
    Sub_001e722c sub1;
    int pad_sub1[3];
    Sub_001e722c sub2;
    int pad_sub2[3];
    Sub_001e722c sub3;
    int pad_sub3[8];
    Sub_001e722c sub5;
    int pad_sub5[4];
    Other_001e722c *other;
};

/* Set up the page: show the first element at `shift` when `show` is set; with `alt` the rows get shifted bases. */
extern "C" void FUN_001e722c(Obj_001e722c *self, int shift, int alt, int show) {
    Other_001e722c *other = self->other;
    other->font = &DAT_0034189c;
    other->dirty = 1;
    FUN_0010d4a8(other);

    Sub_001e722c *row = &self->sub0;
    if (show != 0) {
        FUN_000ffb3c(row->ptr, 0);
        int v = row->off + shift;
        Target_001e722c *t = row->ptr;
        t->value = v;
        t->base = v;
    } else {
        FUN_000ffb3c(row->ptr, 1);
    }

    Sub_001e722c *row2 = &self->sub2;
    Sub_001e722c *row3 = &self->sub3;
    row = &self->sub1;
    Sub_001e722c *row5 = &self->sub5;

    FUN_000ffb3c(row2->ptr, 1);
    FUN_000ffb3c(row3->ptr, 1);
    FUN_000ffb3c(row->ptr, 1);
    FUN_000ffb3c(row5->ptr, 1);

    if (show != 0) {
        FUN_000ffb3c(row2->ptr, 0);
        FUN_000ffb3c(row3->ptr, 0);
        FUN_000ffb3c(row->ptr, 0);
        if (alt != 0) {
            int v2 = row2->off + 1;
            Target_001e722c *t2 = row2->ptr;
            t2->value = v2;
            t2->base = v2;

            int v1 = row3->off + 1;
            Target_001e722c *t1 = row3->ptr;
            t1->value = v1;
            t1->base = v1;

            int v0 = row->off + 17 + shift;
            Target_001e722c *t0 = row->ptr;
            t0->value = v0;
            t0->base = v0;
        } else {
            int v2 = row2->off;
            Target_001e722c *t2 = row2->ptr;
            t2->value = v2;
            t2->base = v2;

            int v1 = row3->off;
            Target_001e722c *t1 = row3->ptr;
            t1->value = v1;
            t1->base = v1;

            int v0 = row->off + shift;
            Target_001e722c *t0 = row->ptr;
            t0->value = v0;
            t0->base = v0;
        }
        FUN_000ffb3c(row5->ptr, 0);
    }
}
