/* HSTMATCH module=EBOOT.BIN start=0x000ee088 end=0x000ee3e8 symbol=FUN_000ee088 lang=c++ */
extern "C" {
void FUN_00051490(void *h, int a, int b, int c, int d, int e, int f);
void FUN_00051894(float u0, float v0, float x0, float y0, float u1, float v1, float x1, float y1, void *h, int color, float z);
void FUN_00051da0(float u0, float v0, float x0, float y0, float z0, float u1, float v1, float x1, float y1, float z1,
                  float u2, float v2, float x2, float y2, float z2, void *hd, int c0, int c1, int c2);
void FUN_0005185c(void *h);
float FUN_0000bc34(float a);
float FUN_0000bf34(float a);
float FUN_0000bd2c(float a);
}

extern "C" void FUN_000ee088(float x, float y, float a, float ang, float scale, float sx, float sy, float w, float hgt, void *hd, int n)
{
    unsigned int color;
    float c[8];
    ((unsigned char *)&color)[0] = 0x80;
    ((unsigned char *)&color)[1] = 0x80;
    ((unsigned char *)&color)[2] = 0x80;
    ((unsigned char *)&color)[3] = (unsigned char)(unsigned int)(a * 128.0f);
    float hw = w * scale / 2.0f;
    float hh = hgt * scale / 2.0f;
    float fx = (float)(int)(x - hw) + hw;
    float fy = (float)(int)(y - hh) + hh;
    c[1] = -hh;
    c[3] = -hh;
    c[0] = -hw;
    c[4] = -hw;
    c[2] = hw;
    c[5] = hh;
    c[6] = hw;
    c[7] = hh;
    if (ang != 0.0f) {
        for (int i = 0; i < 4; i++) {
            float px = c[i * 2];
            float py = c[i * 2 + 1];
            c[i * 2] = FUN_0000bd2c(px * FUN_0000bc34(ang) - py * FUN_0000bf34(ang));
            c[i * 2 + 1] = FUN_0000bd2c(px * FUN_0000bf34(ang) + py * FUN_0000bc34(ang));
        }
        FUN_00051490(hd, 0, 0, 480, 272, 0, 0);
        unsigned int col = color;
        FUN_00051da0(sx, sy, fx + c[0], fy + c[1], (float)n, (sx + w), sy, fx + c[2], fy + c[3], (float)n, sx, (sy + hgt), fx + c[4], fy + c[5], (float)n, hd, col, col, col);
        FUN_00051da0((sx + w), sy, fx + c[2], fy + c[3], (float)n, (sx + w), (sy + hgt), fx + c[6], fy + c[7], (float)n, sx, (sy + hgt), fx + c[4], fy + c[5], (float)n, hd, col, col, col);
        FUN_0005185c(hd);
    } else {
        FUN_00051490(hd, 0, 0, 480, 272, 0, 0);
        FUN_00051894(sx, sy, fx + c[0], fy + c[1], sx + w, sy + hgt, fx + c[6], fy + c[7], hd, color, (float)n);
        FUN_0005185c(hd);
    }
}
// NEAR MISS (lane sn2, second pass): 216/216 words, 19 differ. Fixed since the first pass: alpha is `(unsigned char)(unsigned int)(a * 128.0f)` (the 2^31 compare/branch block that
// retail has), no `fn` local ((float)n is converted once per call into f16, caller-saved), the colour word copied once into `unsigned int col = color;` inside the rotated branch (s2),
// x1/y1 written inline as `(sx + w)` / `(sy + hgt)` (CSE'd across the two calls into f20/f21), which gives the retail callee-saved numbering (f20 w, f21 ang, f22 fy, f23 fx, f24 sy, f25 sx).
// Left: (1) 16 words: hw/hh temporaries take f2/f1 where retail has f1 (hw) / f2 (hh) (`mul.s f1,f20,f16` ... `div.s f1,f1,f2`; add operand order cvt,hw follows); every statement order,
// two-step products, `two` constants, declaration order, Snap() helper, /= forms tried: identical code. (2) 3 words: in the 2nd FUN_00051da0 call retail emits the arg moves
// f13, f18, f12 and puts `mov.s f17,f20` in the delay slot; ours f13, f12, f17 and `mov.s f18,f21` in the slot.
// near miss from lane sn2 (unreviewed)
