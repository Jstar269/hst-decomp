/* HSTMATCH module=EBOOT.BIN start=0x000622d4 end=0x000623e8 symbol=FUN_000622d4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: fade-panel init/retarget, sibling of 0x00062150. */
extern "C" int DAT_00331880[];
extern "C" void FUN_000790d0(int id, int x, int y);

struct Panel
{
    float x0;
    float y0;
    float x1;
    float y1;
    float span;
    float timer;
};

extern "C" void FUN_000622d4(int id, int x, int y, int time)
{
    Panel *p = (Panel *)DAT_00331880 + id;

    if (time <= 0) {
        FUN_000790d0(id, x, y);
        p->x1 = (float)x;
        p->x0 = (float)x;
        p->y1 = (float)y;
        p->y0 = (float)y;
        p->timer = 0.0f;
    } else {
        if (p->timer > 0.0f) {
            float s = 1.0f - p->timer / p->span;
            p->x0 = p->x0 + s * (p->x1 - p->x0);
            p->y0 = p->y0 + s * (p->y1 - p->y0);
        }
        p->x1 = (float)x / 128.0f;
        p->y1 = (float)y / 128.0f;
        p->timer = (float)time;
        p->span = (float)time;
    }
}

// NEAR 4/69 words (lane dsn2, DeepSeek V4.1 Flash (Freebuff)). Only the ORDER of the two lwc1 pairs in the
// lerp differs: retail loads p->x0 (off 0) into $f1 and then p->x1 (off 8) into $f0, ours the reverse (same
// for y0/y1 at 4/12); every other instruction, the register colouring, the `bgtz a3` else layout and both
// store orders are already exact. Tried and no better: `+=`, `s*(x1-x0) + x0`, named endpoint locals (13
// words - forces $f3/$f5 colouring and a different div). Next step: a spelling that makes MWCC emit the
// base load first - e.g. the `p->x0 * (1.0f - s) + p->x1 * s` form is semantically different (2 muls) so
// instead try an inline lerp helper taking (from, to, t) by value, or a Chinese-remainder style
// `p->x0 += (p->x1 - p->x0) * s` (mul operand order flips, watch mul.s $f0,$f2,$f0).
// near miss from lane dsn2 (unreviewed)
