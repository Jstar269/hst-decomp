/* HSTMATCH module=hstp_trans_main.prx start=0x000ea55c end=0x000ea624 symbol=FUN_000ea55c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* effect_ball.cpp (assert strings): replaces the ball-locus child object (0xc0 bytes, ctor FUN_000e5aec) and asserts it (line 1229). */
struct BallLocus { virtual ~BallLocus(); };
struct EffectBall {
    char pad0[0x48];
    BallLocus *m_pBallLocus;  /* 0x48 */
};

extern char DAT_0037d8c4[];  /* assertion format */
extern char DAT_0037d924[];  /* "m_pBallLocus" */
extern char DAT_0037d8f8[];  /* "effect_ball.cpp" */

void *operator new(unsigned int size);

extern "C" {
void FUN_000e5ac0(...);
BallLocus *FUN_000e5aec(void *mem, EffectBall *owner, int a, int b);
void FUN_0001ef34(EffectBall *self, BallLocus *child);
void FUN_000ea55c(EffectBall *self, int a, int b);
}

#define ASSERT(c, text, line) \
    if (!(c)) { FUN_000e5ac0(DAT_0037d8c4, text, DAT_0037d8f8, line); for (;;) {} }
#define SAFE_DELETE(p) if (p) { delete p; p = 0; }

extern "C" void FUN_000ea55c(EffectBall *self, int a, int b)
{
    if (self->m_pBallLocus)
        SAFE_DELETE(self->m_pBallLocus);
    BallLocus *p = (BallLocus *)operator new(0xc0);
    if (p)
        p = FUN_000e5aec(p, self, a, b);
    self->m_pBallLocus = p;
    ASSERT(self->m_pBallLocus, DAT_0037d924, 1229);
    FUN_0001ef34(self, self->m_pBallLocus);
}
