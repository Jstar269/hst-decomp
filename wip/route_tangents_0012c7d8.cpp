/* HSTMATCH module=EBOOT.BIN start=0x0012c7d8 end=0x0012c994 symbol=FUN_0012c7d8 lang=c++ */

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
    Vec4 *FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
    Vec4 *FUN_00022498(float s, Vec4 *out, const Vec4 *in);
    void *FUN_000e74e4(void *m, const Vec4 *p0, const Vec4 *p1, const Vec4 *t0, const Vec4 *t1);
    void FUN_000e74d4(Route *r, void *f40, void *m);

    void FUN_0012c7d8(Route *r);
}

static inline Vec4 Scale(float k, const Vec4 &v) { Vec4 o; FUN_00022498(k, &o, &v); return o; }

void FUN_0012c7d8(Route *r) {
    if (r->flag != 0) {
        if (r->idx + 1 < r->count) {
            Vec4 p_curr;
            Vec4 p_next;
            Vec4 diff;
            Vec4 diff_tmp;
            Mat4 m;

            p_curr = r->pts[r->idx];
            p_next = r->pts[r->idx + 1];

            FUN_00022434(&diff_tmp, &p_next, &p_curr);
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
                r->tangents[r->idx + 1] = Scale(2.0f, diff);
            }

            void *res = FUN_000e74e4(&m, &p_curr, &p_next, &r->tangents[r->idx], &r->tangents[r->idx + 1]);
            FUN_000e74d4(r, r->f40, res);
        }
        r->idx++;
    }
}
// near miss from lane ag4 (unreviewed); lane nx1: 9 -> 6 words.
// FIXED (nx1): retail's batched copy into tangents[idx+1] (lwc1 +4,+8,+12,+0 then 4 swc1) = inline
// `Vec4 Scale(float k, const Vec4 &v) { Vec4 o; FUN_00022498(k, &o, &v); return o; }` assigned directly.
// LEFT (6 words): stack slots only. Retail: p_curr 144, p_next 128, diff 112, diff temp 96, scale temp 80, Mat4 m 16.
// Ours: the Scale temp lands at 16 (below everything) and named m at 32. Inline-body temps always go below named locals.
// Lead (g16 in lane nx1): declaring the VFPU helpers as sret (`Vec4 FUN_00022434(const Vec4*,const Vec4*)`,
// `Vec4 FUN_00022498(float,const Vec4*)`, same registers) plus m inside an inline Hermite(...) helper gives retail's exact
// slot layout, but then the tangents copy is per-field pairs again (9 words; removing Vec4's user ctors did not batch it).
// Ruled out: m in an inner block; Mat4().Ptr() temporary; Sub inline for diff (slots reorder, 11-16);
// inline Build(a,b,c,d) (args evaluated right to left, 11); `*FUN_00022498(..)` copy (13); Vec4 without ctors (9).
// improved by lane nx1 (unreviewed): 9 -> 6 differing words
