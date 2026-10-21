/* HSTMATCH module=hstp_trans_main.prx start=0x001c5800 end=0x001c5ae4 symbol=FUN_001c5800 lang=c99 */
/* Clone of src/eboot/lerp_clamp_001b7b40.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: plain C (a C++ `int b = !F()` gets an extra andi); the member loads are written twice in `f74->f4 != 0 && f74->f4 != 0` (a named local folds the pair); the clamp bounds are passed by POINTER (`Clamp(t, &DAT_a, &DAT_b)`, inline, bounds dereferenced twice: repeated lui + double load); `FUN_001c01a0(&DAT, &self->f68, x, x)` takes the pointers first; `v.y > K` gives c.ngt.s; Vec4 copied field by field. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Sub {
    char pad0[4];
    int f4;
    char pad8[8];
    Vec4 f10;
} Sub;
typedef struct Self {
    char pad0[0x68];
    int f68;
    int f6c;
    unsigned char f70;
    unsigned char f71;
    char pad72[2];
    Sub *f74;
} Self;
typedef struct Cfg { char pad[0x120]; int f120; } Cfg;

extern int DAT_003eaad8;
extern Cfg *DAT_003e95c4;
extern float DAT_0039147c;
extern float DAT_003915f8, DAT_003915fc, DAT_00391600, DAT_00391604, DAT_00391608, DAT_0039160c;
extern float DAT_00391610, DAT_00391614, DAT_00391618, DAT_0039161c, DAT_00391620, DAT_00391624;
extern float DAT_003eaadc;

int FUN_001c0010(int *, int);
void FUN_001c6408(Self *);
void FUN_001c02ac(int *, int *, Vec4 *, int, int);
void FUN_001c01a0(int *, int *, float, float);
void FUN_001c0260(float, int *, int *);

static inline float Clamp(float v, const float *lo, const float *hi)
{
    return v < *lo ? *lo : (v > *hi ? *hi : v);
}

void FUN_001c5800(Self *self)
{
    if (self->f74 != 0) {
        int ok = 1;
        int b = !FUN_001c0010(&DAT_003eaad8, self->f68);
        if (!b) {
            b = !(DAT_003e95c4->f120 < 0);
        }
        if (!b) {
            int c = self->f74->f4 != 0 && self->f74->f4 != 0;
            if (!c) {
                ok = 0;
            }
        }
        if (ok) {
            FUN_001c6408(self);
        } else {
            Vec4 v;
            v.x = self->f74->f10.x; v.y = self->f74->f10.y; v.z = self->f74->f10.z; v.w = self->f74->f10.w;
            FUN_001c02ac(&DAT_003eaad8, &self->f68, &v, 0, 0);
            if (self->f70 != 0) {
                float a, bb;
                if (v.y > DAT_003915fc) {
                    float t = (v.y - DAT_003915f8) / (DAT_003915fc - DAT_003915f8);
                    float c = Clamp(t, &DAT_00391618, &DAT_0039161c);
                    a = DAT_00391604 + c * (DAT_00391608 - DAT_00391604);
                    bb = DAT_00391610 + c * (DAT_00391614 - DAT_00391610);
                } else {
                    float t = (v.y - DAT_003915fc) / (DAT_00391600 - DAT_003915fc);
                    float c = Clamp(t, &DAT_00391620, &DAT_00391624);
                    a = DAT_00391608 + c * (DAT_0039160c - DAT_00391608);
                    bb = DAT_00391614 + c * (DAT_003eaadc - DAT_00391614);
                }
                FUN_001c0260(a, &DAT_003eaad8, &self->f68);
                FUN_001c01a0(&DAT_003eaad8, &self->f68, bb, bb);
            
            } else {
                if (self->f71 == 0 && 0 < self->f6c) {
                    float f = (float)self->f6c / DAT_0039147c;
                    if (f > 0.0f) {
                        FUN_001c01a0(&DAT_003eaad8, &self->f68, f, f);
                    }
                    self->f6c = self->f6c - 1;
                    if (self->f6c < 1) {
                        FUN_001c6408(self);
                    }
                }
            }
        }
    }
}
