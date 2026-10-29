/* HSTMATCH module=EBOOT.BIN start=0x00064a88 end=0x00064bf4 symbol=FUN_00064a88 lang=c++ */
struct Item {
    virtual ~Item();
};

struct Row {
    Item **items;
    int count;
    int pad;
};

struct Vec {
    Row *rows;
    int count;
    int fc;
};

struct Box {
    Vec v;
    int spare[2];
};

struct Self {
    char pad[4];
    Vec v;
};

struct Tag {};
struct Empty {};
struct False : Empty {};

extern "C" void FUN_00065dd0(Vec *v, int n, Tag tag);
extern "C" void FUN_00065a88(Vec *out, Row *first, Row *last, False tag);
extern "C" void FUN_00065fa0(Vec *p, int n);

static inline bool Eq(const void *a, const void *b) { return a == b; }
static inline bool Ne(const void *a, const void *b) { return !Eq(a, b); }

extern "C" void FUN_00064a88(Self *self)
{
    Row *row = self->v.rows;
    while (Ne(row, self->v.rows + self->v.count)) {
        Item **p = row->items;
        while (Ne(p, row->items + row->count)) {
            Item *item = *p;
            delete item;
            p++;
        }
        row++;
    }
    FUN_00065dd0(&self->v, self->v.count, Tag());
    Box box;
    Vec &out = box.v;
    out.rows = 0;
    out.count = 0;
    out.fc = 0;
    False tag;
    FUN_00065a88(&out, self->v.rows, self->v.rows + self->v.count, tag);
    {
        int t = out.fc;
        out.fc = self->v.fc;
        self->v.fc = t;
    }
    {
        Row *tr = out.rows;
        out.rows = self->v.rows;
        self->v.rows = tr;
    }
    {
        int t = out.count;
        out.count = self->v.count;
        self->v.count = t;
    }
    FUN_00065fa0(&out, 0);
}
// NEAR 92/91 words, 45 differ (sy3), frame/slots now exact. Decoded: FUN_00065dd0(Vec *, int, Tag) with an empty Tag (`move v0,zero; seb a2`), and
// FUN_00065a88(Vec *out, Row *first, Row *last, False tag) where `struct False : Empty {}` is a NAMED local declared after the out Vec
// (`lb a3,24(sp)` from a never-written slot; the volatile flag of the old wip is gone). The Out Vec sits in a 20-byte `Box { Vec v; int spare[2]; }`
// so that out=sp+28 and tag=sp+24 as in retail. Left: retail keeps the row-count temp in a1 (loop-exit `lw a1,8(s2)` flows straight into the dropped
// 2nd argument of the first call; ours uses v1/a0 and reloads a1 before the call) and loads the row pointer into s1 with `move s2,a0` later.
// near miss from lane sy3 (unreviewed)
