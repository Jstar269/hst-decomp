/* HSTMATCH module=EBOOT.BIN start=0x000a7ee0 end=0x000a8080 symbol=FUN_000a7ee0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

struct Elem {
    int id;
    unsigned char flag;
    int unk8;
    Vec4 v;
};

struct ElemList {
    struct Elem *data;
    int count;
};

/* Context holding the list of candidate elements and the index to resume from. */
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

/* Scans the context's element list from its index for the first flagged element that passes the range checks; copies it to out and returns 1. */
int FUN_000a7ee0(struct Obj *obj, struct Elem *out, float limit,
                 struct Ctx *ctx, int id_offset)
{
    int i;

    struct ElemList *list = &ctx->list;
    i = ctx->idx;
    if (i < ctx->list.count) {
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
            e.unk8 = p->unk8;
            e.v = p->v;
            if (e.flag != 0
                && e.v.z * obj->rate < limit
                && e.v.y >= -(0.95f * FUN_000b3c68(obj)->range * 0.01f)
                && FUN_000a8080(obj, &e.v, e.id + id_offset) >= 0) {
                out->id = e.id;
                out->flag = e.flag;
                out->unk8 = e.unk8;
                out->v = e.v;
                return 1;
            }
            i++;
        } while (i < list->count);
    }
    return 0;
}
