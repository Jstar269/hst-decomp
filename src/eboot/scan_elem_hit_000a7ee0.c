/* HSTMATCH module=EBOOT.BIN start=0x000a7ee0 end=0x000a8080 symbol=FUN_000a7ee0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

    struct ElemList *list = &param_4->list;
    i = param_4->idx;
    if (i < param_4->list.count) {
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
