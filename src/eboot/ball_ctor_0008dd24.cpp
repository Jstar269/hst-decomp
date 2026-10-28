/* HSTMATCH module=EBOOT.BIN start=0x0008dd24 end=0x0008df24 symbol=FUN_0008dd24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the 0x110 float read through the inline accessor Field110() (orders the commutative mul.s operands); names and types await human review. */
#include "hst/ball.h"

extern "C" {
extern void FUN_000c2158(void);
extern void FUN_0001f06c(void *);
extern void FUN_00056b98(void *);
extern void FUN_0006dfe4(void *);
extern void FUN_00050fc0(void *);
extern void FUN_000007f4(void *, void (*)(void), void (*)(void), int, int);
extern void FUN_0005a8ec(void);
extern void FUN_0005aeac(void);
extern void FUN_0001ca58(void *, const char *);
extern void FUN_000511c4(void *, const char *, int);
extern void FUN_0001cb88(void *);
extern void FUN_000556b0(void *, void *);
extern void FUN_0008e01c(void *);
extern void FUN_0006e094(float, float, float, void *, int);
extern void FUN_0009117c(void *, int);
extern int DAT_0030722c;
extern int DAT_00307238;
extern int DAT_0030ebf4;
extern const char DAT_002d27a7[];
extern const char DAT_002d27c0[];
extern const char DAT_002d27e4[];
}
struct Snd { virtual void s0(); virtual void s1(); virtual void s2(const char *, int, int, int, int, int); };
struct Buf { unsigned char b[16] __attribute__((aligned(16))); float f; };
static inline float Field110(const Ball *ball) { return ball->unk110; }

/* Capacities reserved for the two vectors at the end of construction. */
enum { BALL_VEC_A_RESERVE = 600, BALL_VEC_B_RESERVE = 2 };
/* Bit pattern stored to unk440 (float 1/30). */
enum { BALL_UNK440_INIT = 0x3d066e44 };

extern "C" Ball *FUN_0008dd24(Ball *ball)
{
    Buf buf;

    FUN_000c2158();
    FUN_0001f06c(&ball->vtable1e0);
    ball->vtable = &DAT_0030722c;
    ball->vtable1e0 = &DAT_00307238;
    ball->unk22c = 5;
    ball->unk230 = -1;
    ball->unk234 = -1;
    ball->unk238 = 3;
    ball->unk23c = 13;
    ball->unk240 = 0;
    ball->unk244 = 1.0f;
    ball->unk248 = 0;
    ball->unk250 = 0;
    ball->unk254 = 0;
    ball->unk258 = 0;
    ball->unk25c = 0;
    ball->unk260 = -1;
    ball->unk264 = 0;
    ball->unk268 = 0;
    ball->vecA.data = 0;
    ball->vecA.size = 0;
    ball->vecA.capacity = 0;
    ball->vecB.data = 0;
    ball->vecB.size = 0;
    ball->vecB.capacity = 0;
    ball->unk284 = 0;
    ball->unk288 = 0;
    FUN_00056b98(ball->sound);
    FUN_0006dfe4(ball->obj448);
    FUN_00050fc0(ball->obj450);
    FUN_000007f4(ball->slots, FUN_0005a8ec, FUN_0005aeac, sizeof(BallSlot), BALL_SLOT_COUNT);
    FUN_0001ca58(&DAT_0030ebf4, DAT_002d27a7 + 1);
    ((Snd *)ball->sound)->s2(DAT_002d27c0, 0, 0, 0, 0, 0);
    FUN_000511c4(ball->obj450, DAT_002d27e4, 0);
    FUN_0001cb88(&DAT_0030ebf4);
    FUN_000556b0(ball->sound, &buf);
    ball->unk440 = buf.f;
    *(int *)&ball->unk440 = BALL_UNK440_INIT;
    FUN_0008e01c(ball);
    ball->unk444 = 1;
    ball->unk21c = 3.0f;
    ball->unk220 = 1.5f;
    ball->unk224 = 0.98f;
    ball->unk228 = 0.65f;
    {
        float scaled = Field110(ball) * ball->unk21c;
        FUN_0006e094(scaled, scaled, ball->unk224, ball->obj448, 0);
    }
    if (ball->vecA.capacity < BALL_VEC_A_RESERVE)
        FUN_0009117c(&ball->vecA, BALL_VEC_A_RESERVE);
    if (ball->vecB.capacity < BALL_VEC_B_RESERVE)
        FUN_0009117c(&ball->vecB, BALL_VEC_B_RESERVE);
    return ball;
}
// Sound object: C++ class with three declared virtuals (`Snd::s2(const char *, 5 ints)`, slot 2 = vtable +16) cast over
// ball+0x290 (a C function pointer would call through v0); the local is `struct Buf { unsigned char b[16]
// __attribute__((aligned(16))); float f; }` (32-byte aligned slot at sp+16, f at sp+32).
// matching idiom: the float at 0x110 is read through the inline accessor Field110(). MWCC orders the operands of a commutative
// operator by Sethi-Ullman weight before inlining (a call, inline or not, weighs 4, a field load 1) and puts the lighter one
// in fs: retail's `mul.s $f12,$f0(0x21c),$f1(0x110)` with the 0x110 load issued first. Both direct spellings tie (weight 1)
// and keep source order: `f110 * f21c` gives the right loads but fs=0x110, `f21c * f110` swaps the loads.
