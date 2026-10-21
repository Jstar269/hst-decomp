/* HSTMATCH module=EBOOT.BIN start=0x000d3414 end=0x000d3730 symbol=FUN_000d3414 lang=c++ data=0x002d6660 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the one-entry name table is a function-static pointer array (anonymous .data placed with data=0x2d6660: string, table, then the call strings in order of use); the one-trip loop is `unsigned j = 0; do {...} while (++j < 1);` (a `for` is removed, `do` keeps retail rolled loop); the pointer push_back is an inline member taking an unused empty Tag (`data[size - 1] = x`); the slot vector is indexed through an inline `At(unsigned)` (an open `data[i]` gets strength-reduced to i*16, retail recomputes `sll`); the loop-carried `Slot cur` is never initialised so its field c is read from its stack slot into s3 before the loop; the resize-to-4 is an inline helper whose temporary `Slot x` sits below the caller tag slots; names and types await human review. */
struct Tag {};
struct Obj;
struct Slot {
    int a, b, c, d;
};
struct PtrVec;
extern "C" void FUN_0006ea5c(PtrVec *, Obj *const *, Tag);
struct PtrVec {
    Obj **data;
    unsigned size;
    unsigned cap;
    void push_back(Obj *const &x, Tag)
    {
        if (size < cap) {
            size++;
            data[size - 1] = x;
        } else {
            FUN_0006ea5c(this, &x, Tag());
        }
    }
};
struct SlotVec {
    Slot *data;
    unsigned size;
    unsigned cap;
    Slot &At(unsigned i) { return data[i]; }
};
struct Handle {
    char pad0[8];
    void *f8;
};
struct Root {
    char pad0[0x8c];
    Handle *f8c;
};
struct Mid {
    char pad0[100];
    Root *f64;
};
struct Player {
    char pad0[0x5bc];
    Mid *f5bc;
};
struct Globals {
    char pad0[0x70];
    Player *tbl[4];
};
struct VObj {
    virtual void v0();
    virtual void v1(void *);
};
struct Elem {
    VObj o;
    char pad[0x1ac];
};
struct Self {
    char pad0[0x3c];
    PtrVec objs;
    SlotVec slots;
    char pad54[0xe0 - 0x54];
    Elem elems[4];
    char flags[4];
    void *f7a4;
    void *f7a8;
};

extern "C" {
extern Globals *DAT_003386b0;
void *FUN_00000bcc(unsigned);
Obj *FUN_00050ff4(void *, const char *, int);
void FUN_000d565c(SlotVec *, unsigned, Slot *, Tag);
void FUN_000d564c(SlotVec *, unsigned, Tag);
void *FUN_000535d8(void *);
void *FUN_00055dd0(void *);
void FUN_000537bc(void *, const char *, const char *, int, int, int, int);
void FUN_00055eac(void *, const char *, int);
int FUN_0002fe80(void *, const char *);
void FUN_0005743c(VObj *, int, void *, int);
}

static inline void Resize4(SlotVec *vec)
{
    unsigned n = vec->size;
    if (n < 4) {
        Slot x;
        x.a = -1;
        x.b = -1;
        x.d = 0;
        FUN_000d565c(vec, 4 - n, &x, Tag());
    } else if (4 < n) {
        FUN_000d564c(vec, n - 4, Tag());
    }
}
static inline void Fill(Self *self, int i, Slot &cur)
{
    cur.a = -1;
    cur.b = -1;
    cur.d = 0;
    self->slots.At(i) = cur;
}

extern "C" void FUN_000d3414(Self *self)
{
    static const char *names[1] = {"data/menu/game_eff/player_effect/effect_racket"};
    Obj *o;
    Slot cur;
    unsigned j = 0;
    do {
        Obj *mem = (Obj *)FUN_00000bcc(0x48);
        if (mem)
            mem = FUN_00050ff4(mem, names[j], 0);
        o = mem;
        self->objs.push_back(o, Tag());
    } while (++j < 1);

    Resize4(&self->slots);
    void *m1 = FUN_00000bcc(0x30);
    if (m1)
        m1 = FUN_000535d8(m1);
    self->f7a4 = m1;
    void *m2 = FUN_00000bcc(0x10);
    if (m2)
        m2 = FUN_00055dd0(m2);
    self->f7a8 = m2;
    FUN_000537bc(self->f7a4, "data/menu/game_eff/racket_kiseki/racket_kiseki02.i3r", "data/menu/game_eff/racket_kiseki/", 0, 0, 0, 0);
    FUN_00055eac(self->f7a8, "data/menu/game_eff/racket_kiseki/racket_kiseki02.i3m", 0);
    for (int i = 0; i < 4; i++) {
        Player *pl = DAT_003386b0->tbl[i];
        if (pl == 0) {
            Fill(self, i, cur);
        } else {
            Mid *m = pl->f5bc;
            if (m == 0) {
                Fill(self, i, cur);
            } else {
                Root *r = m->f64;
                if (r == 0) {
                    Fill(self, i, cur);
                } else {
                    void *nd = r->f8c->f8;
                    int e0 = nd ? FUN_0002fe80(nd, "node_eff00") : -1;
                    nd = r->f8c->f8;
                    int e1 = nd ? FUN_0002fe80(nd, "node_eff01") : -1;
                    nd = r->f8c->f8;
                    cur.a = e0;
                    cur.b = e1;
                    cur.c = nd ? FUN_0002fe80(nd, "node_hit") : -1;
                    cur.d = 0;
                    self->slots.At(i) = cur;
                    self->slots.At(i).d = 0;
                    self->elems[i].o.v1(self->f7a4);
                    FUN_0005743c(&self->elems[i].o, 0, self->f7a8, 0);
                    self->flags[i] = 0;
                }
            }
        }
    }
}
