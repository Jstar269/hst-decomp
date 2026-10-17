/* HSTMATCH module=EBOOT.BIN start=0x001aaab0 end=0x001ab530 symbol=FUN_001aaab0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Fills one entry row of a menu panel (sprites in items[ib..ib+9], text labels in labels[lb..lb+4]). */
struct TextWidget;
extern "C" void FUN_0010d4a8(TextWidget *w);

struct TextWidget {
    char pad0[0xf8];
    const char *str;   /* 0xf8 */
    char padfc[0x138 - 0xfc];
    int visible;       /* 0x138 */
    void Set(const char *s, int on)
    {
        str = s;
        visible = on;
        FUN_0010d4a8(this);
    }
};

struct Label {
    int f0;
    TextWidget *text;  /* +4 */
    int f8;
};

struct Sprite {
    char pad0[0x24];
    int frame;      /* 0x24 */
    int baseFrame;  /* 0x28 */
};

struct Item {
    Sprite *spr;
    char pad4[0x10];
};

struct Panel {
    char pad0[0x2c];
    Item items[104];   /* 0x2c */
    Label labels[8];   /* 0x84c */
};

struct Slot3 {
    unsigned char v;
    unsigned char pad[2];
};

struct Info {
    short id;              /* 0x00 */
    char pad2[8];
    short rank;            /* 0x0a */
    char padc[2];
    unsigned char kind;    /* 0x0e */
    char padf[0x20 - 0xf];
    unsigned short f20;    /* 0x20 */
    char pad22[0x7c - 0x22];
    unsigned char f7c;     /* 0x7c */
    Slot3 slots[8];        /* 0x7d */
};

struct Rec {
    int f0;
    Info *info;            /* 0x04 */
    unsigned char f8;      /* 0x08 */
    unsigned char f9;      /* 0x09 */
    unsigned char fa;      /* 0x0a */
    char padb[5];
    char name[0x20];       /* 0x10 */
};

struct Flags {
    char pad0[0x10];
    unsigned char f10[4];  /* 0x10 */
    unsigned char f14[4];  /* 0x14 */
};

struct Mgr {
    char pad0[0x58];
    unsigned char f58;     /* 0x58 */
    char pad59[0x64 - 0x59];
    int f64;               /* 0x64 */
    char pad68[0x88 - 0x68];
    Flags *flags;          /* 0x88 */
    char pad8c[0x160 - 0x8c];
    Rec *recs;             /* 0x160 */
    char pad164[0x2a4 - 0x164];
    unsigned char f2a4;    /* 0x2a4 */
    unsigned char f2a5;    /* 0x2a5 */
};

struct Cfg {
    char pad0[0x178];
    unsigned char f178;
};

struct NameRec {
    char pad0[0x20];
    char name[0x20];       /* 0x20 */
};

extern Cfg *DAT_00338ac4;
extern char DAT_002e20d0[];

extern "C" {
Mgr *FUN_0019d474(void);
void FUN_000ffb3c(Sprite *s, int on);
const char *FUN_001fea10(int cat, int sub, int n);
void *FUN_00193474(int id);
const char *FUN_0016bb98(int id, void *p);
NameRec *FUN_0016bb7c(void);
void FUN_00218b18(Item *it, int n);
void FUN_001aa850(Item *a, Item *b, Item *c, Item *d, Label *e, Label *f, Label *g, Label *h, Label *i);
}

