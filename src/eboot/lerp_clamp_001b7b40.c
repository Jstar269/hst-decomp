/* HSTMATCH module=EBOOT.BIN start=0x001b7b40 end=0x001b7e24 symbol=FUN_001b7b40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: plain C (a C++ `int b = !F()` gets an extra andi); the member loads are written twice in `f74->f4 != 0 && f74->f4 != 0` (a named local folds the pair); the clamp bounds are passed by POINTER (`Clamp(t, &DAT_a, &DAT_b)`, inline, bounds dereferenced twice: repeated lui + double load); `FUN_001b210c(&DAT, &self->f68, x, x)` takes the pointers first; `v.y > K` gives c.ngt.s; Vec4 copied field by field. */
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

extern int DAT_0034179c;
extern Cfg *DAT_00340284;
extern float DAT_002e995c;
extern float DAT_002e9a3c, DAT_002e9a40, DAT_002e9a44, DAT_002e9a48, DAT_002e9a4c, DAT_002e9a50;
extern float DAT_002e9a54, DAT_002e9a58, DAT_002e9a5c, DAT_002e9a60, DAT_002e9a64, DAT_002e9a68;
extern float DAT_003417a0;

int FUN_001b1f7c(int *, int);
void FUN_001b871c(Self *);
void FUN_001b2218(int *, int *, Vec4 *, int, int);
void FUN_001b210c(int *, int *, float, float);
void FUN_001b21cc(float, int *, int *);

static inline float Clamp(float v, const float *lo, const float *hi)
{
    return v < *lo ? *lo : (v > *hi ? *hi : v);
}

void FUN_001b7b40(Self *self)
{
    if (self->f74 != 0) {
        int ok = 1;
        int b = !FUN_001b1f7c(&DAT_0034179c, self->f68);
        if (!b) {
            b = !(DAT_00340284->f120 < 0);
        }
        if (!b) {
            int c = self->f74->f4 != 0 && self->f74->f4 != 0;
            if (!c) {
                ok = 0;
            }
        }
        if (ok) {
            FUN_001b871c(self);
        } else {
            Vec4 v;
            v.x = self->f74->f10.x; v.y = self->f74->f10.y; v.z = self->f74->f10.z; v.w = self->f74->f10.w;
            FUN_001b2218(&DAT_0034179c, &self->f68, &v, 0, 0);
            if (self->f70 != 0) {
                float a, bb;
                if (v.y > DAT_002e9a40) {
                    float t = (v.y - DAT_002e9a3c) / (DAT_002e9a40 - DAT_002e9a3c);
                    float c = Clamp(t, &DAT_002e9a5c, &DAT_002e9a60);
                    a = DAT_002e9a48 + c * (DAT_002e9a4c - DAT_002e9a48);
                    bb = DAT_002e9a54 + c * (DAT_002e9a58 - DAT_002e9a54);
                } else {
                    float t = (v.y - DAT_002e9a40) / (DAT_002e9a44 - DAT_002e9a40);
                    float c = Clamp(t, &DAT_002e9a64, &DAT_002e9a68);
                    a = DAT_002e9a4c + c * (DAT_002e9a50 - DAT_002e9a4c);
                    bb = DAT_002e9a58 + c * (DAT_003417a0 - DAT_002e9a58);
                }
                FUN_001b21cc(a, &DAT_0034179c, &self->f68);
                FUN_001b210c(&DAT_0034179c, &self->f68, bb, bb);
            
            } else {
                if (self->f71 == 0 && 0 < self->f6c) {
                    float f = (float)self->f6c / DAT_002e995c;
                    if (f > 0.0f) {
                        FUN_001b210c(&DAT_0034179c, &self->f68, f, f);
                    }
                    self->f6c = self->f6c - 1;
                    if (self->f6c < 1) {
                        FUN_001b871c(self);
                    }
                }
            }
        }
    }
}
