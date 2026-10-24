/* HSTMATCH module=EBOOT.BIN start=0x000a7cec end=0x000a7ee0 symbol=FUN_000a7cec lang=c++ */
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
    char pad1[4];
    struct ElemList recent;
};

struct Obj {
    char pad0[0x5a8];
    float rate;
};

extern "C" int FUN_000a8080(struct Obj *, Vec4 *, int);

static inline const int &Max(const int &a, const int &b)
{
    return a < b ? b : a;
}

extern "C" int FUN_000a7cec(struct Obj *param_1, struct Elem *param_2, struct Ctx *param_4,
                             int param_5, int param_6, float param_3)
{
    int start;
    struct ElemList *list;
    float best;
    int found;

    start = param_4->idx;
    best = 3.4028235e+38f;
    found = 0;
    list = &param_4->list;
    if (param_4->recent.count > 0) {
        int k = 0;
        struct Elem *e;
        if (param_4->recent.count == 0)
            k = param_4->recent.count - 1;
        e = &param_4->recent.data[k];
        start = Max(start, e->id);
    }
    if (start < list->count) {
        do {
            struct Elem *p;
            if ((unsigned)start < (unsigned)list->count)
                p = &list->data[start];
            else
                p = &list->data[list->count - 1];
            struct Elem e;
            float d;

            e.id = p->id;
            e.flag = p->flag;
            e.c = p->c;
            e.v = p->v;
            if (e.flag != 0
                && e.v.z * param_1->rate < -2.0f
                && (d = e.v.y - param_3) > 0.0f
                && best > d
                && FUN_000a8080(param_1, &e.v, e.id + param_6) >= 0) {
                found = 1;
                param_2->id = e.id;
                param_2->flag = e.flag;
                param_2->c = e.c;
                param_2->v = e.v;
                best = d;
            }
            start++;
        } while (start < list->count);
    } else {
        found = 0;
    }
    return found;
}
// near miss: 124/125 words (one short), 82 differing.
// Structure: nearest-hit scan over the same 0x20-byte element as 0x000a7ee0. `start` is
// address-taken (sp+92) because of the Max() clamp, best starts at FLT_MAX (0x7f7fffff) and is
// updated with the distance d = e.v.y - t, found is the return value.
// Fixed along the way: `list = &param_4->list;` must be assigned AFTER best/found (that is what
// puts `addiu s0,a2,620` in the blez delay slot after `move s1,zero`); d must be computed INSIDE
// the && chain, after the z test (`(d = e.v.y - param_3) > 0.0f`), not before the flag test; the
// best test is `best > d` (retail `c.ngt.s $f20,$f22`); the recent-list index is an if, not a
// ternary (`int k = 0; if (count == 0) k = count - 1;` -> `bnez v0,L; move v1,zero; addiu`).
// Remaining two deltas, both in the loop head:
//  (1) the recent list's data pointer: retail reads it as `12(s0)` (i.e. &list + 0xc) while we
//      read `632(a2)` (ctx + 0x278). Same address; the difference is which base MWCC chose.
//      The recent list is exactly 0xc bytes after &list, so retail addressed it off the live
//      list pointer. Tried: a 12-byte ElemList ({data,count,cap}) so `recent` is at list+0xc -
//      still a2-relative.
//  (2) the clamp: retail is `sltu v0,a0,v1; bnezl v0,JOIN; lw v0,0(s0); addiu a0,v1,-1;
//      lw v0,0(s0)` - a likely branch, the base load in its delay slot AND again on the false
//      path, with ONE shared sll/addu at the join. All our spellings either use beqzl with a
//      single base load (index ternary, 120/125) or duplicate the sll (ternary/if over two
//      `&list->data[...]` addresses, 124/125). The condition `(unsigned)start >=
//      (unsigned)list->count` is the one that gets `sltu v0` into the right register (plain
//      bnez instead of bnezl).
// Also: this function needs a .cpp file and extern "C" on both the target and FUN_000a8080 -
// Max(const int&,const int&) is C++.
// near miss from lane fm9 (unreviewed)
