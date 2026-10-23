/* HSTMATCH module=EBOOT.BIN start=0x0008dba8 end=0x0008dd24 symbol=FUN_0008dba8 lang=c++ */
extern "C" {
typedef struct {
    float x;
    float y;
    float z;
    float w;
} V4;

typedef struct {
    int a;
    unsigned char b;
    int c;
    int pad;
    V4 v;
} Item;

typedef struct {
    Item *items;
    unsigned int count;
    unsigned int cap;
} Vec;

extern void FUN_0009103c(Vec *, Item *, int);
}

extern "C" void FUN_0008dba8(int param_1, int param_2, unsigned char param_3, int param_4, float *param_5)
{
    V4 v;
    Item item;
    Item *p;
    Vec *vec;

    v = *(V4 *)param_5;
    item.v = v;
    item.a = param_2;
    item.b = param_3;
    item.c = param_4;
    vec = (Vec *)param_1;
    if (vec->count < vec->cap) {
        p = &vec->items[vec->count];
        if (p != 0) {
            p->a = item.a;
            p->b = item.b;
            p->c = item.c;
            p->v = item.v;
        }
        vec->count = vec->count + 1;
    } else {
        FUN_0009103c(vec, &item, 0);
    }
    if (param_4 != 1)
        return;
    vec = (Vec *)(param_1 + 0xc);
    if (vec->count < vec->cap) {
        p = &vec->items[vec->count];
        if (p != 0) {
            p->a = item.a;
            p->b = item.b;
            p->c = item.c;
            p->v = item.v;
        }
        vec->count = vec->count + 1;
    } else {
        FUN_0009103c(vec, &item, 0);
    }
}
// near miss from lane fm6 (unreviewed)
