/* HSTMATCH module=EBOOT.BIN start=0x000ecbf0 end=0x000ecfbc symbol=FUN_000ecbf0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float v[4];
} __attribute__((aligned(16)));
struct FrameTag {};
static inline void TagHelper(FrameTag = FrameTag()) {}
struct Mat {
    Vec4 r[4];
};
struct Vert {
    unsigned char r, g, b, a;
    float x, y, z;
    float u, v, q;
};
struct Batch {
    char pad[0x54];
    int idx;
    char pad58[0xc];
    Vert *buf[2];
};
struct Entry {
    Mat m;
    Batch *batch;
    unsigned kind;
    float scale;
    int arg;
    int zero;
    float one;
    char pad58[8];
};
struct Owner {
    char pad[0x3c];
    float alpha;
    void *tbl[6];
    Entry *base;
    int count;
    int pad60;
    Entry *cur;
};
extern "C" {
extern Vec4 DAT_002c07b0[4];
extern Vec4 DAT_002c07f0[4];
Vec4 *FUN_00022498(Vec4 *, const Vec4 *, float);
void FUN_000513a0(void *, int);
int FUN_000ca4a4(void);
void FUN_0005a650(Batch *);
void FUN_0005a670(Batch *, int);
}

extern "C" void FUN_000ecbf0(Owner *self, unsigned kind, float scale, const Mat *m, int arg, int opt, float alpha)
{
    TagHelper();
    Entry *e = self->cur;
    e->kind = kind;
    e->scale = scale;
    e->m.r[0] = m->r[0];
    e->m.r[1] = m->r[1];
    e->m.r[2] = m->r[2];
    e->m.r[3] = m->r[3];
    FUN_00022498(&e->m.r[0], &e->m.r[0], scale);
    FUN_00022498(&e->m.r[1], &e->m.r[1], scale);
    FUN_00022498(&e->m.r[2], &e->m.r[2], scale);
    e->m.r[3].v[3] = 1.0f;
    e->arg = arg;
    e->zero = 0;
    e->one = 1.0f;
    self->alpha = alpha;
    FUN_000513a0(self->tbl[e->kind], opt);
    float a;
    float c;
    if (FUN_000ca4a4() == 1 && kind < 4) {
        c = 128.0f;
        a = 36.0f;
    } else if (kind == 5) {
        c = 128.0f;
        a = 64.0f;
    } else if (kind == 4) {
        a = self->alpha;
        c = 128.0f;
    } else {
        c = 128.0f;
        a = 36.0f;
    }
    Batch *b = e->batch;
    FUN_0005a650(b);
    float aa = a * 1.9921875f;
    for (int i = 0; i < 4; i++) {
        b->buf[b->idx][i].u = DAT_002c07b0[i].v[0];
        b->buf[b->idx][i].v = DAT_002c07b0[i].v[1];
        b->buf[b->idx][i].q = DAT_002c07b0[i].v[2];
        b->buf[b->idx][i].x = DAT_002c07f0[i].v[0];
        b->buf[b->idx][i].y = DAT_002c07f0[i].v[1];
        b->buf[b->idx][i].z = DAT_002c07f0[i].v[2];
        b->buf[b->idx][i].r = c;
        b->buf[b->idx][i].g = c;
        b->buf[b->idx][i].b = c;
        b->buf[b->idx][i].a = aa;
    }
    FUN_0005a670(b, 4);
    Entry *end = self->base + self->count;
    if (++self->cur == end)
        self->cur = self->base;
}
