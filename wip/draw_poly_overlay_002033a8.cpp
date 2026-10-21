/* HSTMATCH module=EBOOT.BIN start=0x002033a8 end=0x00203680 symbol=FUN_002033a8 lang=c++ */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Color {
    unsigned char r, g, b, a;
};
struct Tex;
struct Obj {
    char pad0[0xf0];
    unsigned char c0, c1, c2;
    char pad1[0x390 - 0xf3];
    int count;
    float ys[1];
    char pad2[0x438 - 0x398];
    float xs[1];
    char pad3[0x524 - 0x43c];
    Tex *tex;
};
extern float DAT_002ef1d4;
extern float DAT_0032b190;
extern float DAT_0032b1a4;
extern "C" {
void FUN_00051398(float, Tex *);
void FUN_00051490(Tex *, int, int, int, int, int, int);
void FUN_00052154(float, float, float, float, float, float, float, float, float, Tex *, Color, Color, Color);
void FUN_0005185c(Tex *);
}

extern "C" void FUN_002033a8(float scale, Obj *o, int, int, Vec4 pos)
{
    float y = pos.y;
    if (DAT_002ef1d4 != 0.0f) {
        float s = scale / 8.0f;
        float fx = s * (DAT_0032b190 / 410.29004f);
        float fy = s * (DAT_0032b1a4 / 410.29004f);
        if (1808.0f < pos.x + fx && pos.x - fx < 2288.0f && 1912.0f < y + fy && y - fy < 2184.0f) {
            float a = DAT_002ef1d4 * 192.0f;
            Color col;
            col.r = o->c0;
            col.g = o->c1;
            col.b = o->c2;
            col.a = (unsigned int)a;
            float x0 = pos.x + -1808.0f;
            float y0 = y + -1912.0f;
            Color zero;
            zero.r = 0;
            zero.g = 0;
            zero.b = 0;
            zero.a = 0;
            FUN_00051398(0.0f, o->tex);
            FUN_00051490(o->tex, 0, 0, 480, 272, 0, 0);
            int i = 0;
            if (0 < o->count) {
                do {
                    FUN_00052154(pos.x + (float)(int)(o->xs[i] * fx) + -1808.0f, y + (float)(int)(o->ys[i] * fy) + -1912.0f, 65280.0f,
                                 pos.x + (float)(int)(o->xs[i + 1] * fx) + -1808.0f, y + (float)(int)(o->ys[i + 1] * fy) + -1912.0f, 65280.0f,
                                 x0, y0, 65280.0f, o->tex, zero, zero, col);
                    i++;
                } while (i < o->count);
            }
            FUN_0005185c(o->tex);
        }
    }
}
// lane sn6: 177/182 words, shift-tolerant mismatch ~112 (first pass + 2 refinements). Findings: the Vec4 position arrives BY VALUE (a3 points at the caller's copy and the callee copies it to sp+80:
// lwc1 x3, swc1 x3, then w), retail keeps only y in a callee-saved FPR ($f20) and re-reads pos.x from the stack copy at each use (writing `float x = pos.x` makes MWCC keep x in $f25 instead);
// colours are two 4-byte structs built byte by byte (sb) at sp+104/108 and passed by value: retail loads both words ONCE before the loop (`lw s0,104(sp); lw s1,108(sp)`, reused in a1/a2/a3),
// ours reloads them in every iteration (copying them to second locals does not hoist them); FUN_00052154 takes 9 floats (the 9th, 65280.0f, goes to sp+0) + tex + 3 Color words;
// the 4th argument of the guard is the box test 1808 < x + fx && x - fx < 2288 && 1912 < y + fy && y - fy < 2184 with fx = scale/8 * (DAT_0032b190 / 410.29004f).
// Retail frame is 112 bytes (s0-s4 + f20-f24 saved, loop counter s3, object s4, walker s2); ours 96 (no hoisted colour words, s0-s2 only).
// near miss from lane sn6 (unreviewed)
