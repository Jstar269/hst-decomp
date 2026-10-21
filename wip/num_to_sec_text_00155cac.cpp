/* HSTMATCH module=EBOOT.BIN start=0x00155cac end=0x00155ea4 symbol=FUN_00155cac lang=c++ rodata=0x002c1b0c */
struct Ctx {
    void *tab;
};
struct Cmd {
    int pad0;
    int pad4;
    int f8;
    int kind;
    int f10;
    int f14;
};
extern "C" {
extern unsigned char DAT_003402f0;
extern float DAT_002dcba4;
extern float DAT_002dcba8;
extern char DAT_002dcbac[];
extern char DAT_002dcbb4[];
extern int DAT_0034176c;
int *FUN_0014c344(void *t, int i);
float *FUN_0014c34c(void *t, int i);
int *FUN_0014c354(void *t, int i);
float *FUN_0014c35c(void *t, int i);
int *FUN_0014c364(void *t, int i);
float *FUN_0014c374(void *t, int i);
int *FUN_0014c384(void *t, int i);
float *FUN_0014c398(void *t, int i);
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0014d044(Ctx *c);
void FUN_0014fd94(const char *fmt, ...);
void FUN_00198d68(int a, int b, char *buf);
}

static inline float Clamp(float v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" int FUN_00155cac(Cmd *self, Ctx *ctx)
{
    void *t = ctx->tab;
    int v = 0;
    switch (self->kind) {
    case 0:
        v = *FUN_0014c344(t, self->f10);
        break;
    case 1:
        v = (int)*FUN_0014c34c(t, self->f10);
        break;
    case 2:
        v = *FUN_0014c354(t, self->f10);
        break;
    case 3:
        v = (int)*FUN_0014c35c(t, self->f10);
        break;
    case 4:
        v = *FUN_0014c364(t, self->f10);
        break;
    case 5:
        v = (int)*FUN_0014c374(t, self->f10);
        break;
    case 8:
        v = *FUN_0014c384(t, self->f10);
        break;
    case 9:
        v = (int)*FUN_0014c398(t, self->f10);
        break;
    }
    float f = (float)(v + self->f14) / 30.0f;
    char buf[8];
    FUN_000143b0(buf, DAT_002dcbac, (double)Clamp(f, DAT_002dcba4, DAT_002dcba8));
    if (DAT_003402f0) {
        FUN_0014d044(ctx);
        FUN_0014fd94(DAT_002dcbb4, self->f8, v, self->f10, 30, buf);
    }
    FUN_00198d68(DAT_0034176c, self->f8, buf);
    return 0;
}
// PARKED (lane sn2, ~12 compiles): 118 of 126 words; everything (switch with 8 getter cases and the jump table at rodata=0x2c1b0c, the double-load clamp,
// the double print via 0x143b0, the trace hook) matches EXCEPT the argument register of the table pointer: retail loads `lw t0,0(a1)` at the very top (before
// `move s2,a0`) and passes it with `move a0,t0` in the delay slot of EVERY getter call (8 extra words, so all later words are shifted), ours coalesces it with a0
// (`lw a0,0(a1)` after the moves, no per-case move). Tried: declaration order, int/void* type, an inline Fetch(tab, kind, idx) (puts it in a2 and hoists idx), Fetch(tab, cmd)
// (back to a0), a volatile local (v1 + stack spill). The register allocator picks t0 only when the load precedes the copy of the first parameter (a0 still live).
// near miss from lane sn2 (unreviewed)
