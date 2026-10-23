/* HSTMATCH module=EBOOT.BIN start=0x000944c8 end=0x00094690 symbol=FUN_000944c8 lang=c99 */
extern int FUN_0002fe80(int, int);
extern void FUN_00094690(void *, void *, float *, float *);

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    Vec4 v;
    Vec4 m;
    int idx;
} Out;

typedef struct {
    char pad[0x8c];
    void *src;
    char pad2[0x160 - 0x90];
    char *base;
} Ctx;

void FUN_000944c8(Out *out, Vec4 *in, Ctx *ctx)
{
    Vec4 v;
    int i;
    float tmp[16];
    int *p;
    int idx;
    int *m;

    v = *in;
    if (v.w == 0.0f) {
        out->m.x = 0.0f;
        out->m.y = 0.0f;
        out->m.z = 0.0f;
        out->m.w = 0.0f;
    } else if (v.w == -1.0f) {
        if (out->m.w == 0.0f && out->v.w == 0.0f) {
            out->m.x = 0.0f;
            out->m.y = 0.0f;
            out->m.z = 0.0f;
            v.w = 0.0f;
            out->m.w = 0.0f;
        }
    } else {
        v.w = 1.0f;
        if (out->m.w == 0.0f) {
            if (ctx == 0) {
                out->m.x = 0.0f;
            } else {
                p = (int *)ctx->src;
                if (p != 0) {
                    idx = p[2];
                    if (idx != 0)
                        idx = FUN_0002fe80(idx, out->idx);
                    else
                        idx = -1;
                    m = (int *)(ctx->base + idx * 0x40);
                    for (i = 0; i < 16; i++)
                        tmp[i] = *(float *)((char *)m + i * 4);
                    FUN_00094690(out, &out->m, tmp + 8, tmp);
                    goto done;
                }
                out->m.x = 0.0f;
            }
            out->m.y = 0.0f;
            out->m.z = 0.0f;
            out->m.w = 0.0f;
        }
    }
done:
    out->v = v;
}
// near miss: 109/114 (5 short, 85 differ). Structure recovered: `Vec4 v = *in` is copied to the
// stack (sp+0x50..5c, x/y/z/w in that order); v.w == 0 clears out->m (0x10..0x1c); v.w == -1 tests
// out->v.w then out->m.w and clears with `v.w = 0` between the z and w stores; otherwise v.w = 1
// and if out->m.w == 0 either the ctx==0 / ctx->src==0 path clears out->m, or it takes
// ctx->src->f8 (index), maps it with FUN_0002fe80(idx, out->idx) or -1, copies 16 floats from
// ctx->base + idx*0x40 into two stack blocks (sp+0x10 and sp+0x30) and calls
// FUN_00094690(out, out+0x10, sp+0x30, sp+0x20); the tail copies the saved v back to out->v.
// Remaining: retail's ordering of the two `lwc1` in the -1 arm (12(s0) then 28(s0)) and the exact
// placement of `v.w = 0` between the z and w stores; the copied-16-floats loop and the tail match.
// near miss from lane fm8 (unreviewed)
