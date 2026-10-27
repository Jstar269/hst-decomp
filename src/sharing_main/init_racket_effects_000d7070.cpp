/* HSTMATCH module=hstp_trans_main.prx start=0x000d7070 end=0x000d738c symbol=FUN_000d7070 lang=c++ data=0x0037d148 */
/* Hand-written reconstruction (port of src/eboot/init_racket_effects_000d3414.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Tag {};
struct Obj;
struct Slot {
    int a, b, c, d;
};
struct PtrVec;
extern "C" void FUN_0007021c(PtrVec *, Obj *const *, Tag);
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
            FUN_0007021c(this, &x, Tag());
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
extern Globals *DAT_003e19f0;
void *FUN_00000bcc(unsigned);
Obj *FUN_00051908(void *, const char *, int);
void FUN_000d934c(SlotVec *, unsigned, Slot *, Tag);
void FUN_000d933c(SlotVec *, unsigned, Tag);
void *FUN_00054098(void *);
void *FUN_0005697c(void *);
void FUN_0005427c(void *, const char *, const char *, int, int, int, int);
void FUN_00056a58(void *, const char *, int);
int FUN_0002fea8(void *, const char *);
void FUN_00058090(VObj *, int, void *, int);
}

static inline void Resize4(SlotVec *vec)
{
    unsigned n = vec->size;
    if (n < 4) {
        Slot x;
        x.a = -1;
        x.b = -1;
        x.d = 0;
        FUN_000d934c(vec, 4 - n, &x, Tag());
    } else if (4 < n) {
        FUN_000d933c(vec, n - 4, Tag());
    }
}
static inline void Fill(Self *self, int i, Slot &cur)
{
    cur.a = -1;
    cur.b = -1;
    cur.d = 0;
    self->slots.At(i) = cur;
}

extern "C" void FUN_000d7070(Self *self)
{
    static const char *names[1] = {"data/menu/game_eff/player_effect/effect_racket"};
    Obj *o;
    Slot cur;
    unsigned j = 0;
    do {
        Obj *mem = (Obj *)FUN_00000bcc(0x48);
        if (mem)
            mem = FUN_00051908(mem, names[j], 0);
        o = mem;
        self->objs.push_back(o, Tag());
    } while (++j < 1);

    Resize4(&self->slots);
    void *m1 = FUN_00000bcc(0x30);
    if (m1)
        m1 = FUN_00054098(m1);
    self->f7a4 = m1;
    void *m2 = FUN_00000bcc(0x10);
    if (m2)
        m2 = FUN_0005697c(m2);
    self->f7a8 = m2;
    FUN_0005427c(self->f7a4, "data/menu/game_eff/racket_kiseki/racket_kiseki02.i3r", "data/menu/game_eff/racket_kiseki/", 0, 0, 0, 0);
    FUN_00056a58(self->f7a8, "data/menu/game_eff/racket_kiseki/racket_kiseki02.i3m", 0);
    for (int i = 0; i < 4; i++) {
        Player *pl = DAT_003e19f0->tbl[i];
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
                    int e0 = nd ? FUN_0002fea8(nd, "node_eff00") : -1;
                    nd = r->f8c->f8;
                    int e1 = nd ? FUN_0002fea8(nd, "node_eff01") : -1;
                    nd = r->f8c->f8;
                    cur.a = e0;
                    cur.b = e1;
                    cur.c = nd ? FUN_0002fea8(nd, "node_hit") : -1;
                    cur.d = 0;
                    self->slots.At(i) = cur;
                    self->slots.At(i).d = 0;
                    self->elems[i].o.v1(self->f7a4);
                    FUN_00058090(&self->elems[i].o, 0, self->f7a8, 0);
                    self->flags[i] = 0;
                }
            }
        }
    }
}
