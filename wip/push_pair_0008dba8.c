/* HSTMATCH module=EBOOT.BIN start=0x0008dba8 end=0x0008dd24 symbol=FUN_0008dba8 lang=c99 */
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

extern void FUN_0009103c(Vec *, Item *, char);

void FUN_0008dba8(int param_1, int param_2, unsigned char param_3, int param_4, float *param_5)
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
            p->v.x = item.v.x;
            p->v.y = item.v.y;
            p->v.z = item.v.z;
            p->v.w = item.v.w;
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
            p->v.x = item.v.x;
            p->v.y = item.v.y;
            p->v.z = item.v.z;
            p->v.w = item.v.w;
        }
        vec->count = vec->count + 1;
    } else {
        FUN_0009103c(vec, &item, 0);
    }
}
// near miss: 93/95 words, 46 differ. Shape is right (item at sp+0x10, vec temp at sp+0x30, both
// push_backs inlined with the `count < cap` test, the p != 0 check, count++ and the grow call).
// Open deltas: retail's frame is 0x50 (ours 0x40; 0x10 unexplained), the grow call's third
// argument is materialised as `move v0,zero; seb a2,v0` (a char-typed zero), and the second
// container's count is loaded into a0 rather than a1 (retail indexes +0xc/+0x10/+0x14 directly,
// ours keeps a `Vec *` local for it). Facts: Item is 0x20 bytes with b as UNSIGNED char at +4,
// c at +8, a 4-byte hole at +0xc and the vec4 at +0x10; count/cap compare UNSIGNED (sltu); the
// vec is copied into a V4 temp first and then field-by-field into the element (four separate
// assignments, not a struct copy -- a struct copy batches all four loads before the stores).
// near miss from lane fm6 (unreviewed)
