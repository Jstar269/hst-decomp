/* HSTMATCH module=EBOOT.BIN start=0x0017c39c end=0x0017c6d4 symbol=FUN_0017c39c lang=c++ */
/* Clone of src/sharing_main/selection_state_update_00188a90.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the three cursor calls take `&o->cursor` through a void* prototype (a Cursor* argument is folded into the saved register that FUN_001fe9b4 uses, retail recomputes o+0x5c); FUN_00049094 receives `force` (zero on that path). */
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
int FUN_00049094(int);
void FUN_00094424(void *);
void FUN_00094438(void *);
Tab *FUN_0016bb88();
int FUN_0016bc70();
Item *FUN_001796c4(int, int, int, int);
void FUN_0017cfb4(Obj *, int);
void FUN_0017cfd0(Obj *, int);
void FUN_0017d728(Obj *, int, int);
void FUN_0017d7ac(Obj *, int, int, int, int);
void FUN_0017d880(Obj *, int, int, int);
void FUN_0017e9b0(int);
int FUN_001fe848(void *, int, int);
int FUN_001fe888(void *);
void FUN_001fe8c0(void *);
int FUN_001fe9b4(Cursor *, Sel *);
extern Glob *DAT_00341518;
}

extern "C" void FUN_0017c39c(Obj *o, int force)
{
    Cursor *cur = &o->cursor;
    Sel *sel = &o->sel;
    bool ok = false;
    if (force != 0) {
        ok = true;
    } else if (sel->b5 != 0 && sel->b6 != 0 && FUN_00049094(force) != 0) {
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
    if (sel->cur == o->f4 || FUN_001fe888(&o->cursor) == 1) FUN_0017cfd0(o, 3);
    if (sel->v1c != 0x7fffffff && FUN_001fe848(&o->cursor, sel->cur, 1) == 0) {
        FUN_00094424(&item->sub);
        item->sub.v1();
        if (sel->cur == o->f4) FUN_0017e9b0(DAT_00341518->f17c);
    } else if (sel->v14 != 0x7fffffff || sel->v18 != 0x7fffffff) {
        FUN_00094438(&item->sub);
        item->sub.v1();
    }
    if (FUN_001fe9b4(cur, sel) != 0) {
        FUN_001fe8c0(&o->cursor);
    } else if (cur->b7 == 0 || sel->b7 == 0) {
        FUN_0017cfb4(o, 0);
        FUN_0017cfd0(o, 1);
    }
    sel->Reset();
    int link = 0;
    if (item->link != 0) link = item->link->f1b4;
    Item *e = FUN_001796c4(FUN_0016bc70(), idx, o->f4, link);
    int flag = 0;
    Tab *t = FUN_0016bb88();
    int v;
    if (link >= 0 && link < 15) v = t->b[link]; else v = 1;
    if (v == 2) flag = 1;
    FUN_0017d7ac(o, idx, e->b9 != 0, e->b10 != 0, flag);
    FUN_0017d728(o, idx, e->b8 != 0);
    FUN_0017d880(o, link, o->f4, flag);
}
