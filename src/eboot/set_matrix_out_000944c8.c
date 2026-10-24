/* HSTMATCH module=EBOOT.BIN start=0x000944c8 end=0x00094690 symbol=FUN_000944c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the 16-float matrix copy is two 8-trip loops (a single 16-trip loop is unrolled 8x and stays rolled); the else-arm clear of out->m is int stores (retail uses sw zero, not swc1); the matrix index mapping (0 -> -1) is an inline helper with an early-return "if (a != 0) return F(a,b); return -1;". Names provisional. */
extern int FUN_0002fe80(int, int);

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    float f[16];
} Mat;

typedef struct {
    Vec4 v;
    Vec4 m;
    int idx;
    int i;
} Out;

typedef struct {
    char pad[0x8c];
    int *src;
    char pad2[0x160 - 0x90];
    char *base;
} Ctx;

extern void FUN_00094690(Out *, Vec4 *, Vec4 *, Vec4 *);

static inline int Map(int a, int b)
{
    if (a != 0)
        return FUN_0002fe80(a, b);
    return -1;
}

void FUN_000944c8(Out *out, Vec4 *in, Ctx *ctx)
{
    Vec4 v;
    Mat tmp;
    int idx;
    int i;

    v = *in;
    if (v.w == 0.0f) {
        out->m.x = 0.0f;
        out->m.y = 0.0f;
        out->m.z = 0.0f;
        out->m.w = 0.0f;
    } else if (v.w == -1.0f) {
        if (out->m.w == 0.0f) {
            out->m.x = 0.0f;
            out->m.y = 0.0f;
            out->m.z = 0.0f;
            v.w = 0.0f;
            out->m.w = 0.0f;
        }
    } else {
        v.w = 1.0f;
        if (out->v.w == 0.0f) {
            if (ctx == 0 || ctx->src == 0) {
                *(int *)&out->m.x = 0;
                *(int *)&out->m.y = 0;
                *(int *)&out->m.z = 0;
                *(int *)&out->m.w = 0;
            } else {
                Mat *m;
                idx = Map(ctx->src[2], out->idx);
                m = (Mat *)(ctx->base + idx * 0x40);
                for (i = 0; i < 8; i++)
                    tmp.f[i] = m->f[i];
                for (i = 8; i < 16; i++)
                    tmp.f[i] = m->f[i];
                FUN_00094690(out, &out->m, (Vec4 *)&tmp.f[8], (Vec4 *)&tmp.f[4]);
            }
        }
    }
    out->v = v;
}
