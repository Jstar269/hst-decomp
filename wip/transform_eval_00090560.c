/* HSTMATCH module=EBOOT.BIN start=0x00090560 end=0x000907fc symbol=FUN_00090560 lang=c99 */

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    Vec4 r[4];
} Mat4;

typedef struct {
    char pad[56];
    int idx;
} Sub140;

extern const float DAT_002d27a4;
extern const char DAT_002ef1dd[];

extern void FUN_000c2aa0(float a, float b);
extern float FUN_000224d8(const Vec4 *a, const Vec4 *b);
extern float FUN_00022e44(float x);
extern void FUN_0004d268(Mat4 *out, const Mat4 *in);
extern void FUN_00022570(Mat4 *out, const Mat4 *a, const Mat4 *b);
extern void FUN_0004d278(Mat4 *out, float s, const Mat4 *in);
extern void FUN_00022518(Vec4 *out, const Vec4 *in);
extern void FUN_000224f8(Vec4 *out, const Vec4 *a, const Vec4 *b);
extern void FUN_00055044(void *dst, const Mat4 *m);
extern float fabsf(float);

static inline void CopyVec(Vec4 *dst, const Vec4 *src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
}

void FUN_00090560(char *param_1)
{
    Mat4 m2;
    Mat4 m1;
    Vec4 v;

    param_1[0x284] = 0;
    if (*(int *)(param_1 + 4) != 3) {
        *(int *)(param_1 + 0x268) += 1;
        FUN_000c2aa0(*(float *)(param_1 + 0x244), *(float *)(param_1 + 0x248));

        float fVar4;
        if (*(int *)(param_1 + 4) == 2) {
            v.x = *(float *)(param_1 + 0x20);
            v.y = *(float *)(param_1 + 0x24);
            v.z = *(float *)(param_1 + 0x28);
            v.w = *(float *)(param_1 + 0x2c);
            fVar4 = FUN_00022e44(FUN_000224d8(&v, &v)) / *(float *)(param_1 + 0x110);
        } else {
            fVar4 = *(float *)(param_1 + 0x120) * DAT_002d27a4;
        }
        fVar4 = -fVar4;

        m2.r[0].x = *(float *)(param_1 + 0x2c0);
        m2.r[0].y = *(float *)(param_1 + 0x2c4);
        m2.r[0].z = *(float *)(param_1 + 0x2c8);
        m2.r[0].w = *(float *)(param_1 + 0x2cc);
        m2.r[1].x = *(float *)(param_1 + 0x2d0);
        m2.r[1].y = *(float *)(param_1 + 0x2d4);
        m2.r[1].z = *(float *)(param_1 + 0x2d8);
        m2.r[1].w = *(float *)(param_1 + 0x2dc);
        m2.r[2].x = *(float *)(param_1 + 0x2e0);
        m2.r[2].y = *(float *)(param_1 + 0x2e4);
        m2.r[2].z = *(float *)(param_1 + 0x2e8);
        m2.r[2].w = *(float *)(param_1 + 0x2ec);
        m2.r[3].w = 1.0f;
        m2.r[3].x = 0.0f;
        m2.r[3].y = 0.0f;
        m2.r[3].z = 0.0f;

        FUN_0004d268(&m1, (const Mat4 *)(param_1 + 0xd0));
        FUN_00022570(&m2, &m1, &m2);
        FUN_0004d278(&m2, fVar4, &m2);
        FUN_00022570(&m2, (const Mat4 *)(param_1 + 0xd0), &m2);

        FUN_00022518(&m2.r[2], &m2.r[2]);
        FUN_000224f8(&m2.r[0], &m2.r[1], &m2.r[2]);
        m2.r[2].w = 0.0f;

        FUN_00022518(&m2.r[0], &m2.r[0]);
        FUN_000224f8(&m2.r[1], &m2.r[2], &m2.r[0]);
        m2.r[0].w = 0.0f;

        CopyVec(&m2.r[3], &m2.r[3]);

        m2.r[3].x = *(float *)(param_1 + 0x2f0);
        m2.r[3].y = *(float *)(param_1 + 0x2f4);
        m2.r[3].z = *(float *)(param_1 + 0x2f8);
        m2.r[3].w = *(float *)(param_1 + 0x2fc);
        FUN_00055044(param_1 + 0x290, &m2);

        Sub140 *sub = (Sub140 *)(param_1 + 0x140);
        if (*(float *)(param_1 + 0x170) != 3.4028235e+38f) {
            int ok = 0;
            if (fabsf(*(float *)(param_1 + 0x10)) <= 7.48639965f) {
                ok = (fabsf(*(float *)(param_1 + 0x18)) <= 11.8871994f);
            }
            if (ok) {
                param_1[0x284] = (DAT_002ef1dd[sub->idx * 16] != 0);
            }
        }
    }

    if (*(unsigned char *)(param_1 + 0x284) != 0) {
        *(int *)(param_1 + 0x288) += 1;
    } else {
        *(int *)(param_1 + 0x288) = 0;
    }
}

// Differing words: 167/167 words generated (exact size).
// Full logic, stack frame layout (176 bytes), matrix and vector operations match 100%.
// 19 instructions at the epilogue (0x907b0..0x907f8) match bit-for-bit.
// The middle body (130 words) matches instruction-for-instruction, but is shifted by 1 word (4 bytes)
// due to retail's entry sequence:
// Retail emits: lw a2, 4(a0); li v1, 3; beq a2, v1, 0x907d0; move s0, a0;
// Ours emits: move s0, a0; lw a0, 4(a0); li v1, 3; beql a0, v1, 0x907d4; lbu v1, 644(s0);
// Ruled out: volatile reads, early return, goto tail, inline helper, void*/int/param_2 types, switch statement.
// near miss from lane ag2 (unreviewed)
