/* HSTMATCH module=EBOOT.BIN start=0x00044550 end=0x000447b8 symbol=FUN_00044550 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 112: ra 76, s3 72, s2 68, s1 64, s0 60, f24 52, f23 48, f22 44, f21 40, f20 36,
   six float temporaries at sp+88..108 and one outgoing float argument at sp+0. a0 = the render object (handle at
   +0x19074), a1 = the sprite record, a2 = a shape/context pointer, a3 = the passthrough value for the last call. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;

typedef struct Render {
    u8 pad0[0x19074];
    u32 handle;                  /* +0x19074 */
} Render;

typedef struct P2 {
    float x;                     /* 0 */
    float y;                     /* 4 */
} P2;

typedef struct Spr {
    float f0;                    /* 0 */
    float f4;                    /* 4 */
    u16 f8;                      /* 8 */
    float f0c;                   /* 12 */
    float f10;                   /* 16 */
    float f14;                   /* 20 */
    u32 f18;                     /* 24 */
    s8 f1c;                      /* 28 */
    s16 f1e;                     /* 30 */
    s16 f20;                     /* 32 */
    s16 f22;                     /* 34 */
    s16 f24;                     /* 36 */
} Spr;

int FUN_00044c3c(Render *r, void *ctx);
int FUN_00043f38(Render *r, void *ctx, P2 *a2, P2 *a3, P2 *a4);
void FUN_00051478(u32 handle, u32 tag);
int FUN_000524a8(u32 handle, u32 a1, float f12, float f13, float f14, float f15,
                 float f16, float f17, float f18, float f19, float stack0);

int FUN_00044550(Render *r, Spr *s, void *ctx, u32 a3)
{
    P2 p[3];
    float stack0;
    float f20;
    float f21;
    float f22;
    float f23;
    float f24;
    u32 tag;

    if (FUN_00044c3c(r, ctx) != 0)
        f22 = (float)s->f1c / 2.0f;
    else
        f22 = (float)s->f1c;

    if (FUN_00043f38(r, ctx, &p[2], &p[1], &p[0]) == 0)
        return 0;

    p[0].y = p[0].y - 14.5f;
    f23 = 0.0f;
    p[0].y = p[0].y * s->f10;
    p[0].x = p[0].x * s->f10;
    f21 = p[1].y * s->f10;
    f23 = p[1].x * s->f0c;

    if (f22 == 0.0f) {
        p[0].x = 0.0f;
        f20 = f23;
    } else if (f23 > f22) {
        p[0].x = 0.0f;
        f20 = f22;
        f23 = f22;
    } else if (f23 < f22) {
        p[0].x = (f23 - f22) / 2.0f;
        f23 = f22;
    } else {
        p[0].x = 0.0f;
    }
    tag = 0xd4000000u | ((u32)s->f20 << 10) | (u16)s->f1e;
    f22 = s->f0 - p[0].x;
    f24 = s->f4 - p[0].y;
    FUN_00051478(r->handle, tag);

    tag = 0xd5000000u | ((u32)s->f24 << 10) | (u16)s->f22;
    FUN_00051478(r->handle, tag);

    if ((s16)s->f8 < 0)
        stack0 = (float)(((s->f8 >> 1) | (s->f8 & 1))) * 2.0f;
    else
        stack0 = (float)s->f8;

    return FUN_000524a8(r->handle, a3, p[2].x, p[2].y, f22, f24, p[2].x + p[1].x, p[2].y + p[1].y,
                        f22 + f20, f24 + f21, stack0);
}
// MEASURED STATE (first write-first pass: 152/154 words, frame 96 vs 112). Decoded: a0 = render object (a u32
// handle at +0x19074), a1 = the sprite record (floats at 0/4/12/16/20, u16 at 8, s8 at 28, s16s at 30/32/34/36),
// a2 = a context pointer, a3 = a passthrough for the last call. Calls: 0x44c3c(r,ctx) -> int; 0x43f38(r,ctx,
// &p[2],&p[1],&p[0]) filling three 2D points; 0x51478(handle, 0xd4000000|(s16@32<<10)|(u16@30) then the 0xd5 form
// with s16@36/@34; 0x524a8(handle, a3, f12..f19, stack0) drawing the quad. Remaining: retail homes all three P2
// points at sp+88..111 and saves f20..f24 (frame 112); ours homes the same 24 bytes at sp+72..95 and saves only
// f21..f23 (frame 96), so the fp allocation of f20/f24 across the calls is the next lever.
// near miss from lane dsn2 (unreviewed)
