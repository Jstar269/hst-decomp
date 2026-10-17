/* HSTMATCH module=hstp_trans_main.prx start=0x00188a90 end=0x00188dc8 symbol=FUN_00188a90 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the three cursor calls take `&o->cursor` through a void* prototype (a Cursor* argument is folded into the saved register that FUN_0020d184 uses, retail recomputes o+0x5c); FUN_00048e38 receives `force` (zero on that path). */
struct Sub {
    virtual void v0();
    virtual void v1();
};

struct Link {
    char pad[0x1b4];
    int f1b4;
};

struct Item {
    int pad0;
    int state;
    unsigned char b8, b9, b10, pad11[5];
    Sub sub;
    char pad14[0x60 - 0x14];
    Link *link;
};

struct Cursor {
    int cur;
    char pad4[3];
    unsigned char b7;
};

struct Sel {
    int cur;
    unsigned char b4, b5, b6, b7;
    int v8, vc, v10, v14, v18, v1c;
    void Reset()
    {
        cur = 0x7fffffff;
        b4 = 0; b5 = 0; b6 = 0; b7 = 0;
        v8 = 0x7fffffff; vc = 0x7fffffff; v10 = 0x7fffffff;
        v14 = 0x7fffffff; v18 = 0x7fffffff; v1c = 0x7fffffff;
    }
};

struct Tab {
    char pad[0x1025];
    unsigned char b[15];
};

struct Obj {
    int pad0;
    int f4;
    Item **items;
    char pad0c[0x5c - 0x0c];
    Cursor cursor;
    char pad64[0x2e4 - 0x64];
    Sel sel;
};

struct Glob {
    char pad[0x17c];
    int f17c;
};

extern "C" {
int FUN_00048e38(int);
void FUN_00096348(void *);
void FUN_0009635c(void *);
Tab *FUN_00177d4c();
int FUN_00177e98();
Item *FUN_00185db8(int, int, int, int);
void FUN_001896a8(Obj *, int);
void FUN_001896c4(Obj *, int);
void FUN_00189e1c(Obj *, int, int);
void FUN_00189ea0(Obj *, int, int, int, int);
void FUN_00189f74(Obj *, int, int, int);
void FUN_0018b0a4(int);
int FUN_0020d018(void *, int, int);
int FUN_0020d058(void *);
void FUN_0020d090(void *);
int FUN_0020d184(Cursor *, Sel *);
extern Glob *DAT_003ea858;
}

extern "C" void FUN_00188a90(Obj *o, int force)
{
    Cursor *cur = &o->cursor;
    Sel *sel = &o->sel;
    bool ok = false;
    if (force != 0) {
        ok = true;
    } else if (sel->b5 != 0 && sel->b6 != 0 && FUN_00048e38(force) != 0) {
        ok = true;
    }
    if (!ok) return;
    int idx = cur->cur;
    if (idx != 0x7fffffff) {
        if (sel->cur != 0x7fffffff && idx != sel->cur) {
            sel->Reset();
            return;
        }
    }
    idx = sel->cur;
    Item *item = o->items[idx];
    if (item->state != 4) {
        if (item->state != 2 && item->state != 3) item->state = 1;
    }
    if (sel->cur == o->f4 || FUN_0020d058(&o->cursor) == 1) FUN_001896c4(o, 3);
    if (sel->v1c != 0x7fffffff && FUN_0020d018(&o->cursor, sel->cur, 1) == 0) {
        FUN_00096348(&item->sub);
        item->sub.v1();
        if (sel->cur == o->f4) FUN_0018b0a4(DAT_003ea858->f17c);
    } else if (sel->v14 != 0x7fffffff || sel->v18 != 0x7fffffff) {
        FUN_0009635c(&item->sub);
        item->sub.v1();
    }
    if (FUN_0020d184(cur, sel) != 0) {
        FUN_0020d090(&o->cursor);
    } else if (cur->b7 == 0 || sel->b7 == 0) {
        FUN_001896a8(o, 0);
        FUN_001896c4(o, 1);
    }
    sel->Reset();
    int link = 0;
    if (item->link != 0) link = item->link->f1b4;
    Item *e = FUN_00185db8(FUN_00177e98(), idx, o->f4, link);
    int flag = 0;
    Tab *t = FUN_00177d4c();
    int v;
    if (link >= 0 && link < 15) v = t->b[link]; else v = 1;
    if (v == 2) flag = 1;
    FUN_00189ea0(o, idx, e->b9 != 0, e->b10 != 0, flag);
    FUN_00189e1c(o, idx, e->b8 != 0);
    FUN_00189f74(o, link, o->f4, flag);
}