extern "C" void FUN_001aaab0(Panel *self, int side, int ib, int lb)
{
    bool flag;
    Rec *rec = &FUN_0019d474()->recs[side];
    int k = FUN_0019d474()->f64;
    Item *i0 = &self->items[ib];
    Item *i1 = &self->items[ib + 1];
    Item *i2 = &self->items[ib + 2];
    Item *i4 = &self->items[ib + 4];
    Item *i8 = &self->items[ib + 8];
    Item *i9 = &self->items[ib + 9];
    Item *i3 = &self->items[ib + 3];
    Label *l0 = &self->labels[lb];
    Label *l1 = &self->labels[lb + 1];
    Label *l3 = &self->labels[lb + 3];
    Label *l2 = &self->labels[lb + 2];
    Label *l4 = &self->labels[lb + 4];
    flag = false;
    if (rec->fa)
        flag = true;

    FUN_000ffb3c(i0->spr, 1);
    FUN_000ffb3c(i8->spr, 1);
    FUN_000ffb3c(i9->spr, 1);
    if (FUN_0019d474()->f2a4) {
        Flags *fl = FUN_0019d474()->flags;
        if (FUN_0019d474()->f2a5) {
            if (side == 0) {
                FUN_000ffb3c(i0->spr, 0);
                i0->spr->frame = i0->spr->baseFrame;
            }
        } else {
            if (side == 1) {
                FUN_000ffb3c(i0->spr, 0);
                i0->spr->frame = i0->spr->baseFrame + 1;
            }
        }
        if (!fl->f14[side]) {
            FUN_000ffb3c(i8->spr, 0);
            FUN_000ffb3c(i9->spr, 0);
        }
    }
    FUN_000ffb3c(i1->spr, 1);
    if (flag) {
        FUN_001aa850(i1, i2, i4, i3, l0, l1, l3, l2, l4);
        FUN_000ffb3c(i9->spr, 0);
        return;
    }
    if (!FUN_0019d474()->flags->f10[side]) {
        FUN_001aa850(i1, i2, i4, i3, l0, l1, l3, l2, l4);
        return;
    }
    if (rec->f8) {
        if (rec->info->f7c == 2)
            FUN_000ffb3c(i1->spr, 0);
        bool full = false;
        if (FUN_0019d474()->f58) {
            if (side == 2 || side == 3) {
                if (rec->info->slots[k].v != 15)
                    full = true;
            }
        }
        if (full) {
            FUN_000ffb3c(i4->spr, 0);
            FUN_000ffb3c(i2->spr, 0);
            i2->spr->frame = i2->spr->baseFrame + 17;
        } else {
            FUN_000ffb3c(i4->spr, 0);
            FUN_000ffb3c(i2->spr, 0);
            i2->spr->frame = i2->spr->baseFrame + rec->info->slots[k].v;
        }
        int tens = rec->info->rank / 10;
        if (tens == 0 || tens == 50) {
            l3->text->Set(DAT_002e20d0, 0);
            l2->text->Set(FUN_001fea10(13, 1, rec->info->rank), 1);
        } else {
            l3->text->Set(FUN_001fea10(13, 1, rec->info->rank), 1);
            l2->text->Set(DAT_002e20d0, 0);
        }
        FUN_000ffb3c(i3->spr, 0);
        FUN_00218b18(i3, rec->info->rank);
        if (rec->f9) {
            l0->text->Set(FUN_001fea10(9, 11, 0), 1);
            l1->text->Set(FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_001fea10(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_001fea10(11, 1, 0), 1);
        } else {
        switch (rec->info->kind) {
        case 1: {
            l0->text->Set(FUN_001fea10(7, 0, rec->info->f20), 1);
            const char *s = FUN_0016bb98(rec->info->id, (char *)rec->info + 0x68);
            l4->text->Set(FUN_001fea10(11, 1, (int)s), 1);
            break;
        }
        case 2:
        case 3: {
            l0->text->Set(FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_001fea10(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_001fea10(11, 1, 0), 1);
            break;
        }
        }
        l1->text->Set(FUN_001fea10(19, 0, 0), 1);
        }
    } else {
        if (rec->info->f7c == 2)
            FUN_000ffb3c(i1->spr, 0);
        FUN_000ffb3c(i4->spr, 0);
        FUN_000ffb3c(i2->spr, 0);
        i2->spr->frame = i2->spr->baseFrame + rec->info->slots[k].v;
        int tens = rec->info->rank / 10;
        if (tens == 0 || tens == 50) {
            l3->text->Set(DAT_002e20d0, 0);
            l2->text->Set(FUN_001fea10(13, 1, rec->info->rank), 1);
        } else {
            l3->text->Set(FUN_001fea10(13, 1, rec->info->rank), 1);
            l2->text->Set(DAT_002e20d0, 0);
        }
        FUN_000ffb3c(i3->spr, 0);
        FUN_00218b18(i3, rec->info->rank);
        if (FUN_0019d474()->f2a4) {
            bool own;
            if (side == 1) {
                if (DAT_00338ac4->f178)
                    own = false;
                else
                    own = true;
            } else {
                if (DAT_00338ac4->f178)
                    own = true;
                else
                    own = false;
            }
            if (own)
                l0->text->Set(FUN_0016bb7c()->name, 1);
            else
                l0->text->Set(rec->name, 1);
            l1->text->Set(FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_001fea10(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_001fea10(11, 1, 0), 1);
        } else {
            l0->text->Set(FUN_0016bb7c()->name, 1);
            l1->text->Set(FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_001fea10(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_001fea10(11, 1, 0), 1);
        }
    }
}
