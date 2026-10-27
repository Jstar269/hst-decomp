/* HSTMATCH module=EBOOT.BIN start=0x000ec6c8 end=0x000ecae4 symbol=FUN_000ec6c8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane ol3 near miss reworked); exact match verified; names and types await human review. Entry loop uses the pointer-wrapper iterator (free operator!= as !(a == b), begin() const, end() non-const) as in 0x000ecae4, with the body working on Entry *p = &*e. */
struct Vec4 {
    float x, y, z, w;
    Vec4 &operator=(const Vec4 &o) { float a = o.x; float b = o.y; float c = o.z; float d = o.w; w = d; z = c; y = b; x = a; return *this; }
} __attribute__((aligned(16)));
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
template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
    T &operator*() const { return *p_; }
    T *operator->() const { return p_; }
    It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }
template <class T> struct Vec {
    T *data_;
    unsigned size_;
    It<T> begin() const { return It<T>(data_); }
    It<T> end() { return It<T>(data_ + size_); }
};
struct Owner {
    char pad[0x3c];
    float alpha;
    void *tbl[6];
    Vec<Entry> items;
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
double FUN_00020f5c(float);
double FUN_00021748(double, double);
float FUN_000223a0(double);
void FUN_000ed08c(Owner *);
extern float DAT_002d6c84;
}

struct Less {
    bool operator()(const float &a, const float &b) const { return a < b; }
};
static inline const float &Max(const float &a, const float &b, Less cmp = Less())
{
    return cmp(a, b) ? b : a;
}

extern "C" void FUN_000ec6c8(Owner *self)
{
    for (It<Entry> e = self->items.begin(); e != self->items.end(); ++e) {
        Entry *p = &*e;
        if (p->kind == 6)
            continue;
        switch (p->zero) {
        case 0:
            if (p->arg > 0) {
                if (--p->arg == 0)
                    p->zero = 1;
            }
            break;
        case 1:

            float a;
            float c;
            if (FUN_000ca4a4() == 1 && p->kind < 4) {
                c = 128.0f;
                a = FUN_000223a0(FUN_00021748(1.125, FUN_00020f5c(p->one * 32.0f)));
            } else if (p->kind == 5) {
                a = p->one * 32.0f * 2.0f;
                c = 128.0f;
            } else if (p->kind == 4) {
                c = 128.0f;
                a = p->one * self->alpha;
            } else {
                c = 128.0f;
                a = FUN_000223a0(FUN_00021748(1.125, FUN_00020f5c(p->one * 32.0f)));
            }
            Batch *b = p->batch;
            p->one -= 0.1f;
            p->one = Max(p->one, DAT_002d6c84);
            if (p->one <= 0.0f) {
                p->kind = 6;
            } else {
                FUN_0005a650(b);
                float aa = a * 1.9921875f;
                for (int i = 0; i < 4; i++) {
                    b->buf[b->idx][i].u = DAT_002c07b0[i].x;
                    b->buf[b->idx][i].v = DAT_002c07b0[i].y;
                    b->buf[b->idx][i].q = DAT_002c07b0[i].z;
                    b->buf[b->idx][i].x = DAT_002c07f0[i].x;
                    b->buf[b->idx][i].y = DAT_002c07f0[i].y;
                    b->buf[b->idx][i].z = DAT_002c07f0[i].z;
                    b->buf[b->idx][i].r = c;
                    b->buf[b->idx][i].g = c;
                    b->buf[b->idx][i].b = c;
                    b->buf[b->idx][i].a = aa;
                }
                FUN_0005a670(b, 4);
            }
            break;
        }
    }
    FUN_000ed08c(self);
}
