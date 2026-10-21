/* HSTMATCH module=EBOOT.BIN start=0x000a1708 end=0x000a1a78 symbol=FUN_000a1708 lang=c++ */
struct Cfg {
    char pad[0x45];
    unsigned char f45;
    char pad1[0x58 - 0x46];
    int f58;
};
struct Node {
    char pad[0xf0];
    int fF0;
};
struct Sub {
    char pad[0x58];
    Node *f58;
};
struct Input {
    char pad[0x89];
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
    signed char d : 2;
    char pad1[0xa0 - 0x8a];
    float fa0;
};
struct Self {
    char pad0[0x150];
    int f150;
    char pad1[0x409 - 0x154];
    unsigned char f409;
    char pad2[0x411 - 0x40a];
    unsigned char f411;
    char pad3[0x419 - 0x412];
    unsigned char f419;
    char pad4[0x424 - 0x41a];
    int f424;
    char pad5[0x580 - 0x428];
    float f580, f584, f588, f58c;
    float f590, f594, f598, f59c;
    char pad6[0x5bc - 0x5a0];
    Sub *f5bc;
};
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
extern Cfg *DAT_00338b44;
extern float DAT_0034125c;
extern float DAT_002bfcd0;
static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (hi < v ? hi : v); }
extern "C" {
unsigned char FUN_000a2c58(float, float, Self *, int *);
int FUN_00093b00(Sub *, int);
float FUN_0000bf34(int);
void FUN_000a3460(Vec4 *, Self *, float *, float *);
void FUN_000b237c(float, float, float, Self *, int, int, int, int, int, int, int);
}

extern "C" void FUN_000a1708(Self *self, Input *in)
{
    self->f590 = self->f580;
    self->f594 = self->f584;
    self->f598 = self->f588;
    self->f59c = self->f58c;
    if (self->f409 == 0 && self->f411 == 0 && self->f419 == 0) {
        int local4 = 0;
        unsigned char ok = FUN_000a2c58(in->fa0, 0.0f, self, &local4);
        if (ok == 0) {
            float f = 0.0f;
            if (!(in->a < 0)) {
                f = -1.0f;
            }
            if (!(in->c < 0)) {
                f = 1.0f;
            }
            ok = FUN_000a2c58(f, 0.0f, self, &local4);
        }
        Sub *sub = self->f5bc;
        int s1 = 0x7fff;
        int s0 = 0x7fff;
        int k;
        if (sub->f58 == 0) {
            k = -1;
        } else {
            k = sub->f58->fF0;
        }
        if (self->f424 < 1 && ((k != 0x8c && k != 0x8e) || FUN_00093b00(sub, 0) != 0)) {
            s1 = 0x8a;
            s0 = 0x8b;
        }
        if (ok != 0) {
            float d = 0.01f * DAT_0034125c * FUN_0000bf34(local4);
            float lim;
            if (DAT_00338b44->f45 == 0) {
                lim = 5.4863997f;
            } else {
                lim = 4.1148f;
            }
            Vec4 want;
            Vec4 out;
            want.x = self->f580;
            want.y = self->f584;
            want.z = self->f588;
            want.w = self->f58c;
            float k = (float)DAT_00338b44->f58;
            float t = k * (self->f580 + d);
            want.x = Clamp(t, DAT_002bfcd0, lim - 0.79999995f);
            want.x = k * want.x;
            FUN_000a3460(&out, self, &want.x, &self->f590);
            int eq = out.x == want.x;
            if (eq) {
                eq = out.y == want.y;
            }
            if (eq) {
                eq = out.z == want.z;
            }
            if (eq) {
                eq = out.w == want.w;
            }
            if (eq && self->f580 != want.x) {
                self->f580 = want.x;
                if ((d < 0.0f) == (self->f150 == 0)) {
                    s1 = 0x92;
                    s0 = 0x93;
                } else {
                    s1 = 0x90;
                    s0 = 0x91;
                }
            }
        }
        FUN_000b237c(-1.0f, -1.0f, 0.0f, self, s1, 1, s0, 1, 1, 0, 0);
    }
}
// lane sn6: 220/220 words, shift-tolerant mismatch ~67 (hstmatch word-by-word 165). Semantics complete: position update with the clamp Clamp(k*(f580 + d), DAT_002bfcd0, lim - 0.79999995f) (const-ref
// clamp, returned by value), want = {f580..f58c} copied field-wise, x replaced by k * clamp, FUN_000a3460(&out, self, &want.x, &self->f590), "unchanged" test as a materialised chain
// (`c.eq.s; bc1t; li v0,1; move v0,zero; beqz v0` per component), message ids 0x8a/0x8b, 0x90..0x93, FUN_000b237c(-1,-1,0,self,..). Vec4 locals need `aligned(16)` (out at sp+48, want at sp+64);
// the 2-bit signed fields at +0x89 are bitfields (`lb; sll 24; sra 30` and `sll 28; sra 30`); FUN_000a2c58 returns unsigned char (andi 0xff).
// Open: (1) retail keeps `(float)cfg->f58` ONCE in $f5 (one cvt.s.w) and does not store the clamp result to want.x before the multiply; (2) the compare chain in retail has NO `andi v0,v0,0xff`
// (bool/int variables and an inline `Same(a,b)` helper both add it or flatten the chain); (3) the first call's float arg is passed as `lwc1 $f12,92(sp)` (FUN_000a2c58 second
// param/first float) and retail begins with `beqzl v1,L; sw zero,92(sp)` (local4 = 0 in the slot).
// near miss from lane sn6 (unreviewed)
