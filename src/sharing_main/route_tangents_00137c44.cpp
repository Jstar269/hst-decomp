/* HSTMATCH module=hstp_trans_main.prx start=0x00137c44 end=0x00137e00 symbol=FUN_00137c44 lang=c++ */
/* Clone of src/eboot/route_tangents_0012c7d8.cpp (hstclone.py tag lnm2c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r[4];
};

struct Route {
    char pad00[0x40];
    void *f40;
    char pad44[0x2c];
    Vec4 *pts;          // 0x70
    char pad74[8];
    unsigned count;     // 0x7c
    unsigned idx;       // 0x80
    Vec4 *tangents;     // 0x84
    char pad88[0xc];
    unsigned char flag; // 0x94
};

extern "C" {
    Vec4 *FUN_0002245c(Vec4 *out, const Vec4 *a, const Vec4 *b);
    Vec4 *FUN_000224c0(float s, Vec4 *out, const Vec4 *in);
    void *FUN_000ec4e0(void *m, const Vec4 *p0, const Vec4 *p1, const Vec4 *t0, const Vec4 *t1);
    void FUN_000ec4d0(Route *r, void *f40, void *m);

    void FUN_00137c44(Route *r);
}

static inline Vec4 Scale(float k, const Vec4 &v) { Vec4 o; FUN_000224c0(k, &o, &v); return o; }

static inline void Hermite(Route *r, const Vec4 *p_curr, const Vec4 *p_next,
                           const Vec4 *t_next, const Vec4 *t_curr)
{
    Mat4 m;
    void *res = FUN_000ec4e0(&m, p_curr, p_next, t_curr, t_next);
    FUN_000ec4d0(r, r->f40, res);
}

void FUN_00137c44(Route *r) {
    if (r->flag != 0) {
        if (r->idx + 1 < r->count) {
            Vec4 p_curr;
            Vec4 p_next;
            Vec4 diff;
            Vec4 diff_tmp;

            p_curr = r->pts[r->idx];
            p_next = r->pts[r->idx + 1];

            FUN_0002245c(&diff_tmp, &p_next, &p_curr);
            diff = diff_tmp;

            if (r->idx == 0) {
                r->tangents[r->idx] = diff;
            }

            if (r->idx + 1 == r->count - 1) {
                Vec4 *t = &r->tangents[r->idx + 1];
                t->x = 0.0f;
                t->y = 0.0f;
                t->z = 0.0f;
                t->w = 0.0f;
            } else {
                Vec4 scale_tmp = Scale(2.0f, diff);
                r->tangents[r->idx + 1] = scale_tmp;
            }

            Hermite(r, &p_curr, &p_next, &r->tangents[r->idx + 1], &r->tangents[r->idx]);
        }
        r->idx++;
    }
}
