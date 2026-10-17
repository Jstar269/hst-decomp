/* HSTMATCH module=hstp_trans_main.prx start=0x001b807c end=0x001b8b34 symbol=FUN_001b807c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* kak_sprite.cpp (from the assert): fills one entry row of a menu panel (sprites in items[ib..ib+9], text
   labels in labels[lb..lb+4]); Sharing twin of EBOOT 0x1aaab0 with the player-name assert enabled. */
struct TextWidget;
extern "C" void FUN_00113a50(TextWidget *w);

struct TextWidget {
    char pad0[0xf8];
    const char *str;   /* 0xf8 */
    char padfc[0x138 - 0xfc];
    int visible;       /* 0x138 */
    void Set(const char *s, int on)
    {
        str = s;
        visible = on;
        FUN_00113a50(this);
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

extern Cfg *DAT_003e1e04;
extern char DAT_003899a0[];

extern const char DAT_003899a4[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_003899d0[]; /* "strlen(pProfile->GetPlayerName())>0" */
extern const char DAT_003899f4[]; /* "kak_sprite.cpp" */

extern "C" {
Mgr *FUN_001aa91c(void);
void FUN_00105470(Sprite *s, int on);
const char *FUN_0020d1e0(int cat, int sub, int n);
void *FUN_0019fc84(int id);
const char *FUN_00177d88(int id, void *p);
NameRec *FUN_00177d40(void);
void FUN_00228030(Item *it, int n);
unsigned int FUN_00014a40(const char *s); /* strlen */
void FUN_001b8b34(...);
void FUN_001b7e1c(Item *a, Item *b, Item *c, Item *d, Label *e, Label *f, Label *g, Label *h, Label *i);
}

#define KAK_ASSERT(c, text, line) \
    if (!(c)) { FUN_001b8b34(DAT_003899a4, text, DAT_003899f4, line); while (1) {} }

extern "C" void FUN_001b807c(Panel *self, int side, int ib, int lb)
{
    bool flag;
    Rec *rec = &FUN_001aa91c()->recs[side];
    int k = FUN_001aa91c()->f64;
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

    FUN_00105470(i0->spr, 1);
    FUN_00105470(i8->spr, 1);
    FUN_00105470(i9->spr, 1);
    if (FUN_001aa91c()->f2a4) {
        Flags *fl = FUN_001aa91c()->flags;
        if (FUN_001aa91c()->f2a5) {
            if (side == 0) {
                FUN_00105470(i0->spr, 0);
                i0->spr->frame = i0->spr->baseFrame;
            }
        } else {
            if (side == 1) {
                FUN_00105470(i0->spr, 0);
                i0->spr->frame = i0->spr->baseFrame + 1;
            }
        }
        if (!fl->f14[side]) {
            FUN_00105470(i8->spr, 0);
            FUN_00105470(i9->spr, 0);
        }
    }
    FUN_00105470(i1->spr, 1);
    if (flag) {
        FUN_001b7e1c(i1, i2, i4, i3, l0, l1, l3, l2, l4);
        FUN_00105470(i9->spr, 0);
        return;
    }
    if (!FUN_001aa91c()->flags->f10[side]) {
        FUN_001b7e1c(i1, i2, i4, i3, l0, l1, l3, l2, l4);
        return;
    }
    if (rec->f8) {
        if (rec->info->f7c == 2)
            FUN_00105470(i1->spr, 0);
        bool full = false;
        if (FUN_001aa91c()->f58) {
            if (side == 2 || side == 3) {
                if (rec->info->slots[k].v != 15)
                    full = true;
            }
        }
        if (full) {
            FUN_00105470(i4->spr, 0);
            FUN_00105470(i2->spr, 0);
            i2->spr->frame = i2->spr->baseFrame + 17;
        } else {
            FUN_00105470(i4->spr, 0);
            FUN_00105470(i2->spr, 0);
            i2->spr->frame = i2->spr->baseFrame + rec->info->slots[k].v;
        }
        int tens = rec->info->rank / 10;
        if (tens == 0 || tens == 50) {
            l3->text->Set(DAT_003899a0, 0);
            l2->text->Set(FUN_0020d1e0(13, 1, rec->info->rank), 1);
        } else {
            l3->text->Set(FUN_0020d1e0(13, 1, rec->info->rank), 1);
            l2->text->Set(DAT_003899a0, 0);
        }
        FUN_00105470(i3->spr, 0);
        FUN_00228030(i3, rec->info->rank);
        if (rec->f9) {
            l0->text->Set(FUN_0020d1e0(9, 11, 0), 1);
            l1->text->Set(FUN_0020d1e0(12, 0, rec->info->id), 1);
            void *p = FUN_0019fc84(rec->info->id);
            const char *s = FUN_00177d88(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_0020d1e0(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_0020d1e0(11, 1, 0), 1);
        } else {
        switch (rec->info->kind) {
        case 1: {
            l0->text->Set(FUN_0020d1e0(7, 0, rec->info->f20), 1);
            const char *s = FUN_00177d88(rec->info->id, (char *)rec->info + 0x68);
            l4->text->Set(FUN_0020d1e0(11, 1, (int)s), 1);
            break;
        }
        case 2:
        case 3: {
            l0->text->Set(FUN_0020d1e0(12, 0, rec->info->id), 1);
            void *p = FUN_0019fc84(rec->info->id);
            const char *s = FUN_00177d88(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_0020d1e0(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_0020d1e0(11, 1, 0), 1);
            break;
        }
        }
        l1->text->Set(FUN_0020d1e0(19, 0, 0), 1);
        }
    } else {
        if (rec->info->f7c == 2)
            FUN_00105470(i1->spr, 0);
        FUN_00105470(i4->spr, 0);
        FUN_00105470(i2->spr, 0);
        i2->spr->frame = i2->spr->baseFrame + rec->info->slots[k].v;
        int tens = rec->info->rank / 10;
        if (tens == 0 || tens == 50) {
            l3->text->Set(DAT_003899a0, 0);
            l2->text->Set(FUN_0020d1e0(13, 1, rec->info->rank), 1);
        } else {
            l3->text->Set(FUN_0020d1e0(13, 1, rec->info->rank), 1);
            l2->text->Set(DAT_003899a0, 0);
        }
        FUN_00105470(i3->spr, 0);
        FUN_00228030(i3, rec->info->rank);
        if (FUN_001aa91c()->f2a4) {
            bool own;
            if (side == 1) {
                if (DAT_003e1e04->f178)
                    own = false;
                else
                    own = true;
            } else {
                if (DAT_003e1e04->f178)
                    own = true;
                else
                    own = false;
            }
            if (own)
                l0->text->Set(FUN_00177d40()->name, 1);
            else {
                KAK_ASSERT(FUN_00014a40(rec->name) > 0, DAT_003899d0, 1594);
                l0->text->Set(rec->name, 1);
            }
            l1->text->Set(FUN_0020d1e0(12, 0, rec->info->id), 1);
            void *p = FUN_0019fc84(rec->info->id);
            const char *s = FUN_00177d88(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_0020d1e0(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_0020d1e0(11, 1, 0), 1);
        } else {
            l0->text->Set(FUN_00177d40()->name, 1);
            l1->text->Set(FUN_0020d1e0(12, 0, rec->info->id), 1);
            void *p = FUN_0019fc84(rec->info->id);
            const char *s = FUN_00177d88(rec->info->id, (char *)p + 0x68);
            if (p)
                l4->text->Set(FUN_0020d1e0(11, 1, (int)s), 1);
            else
                l4->text->Set(FUN_0020d1e0(11, 1, 0), 1);
        }
    }
}
