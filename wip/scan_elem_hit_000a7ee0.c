/* HSTMATCH module=EBOOT.BIN start=0x000a7ee0 end=0x000a8080 symbol=FUN_000a7ee0 lang=c99 */
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

struct Elem {
    int id;
    unsigned char flag;
    int c;
    Vec4 v;
};

struct ElemList {
    struct Elem *data;
    int count;
};

struct Ctx {
    char pad0[0x268];
    int idx;
    struct ElemList list;
};

struct Obj {
    char pad0[0x5a8];
    float rate;
};

struct Sub {
    char pad0[0x3c];
    float range;
};

extern struct Sub *FUN_000b3c68(struct Obj *);
extern int FUN_000a8080(struct Obj *, Vec4 *, int);

int FUN_000a7ee0(struct Obj *param_1, struct Elem *param_2, float param_3,
                 struct Ctx *param_4, int param_5)
{
    int i;

    i = param_4->idx;
    if (i < param_4->list.count) {
        struct ElemList *list = &param_4->list;
        do {
            unsigned k;
            struct Elem *p;
            struct Elem e;

            k = (unsigned)i;
            if ((unsigned)k >= (unsigned)list->count)
                k = list->count - 1;
            p = &list->data[k];
            e.id = p->id;
            e.flag = p->flag;
            e.c = p->c;
            e.v = p->v;
            if (e.flag != 0
                && e.v.z * param_1->rate < param_3
                && e.v.y >= -(0.95f * FUN_000b3c68(param_1)->range * 0.01f)
                && FUN_000a8080(param_1, &e.v, e.id + param_5) >= 0) {
                param_2->id = e.id;
                param_2->flag = e.flag;
                param_2->c = e.c;
                param_2->v = e.v;
                return 1;
            }
            i++;
        } while (i < list->count);
    }
    return 0;
}
// near miss: 104/104 words, only 2 differ - both the same prologue scheduling tie.
// Retail: `mov.s $f20,$f12; move s2,a3; beqz at,END; addiu s0,a2,620` (the param_5 copy BEFORE
// the branch, the &list pointer in the delay slot). Ours: `mov.s $f20,$f12; beqz at,END;
// move s2,a3; addiu s0,a2,620` - MWCC defers the a3 copy into the delay slot, which also shifts
// the branch offset by one word (0x4f vs 0x4e). Ruled out: `int adj = param_5;` + using adj, an
// initialised `int i = param_4->idx;`, `unsigned i`, and `if (count > i)`; also float param
// positions 2, 4 and 5 (3 differing) and 1/4/5 reordered (4-5 differing).
// Facts pinned for this function family:
//  * the element is a 0x20-byte struct { int id; unsigned char flag; int c; Vec4 v; } with Vec4
//    __attribute__((aligned(16))) so v lands at 0x10 and the 0xc hole is PADDING - the copies
//    must then be field-by-field (e.v = p->v gives the 4 lwc1 / 4 swc1 batch); a plain `e = *p`
//    or an unaligned Vec4 vectorises the first 16 bytes and breaks the copy block.
//  * the list is a {data,count} pair at ctx+0x26c/0x270 (`lw s1,616(a2)` is idx at 0x268), and the
//    pointer `&ctx->list` must be declared INSIDE the if-block: retail loads the count for the
//    entry test as `624(a2)` and inside the loop as `4(s0)`, i.e. the two access forms must NOT
//    CSE (that is worth exactly one word).
//  * the clamp is `unsigned k = i; if ((unsigned)k >= (unsigned)list->count) k = list->count - 1;`
//    -> `sltu v0,s1,v1; bnez v0,L; move a0,s1; addiu a0,v1,-1`. The ternary form gives a likely
//    branch (beqzl) instead, which costs 2 words.
//  * the second float test must read variable-first: `e.v.y >= -(0.95f * range * 0.01f)` gives
//    retail's `c.nge.s $f0,$f1; bc1t`; writing `-(...) <= e.v.y` gives `c.le.s; bc1f`.
//  * the float parameter belongs in f12 but must be THIRD in the source parameter list; the
//    parameter-copy order in the prologue follows that declaration order (Obj*, Elem*, float,
//    Ctx*, int).
// near miss from lane fm9 (unreviewed)
