/* HSTMATCH module=hstp_trans_main.prx start=0x00146eb4 end=0x0014726c symbol=FUN_00146eb4 lang=c++ */
/* Clone of src/eboot/collect_best_score_0013b868.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: NOTE is a macro (an inline function hoists `move a0,s1` above the null test), the three list walks fetch their element through static inline accessors taking an unsigned index while the counter is a plain int (keeps retail's per-pass `sll`, no strength reduction), Ready() is the inline scan on the embedded Anim object at +0x1d0 (plain `last`), the player branch is `A && !Ready ... else if (f3d8 != 0 && !Ready && kind in {6,1,7,8}) ... else if (flag) ...`; names and types await human review. */
struct Obj8 {
    char pad[8];
    float f8;
};
struct Entry {
    Obj8 **ptr;
    char pad[0x10 - 4];
    float f10;
    char pad1[0x34 - 0x14];
};
struct Item {
    char pad0[0x260];
    int f260;
};
struct Item2 {
    char pad0[0x454];
    int f454;
};
struct Anim {
    char pad0[0xf4];
    Entry ent[1];
    char pad0b[0x158 - 0xf4 - 0x34];
    int first;
    int last;
};
struct Pl {
    char pad0[0x1d0];
    Anim anim;
    char pad1[0x3d0 - 0x1d0 - 0x160];
    int kind;
    char pad2[0x3d8 - 0x3d4];
    unsigned char f3d8;
    char pad3[0x3dc - 0x3d9];
    int f3dc;
};
struct Game {
    char pad0[0x188];
    Pl **players;
    unsigned nplayers;
    char pad1[0x1398 - 0x190];
    Item **items;
    unsigned nitems;
    char padx[0x13b0 - 0x13a0];
    Item2 **items2;
    unsigned nitems2;
    char pad2[0x145c - 0x13b8];
    int best;
    char pad3[0x14b8 - 0x1460];
    unsigned char f14b8;
    unsigned char f14b9;
};
extern "C" {
int FUN_0025136c(Item *);
int FUN_002593ec(Item2 *, int *);
int FUN_0014726c(Game *, int, int);
}

/* score note: the out pointer is tested BEFORE the arguments are evaluated (an inline function evaluates its arguments first) */
#define NOTE(G, OUT, A, B)     do {         if ((OUT) != 0) {             int v_ = FUN_0014726c((G), (A), (B));             *(OUT) = v_;             if ((G)->best < v_) {                 (G)->best = v_;             }         }     } while (0)

static inline float Level(Entry *e)
{
    return e->ptr != 0 ? (*e->ptr)->f8 : 0.0f;
}

static inline bool Ready(Anim *p)
{
    int i = p->first;
    if (i <= p->last) {
        do {
            float t = Level(&p->ent[i]);
            if (p->ent[i].f10 < t) {
                return false;
            }
            i++;
        } while (i <= p->last);
    }
    return true;
}

static inline Item *ItemAt(Game *g, unsigned i)
{
    return g->items[i];
}
static inline Item2 *Item2At(Game *g, unsigned i)
{
    return g->items2[i];
}
static inline Pl *PlayerAt(Game *g, unsigned i)
{
    return g->players[i];
}

extern "C" int FUN_00146eb4(Game *g, int *out)
{
    int i = 0;
    if (g->nitems != 0) {
        do {
            if (FUN_0025136c(ItemAt(g, i)) != 0) {
                NOTE(g, out, ItemAt(g, i)->f260, 1);
            }
            i++;
        } while (i < g->nitems);
    }
    i = 0;
    if (g->nitems2 != 0) {
        do {
            int q;
            if (FUN_002593ec(Item2At(g, i), &q) != 0) {
                NOTE(g, out, Item2At(g, i)->f454, q);
            }
            i++;
        } while (i < g->nitems2);
    }
    i = 0;
    if (g->nplayers != 0) {
        do {
            Pl *p = PlayerAt(g, i);
            Anim *an = &p->anim;
            if (p->f3dc == 2 && (unsigned)(p->kind - 4) < 2 && p->f3d8 != 0 && !Ready(an)) {
                NOTE(g, out, p->kind + 200, 2);
            } else if (p->f3d8 != 0 && !Ready(an) && (p->kind == 6 || p->kind == 1 || (unsigned)(p->kind - 7) < 2)) {
                NOTE(g, out, p->kind + 200, 1);
            } else {
                if (g->f14b9 != 0) {
                    NOTE(g, out, p->kind + 200, 1);
                }
            }
            i++;
        } while (i < g->nplayers);
    }
    if (g->f14b8 != 0) {
        NOTE(g, out, 300, 1);
    }
    int best = g->best;
    if (best > 0) {
        if (out != 0) {
            *out = best;
        }
        return 1;
    }
    return 0;
}
