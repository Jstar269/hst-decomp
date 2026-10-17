/* HSTMATCH module=EBOOT.BIN start=0x00092258 end=0x00092630 symbol=FUN_00092258 lang=c++ */
/* Hand-written reconstruction from the disassembly (restructured from the hstgen.py tag a3 candidate); exact match verified; names and types await human review. */
/* Matching idioms: the four state flags are `bool`s read from signed 4-bit field bits (`e->hi62 & 1`, `& 2`) and the second accumulates with `b2 |= e->hi62 & 1` (a `||` short-circuits); `if (b4 || (b1 && b3))` is one shared block; the loop counts go through an inline `Count(c)` ternary in a `while` condition (rotated test with entry jump); the per-index value is `v9 != 0 && !(flags & 2)` (the `^ 1` and bool-variable spellings add an extra sltu/andi); `(v9 != 0) ^ 1` is kept for the later call (sltu;xori). Names provisional. */
struct List;
struct Ctrl {
    char pad0[8];
    List *list;
};
struct Item {
    char pad0[0x8c];
    Ctrl *ctrl;
    char pad90[0x1b4 - 0x90];
    unsigned id;
};
struct Ent {
    char pad0[0x62];
    signed char lo62 : 4;
    signed char hi62 : 4;
    char pad63;
    signed char lo64 : 4;
};
struct Reg;
struct Self {
    char pad0[0x50];
    Item *f50;
    Item *f54;
    Item *f58;
    Item *f5c;
    Item *f60;
    char pad64[0x74 - 0x64];
    char flags;
    unsigned char f75;
};
extern "C" {
extern Reg *DAT_00338b08;
extern char DAT_002d2908[];
extern char DAT_002d291c[];
Ent *FUN_000d8c24(Reg *, int, unsigned);
unsigned FUN_0002fe08(List *);
int FUN_0002fe80(List *, char *);
void FUN_00054464(Ctrl *, int, int, int, int);
}
static inline int Count(Ctrl *c)
{
    return c->list == 0 ? 0 : FUN_0002fe08(c->list);
}
static inline int Find(List *l, char *name)
{
    if (l != 0)
        return FUN_0002fe80(l, name);
    return -1;
}
extern "C" void FUN_00092258(Self *s)
{
    bool b1 = false;
    bool b2 = false;
    bool b3 = false;
    bool b4 = false;
    s->flags = s->flags & 0x20;
    if (s->f54 != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 1, s->f54->id);
        if (e != 0)
            b1 = e->hi62 & 1;
    }
    if (s->f5c != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 3, s->f5c->id);
        if (e != 0)
            b2 = e->hi62 & 1;
    }
    if (s->f60 != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 4, s->f60->id);
        if (e != 0)
            b2 |= e->hi62 & 1;
    }
    if (s->f58 != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 2, s->f58->id);
        if (e != 0) {
            b3 = e->hi62 & 1;
            b4 = e->hi62 & 2;
        }
    }
    if (b4 || (b1 && b3)) {
        b1 = false;
        s->flags |= 2;
    }
    if (b1 || b3) {
        if (b2)
            s->flags |= 8;
    }
    if (s->f50 != 0 && s->f50->ctrl != 0 && s->f54 != 0 && s->f54->ctrl != 0) {
        unsigned v9 = s->f75;
        Ent *e = FUN_000d8c24(DAT_00338b08, 1, s->f54->id);
        if (e != 0) {
            if (e->lo64 != 1)
                v9 = 0;
        }
        int idx = Find(s->f50->ctrl->list, DAT_002d2908);
        if (idx >= 0) {
            if (v9 != 0 && b2) {
                b2 = false;
                Ctrl *c = s->f50->ctrl;
                int i = 0;
                while (i < Count(c)) {
                    FUN_00054464(c, -1, i, i == idx, 0);
                    i++;
                }
            } else {
                Ctrl *c = s->f50->ctrl;
                int i = 0;
                while (i < Count(c)) {
                    int v = 1;
                    if (i == idx)
                        v = v9 != 0 && !(s->flags & 2);
                    FUN_00054464(c, -1, i, v, 0);
                    i++;
                }
            }
        }
        idx = Find(s->f54->ctrl->list, DAT_002d2908);
        if (idx >= 0)
            FUN_00054464(s->f54->ctrl, -1, idx, (v9 != 0) ^ 1, 0);
        idx = Find(s->f54->ctrl->list, DAT_002d291c);
        if (idx >= 0)
            FUN_00054464(s->f54->ctrl, -1, idx, v9, 0);
    }
    if (b1 || b2 || b3)
        s->flags |= 1;
}
