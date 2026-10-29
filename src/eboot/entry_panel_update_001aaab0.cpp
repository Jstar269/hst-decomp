/* HSTMATCH module=EBOOT.BIN start=0x001aaab0 end=0x001ab530 symbol=FUN_001aaab0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Fills one entry row of a menu panel (sprites in items[ib..ib+9], text labels in labels[lb..lb+4]). */
#include "hst/entry_panel.h"

extern "C" void FUN_0010d4a8(EntryText *w);

/* Sets a text widget's string and visibility, then refreshes it. */
static inline void SetText(EntryText *w, const char *s, int on)
{
    w->str = s;
    w->visible = on;
    FUN_0010d4a8(w);
}

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
EntryMgr *FUN_0019d474(void);
void FUN_000ffb3c(EntrySprite *s, int on);
const char *FUN_001fea10(int cat, int sub, int n);
void *FUN_00193474(int id);
const char *FUN_0016bb98(int id, void *p);
NameRec *FUN_0016bb7c(void);
void FUN_00218b18(EntryItem *it, int n);
void FUN_001aa850(EntryItem *a, EntryItem *b, EntryItem *c, EntryItem *d, EntryLabel *e, EntryLabel *f, EntryLabel *g, EntryLabel *h, EntryLabel *i);
}

extern "C" void FUN_001aaab0(EntryPanel *self, int side, int ib, int lb)
{
    bool flag;
    EntryRec *rec = &FUN_0019d474()->recs[side];
    int slot_idx = FUN_0019d474()->unk64;
    EntryItem *i0 = &self->items[ib];
    EntryItem *i1 = &self->items[ib + 1];
    EntryItem *i2 = &self->items[ib + 2];
    EntryItem *i4 = &self->items[ib + 4];
    EntryItem *i8 = &self->items[ib + 8];
    EntryItem *i9 = &self->items[ib + 9];
    EntryItem *i3 = &self->items[ib + 3];
    EntryLabel *l0 = &self->labels[lb];
    EntryLabel *l1 = &self->labels[lb + 1];
    EntryLabel *l3 = &self->labels[lb + 3];
    EntryLabel *l2 = &self->labels[lb + 2];
    EntryLabel *l4 = &self->labels[lb + 4];
    flag = false;
    if (rec->unka)
        flag = true;

    FUN_000ffb3c(i0->spr, 1);
    FUN_000ffb3c(i8->spr, 1);
    FUN_000ffb3c(i9->spr, 1);
    if (FUN_0019d474()->unk2a4) {
        EntryFlags *fl = FUN_0019d474()->flags;
        if (FUN_0019d474()->unk2a5) {
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
        if (!fl->unk14[side]) {
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
    if (!FUN_0019d474()->flags->unk10[side]) {
        FUN_001aa850(i1, i2, i4, i3, l0, l1, l3, l2, l4);
        return;
    }
    if (rec->unk8) {
        if (rec->info->unk7c == 2)
            FUN_000ffb3c(i1->spr, 0);
        bool full = false;
        if (FUN_0019d474()->unk58) {
            if (side == 2 || side == 3) {
                if (rec->info->slots[slot_idx].v != 15)
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
            i2->spr->frame = i2->spr->baseFrame + rec->info->slots[slot_idx].v;
        }
        int tens = rec->info->rank / 10;
        if (tens == 0 || tens == 50) {
            SetText(l3->text, DAT_002e20d0, 0);
            SetText(l2->text, FUN_001fea10(13, 1, rec->info->rank), 1);
        } else {
            SetText(l3->text, FUN_001fea10(13, 1, rec->info->rank), 1);
            SetText(l2->text, DAT_002e20d0, 0);
        }
        FUN_000ffb3c(i3->spr, 0);
        FUN_00218b18(i3, rec->info->rank);
        if (rec->unk9) {
            SetText(l0->text, FUN_001fea10(9, 11, 0), 1);
            SetText(l1->text, FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                SetText(l4->text, FUN_001fea10(11, 1, (int)s), 1);
            else
                SetText(l4->text, FUN_001fea10(11, 1, 0), 1);
        } else {
        switch (rec->info->kind) {
        case 1: {
            SetText(l0->text, FUN_001fea10(7, 0, rec->info->unk20), 1);
            const char *s = FUN_0016bb98(rec->info->id, (char *)rec->info + 0x68);
            SetText(l4->text, FUN_001fea10(11, 1, (int)s), 1);
            break;
        }
        case 2:
        case 3: {
            SetText(l0->text, FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                SetText(l4->text, FUN_001fea10(11, 1, (int)s), 1);
            else
                SetText(l4->text, FUN_001fea10(11, 1, 0), 1);
            break;
        }
        }
        SetText(l1->text, FUN_001fea10(19, 0, 0), 1);
        }
    } else {
        if (rec->info->unk7c == 2)
            FUN_000ffb3c(i1->spr, 0);
        FUN_000ffb3c(i4->spr, 0);
        FUN_000ffb3c(i2->spr, 0);
        i2->spr->frame = i2->spr->baseFrame + rec->info->slots[slot_idx].v;
        int tens = rec->info->rank / 10;
        if (tens == 0 || tens == 50) {
            SetText(l3->text, DAT_002e20d0, 0);
            SetText(l2->text, FUN_001fea10(13, 1, rec->info->rank), 1);
        } else {
            SetText(l3->text, FUN_001fea10(13, 1, rec->info->rank), 1);
            SetText(l2->text, DAT_002e20d0, 0);
        }
        FUN_000ffb3c(i3->spr, 0);
        FUN_00218b18(i3, rec->info->rank);
        if (FUN_0019d474()->unk2a4) {
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
                SetText(l0->text, FUN_0016bb7c()->name, 1);
            else
                SetText(l0->text, rec->name, 1);
            SetText(l1->text, FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                SetText(l4->text, FUN_001fea10(11, 1, (int)s), 1);
            else
                SetText(l4->text, FUN_001fea10(11, 1, 0), 1);
        } else {
            SetText(l0->text, FUN_0016bb7c()->name, 1);
            SetText(l1->text, FUN_001fea10(12, 0, rec->info->id), 1);
            void *p = FUN_00193474(rec->info->id);
            const char *s = FUN_0016bb98(rec->info->id, (char *)p + 0x68);
            if (p)
                SetText(l4->text, FUN_001fea10(11, 1, (int)s), 1);
            else
                SetText(l4->text, FUN_001fea10(11, 1, 0), 1);
        }
    }
}
