/* HSTMATCH module=EBOOT.BIN start=0x00186fbc end=0x00187114 symbol=FUN_00186fbc lang=c++ */

extern "C" int FUN_0016bc7c();
extern "C" int FUN_0016bc70();
extern "C" void FUN_002177d4(void *p, int a1, int a2, int a3, int a4, int a5);

struct El1_186fbc {
    char pad0[0x14];
    short h;
    short w;
    char pad1[0x74];
};

struct El_186fbc {
    char pad0[8];
    short h;
    short w;
    char pad1[0x80];
};

extern "C" void FUN_00186fbc(char *self)
{
    char *a0r = (char *)FUN_0016bc7c();
    int cnt = *(int *)(a0r + 0x64);
    char *o = (char *)FUN_0016bc70();
    if (*(unsigned char *)(o + 0x3d) != 0) {
        El1_186fbc *e1 = (El1_186fbc *)(self + 0x1254 + 0x8c);
        FUN_002177d4(e1, e1->h - 480, e1->w, e1->h, e1->w, 5);
    } else {
        El_186fbc *e0 = (El_186fbc *)(self + 0x1254);
        FUN_002177d4(e0, e0->h - 480, e0->w, e0->h, e0->w, 5);
    }
    char *p = *(char **)(self + 0x20);
    El_186fbc *e2 = (El_186fbc *)(self + 0x1254 + 0x8c * 2);
    FUN_002177d4(e2, e2->h - 480, (int)*(float *)(p + 100), e2->h, (int)*(float *)(p + 100), cnt);
    El_186fbc *e5 = (El_186fbc *)(self + 0x1254 + 0x8c * 5);
    FUN_002177d4(e5, e5->h - 480, e5->w, e5->h, e5->w, cnt);
    El_186fbc *e3 = (El_186fbc *)(self + 0x1254 + 0x8c * 3);
    FUN_002177d4(e3, e3->h - 480, e3->w, e3->h, e3->w, cnt + 4);
    char *q = *(char **)(self + 0x28);
    int t = (int)*(float *)(q + 96);
    El_186fbc *e4 = (El_186fbc *)(self + 0x1254 + 0x8c * 4);
    FUN_002177d4(e4, t - 480, e4->w, t, e4->w, cnt + 4);
    El_186fbc *e6 = (El_186fbc *)(self + 0x1254 + 0x8c * 6);
    FUN_002177d4(e6, e6->h + 480, e6->w, e6->h, e6->w, cnt);
    El_186fbc *e7 = (El_186fbc *)(self + 0x1254 + 0x8c * 7);
    FUN_002177d4(e7, e7->h + 480, e7->w, e7->h, e7->w, cnt + 3);
    El_186fbc *e8 = (El_186fbc *)(self + 0x1254 + 0x8c * 8);
    FUN_002177d4(e8, e8->h + 480, e8->w, e8->h, e8->w, cnt + 4);
}
// NEAR MISS: 86/86 words, 24 words differ, ALL inside the argument-setup order of the nine FUN_002177d4
// calls: retail emits `a0 = ptr`, `t0 = a2`, `a1 = a3-480`, jal, `t1 = K` (delay) while we emit `a0`,
// `t1 = K`, `t0 = a2`, `a1 = a3-480`, jal. Values and registers are otherwise identical.
// Structural facts: element base 0x1254, stride 0x8c, 9 elements; the branch element (0x12e0) has its
// h/w at +0x14/+0x16 while all others use +8/+10 (separate struct type); cnt = FUN_0016bc7c()->f64 and
// the flag is FUN_0016bc70()->f3d; call order 0/1 (branch), 2, 5, 3, 4, 6, 7, 8.
// near miss from lane ds10 (unreviewed)
