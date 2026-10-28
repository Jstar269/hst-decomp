/* HSTMATCH module=EBOOT.BIN start=0x00058b78 end=0x00058d1c symbol=FUN_00058b78 lang=c++ */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
/* Rebuilds the 0x40-byte rows of the object at 0x160 from the Vec4 list at 0x16c: each row is the source
   vector scaled by x, y and z in turn, and rows whose element at 0x16c-elements index (the short at the front
   of the element's node) is valid are additionally multiplied by the component-wise reciprocal of the
   referenced vector (w stays 1). Only runs while the byte flag at 0x170 is set. Matching idiom: the two
   in-place scale calls go through the same small `Scale` wrapper the lane already uses elsewhere
   (0x00128f60), which is what orders the two strength-reduced byte offsets; written out in full the two
   induction variables land in the opposite s-registers. */
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Row {
    Vec4 r[4];
} Row;

typedef struct Node {
    short index;
} Node;

typedef struct Elem {
    Node *node;
    int pad[3];
} Elem;

typedef struct Model {
    char pad0[8];
    Elem *list;                 /* +8 */
} Model;

typedef struct Object {
    char pad0[0x8c];
    Model *model;               /* 0x8c */
    char pad90[0x160 - 0x90];
    Row *rows;                  /* 0x160: 0x40 bytes per row */
    char pad164[8];
    Vec4 *values;               /* 0x16c */
    unsigned char enabled;      /* 0x170 */
} Object;

extern "C" {
int FUN_0002fe08(void *);
Elem *FUN_0002e7a4(char *);
Vec4 *FUN_00022498(Vec4 *, const Vec4 *, float);
Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
}

static inline void Scale(Vec4 *v, float s) { FUN_00022498(v, v, s); }

extern "C" void FUN_00058b78(Object *self)
{
    Vec4 scale;
    Elem *elem;
    int n;

    if (self->enabled == 0)
        return;

    if (self->model->list != 0)
        n = FUN_0002fe08(self->model->list);
    else
        n = 0;

    elem = FUN_0002e7a4((char *)self->model->list + 16);

    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    scale.w = 1.0f;

    for (int i = 0; i < n; i++) {
        Scale(&self->rows[i].r[0], self->values[i].x);
        Scale(&self->rows[i].r[1], self->values[i].y);
        Scale(&self->rows[i].r[2], self->values[i].z);

        if (elem->node->index >= 0) {
            Vec4 *row = &self->values[elem->node->index];
            scale.x = 1.0f / row->x;
            scale.y = 1.0f / row->y;
            scale.z = 1.0f / row->z;
            FUN_00022450(&self->rows[i].r[0], &self->rows[i].r[0], &scale);
            FUN_00022450(&self->rows[i].r[1], &self->rows[i].r[1], &scale);
            FUN_00022450(&self->rows[i].r[2], &self->rows[i].r[2], &scale);
        }
        elem++;
    }
}
