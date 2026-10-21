/* HSTMATCH module=EBOOT.BIN start=0x0021f7e0 end=0x0021fb38 symbol=FUN_0021f7e0 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (214/214 words, 46 differ: temp register naming; see trailing comments); names and types await human review. */
struct Pos { float x, y, z, w; } __attribute__((aligned(16)));
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));

struct Sub { char pad60[0x60]; float f60; float f64; char pad68[0x78 - 0x68]; float f78; };
struct Digit { unsigned color; int f4; char pad[0x24 - 8]; int f24; int f28; };
struct Cfg { int a, b, c; };
struct Globals { char pad[0x80]; int f80; };
struct Self {
    char pad0[0x55];
    unsigned char f55;
    char pad56[2];
    int f58;
    int f5c;
    int f60;
    Sub *f64;
    Digit *objs[8];
};

extern Globals *DAT_003415a8;
extern float DAT_0034a1e0, DAT_0034a1e4, DAT_0034a1f0;
extern float DAT_002f0ae8, DAT_002f0aec;
extern int DAT_002f0a60;
extern Cfg DAT_002f09f0[];

extern "C" {
void FUN_0021fb38(Self *);
void FUN_00103480(Self *);
Vec4 *FUN_00022418(Vec4 *, const Pos *, const Vec4 *);
void FUN_0021fb9c(Self *, Vec4 *);
void FUN_0021fb70(Self *);
double FUN_0000c07c(double, double);
void FUN_000ffb3c(Digit *, int);

static inline Digit *Obj(const Self *s, int i) { return s->objs[i]; }
static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

static inline Vec4 Add(const Pos &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}

void FUN_0021f7e0(Self *self, int base, Pos *p3)
{
    Pos v = *p3;
    self->f58 = base;
    self->f5c = DAT_003415a8->f80;
    FUN_0021fb38(self);
    self->f55 = 1;
    self->f64->f60 = DAT_0034a1e0;
    self->f64->f64 = DAT_0034a1e4;
    float x = Clamp(DAT_0034a1f0, DAT_002f0ae8, DAT_002f0aec);
    self->f64->f78 = x;
    FUN_00103480(self);
    Vec4 w = Add(v, Vec4(0.0f, 0.2f, 0.0f, 0.0f));
    FUN_0021fb9c(self, &w);
    self->f60 = DAT_002f0a60;
    FUN_0021fb70(self);
    int loc[2] = { self->f58, self->f5c - self->f58 };
    int i = 0;
    do {
        int n = (int)((double)loc[0] / FUN_0000c07c(10.0, (double)i));
        int digit = n % 10;
        int j = 7 - i;
        int k = 3 - i;
        if (i != 0 && n <= 0) {
            FUN_000ffb3c(self->objs[j], 1);
            FUN_000ffb3c(self->objs[k], 1);
        } else {
            Digit **pj = &self->objs[j];
            FUN_000ffb3c(*pj, 0);
            Digit **pk = &self->objs[k];
            FUN_000ffb3c(*pk, 0);
            int vj = digit + DAT_002f09f0[j].c;
            (*pj)->f24 = vj;
            (*pj)->f28 = vj;
            int vk = digit + DAT_002f09f0[k].c;
            (*pk)->f24 = vk;
            (*pk)->f28 = vk;
        }
        Digit *dj = Obj(self, j);
        Digit *dk = Obj(self, k);
        Digit **ppk = &dk;
        i++;
        unsigned kc = (*ppk)->color;
        unsigned jc = dj->color;
        dj->color = (((jc >> 16) & 0xff) << 16) | (((jc >> 8) & 0xff) << 8) | (jc & 0xff);
        (*ppk)->color = (((kc >> 16) & 0xff) << 16) | (((kc >> 8) & 0xff) << 8) | (kc & 0xff);
    } while (i < 4);
}
}

// sn1 NEAR (213/214 words, 77 differ, all in the digit loop body): everything before the loop is word-exact (POD `Pos v = *p3` batched copy, `Vec4 w = Add(v, Vec4(0, 0.2f, 0, 0))`
// through an inline returning Vec4 with the slots v 96 / w 80 / t 64 / r 48, Clamp with `v > hi`, the guarded 8-byte `int loc[2] = {...}` clear) and the soft-float chain
// `(int)((double)loc[0] / FUN_0000c07c(10.0, (double)i))` emits exactly retail's __floatsidf/pow/__floatsidf/__divdf3/__fixdfsi sequence (needs `__floatsidf = 0x00022178`
// in symbols/EBOOT.BIN.txt, appended by this lane). Loop layout facts: `digit = n % 10` is computed BEFORE j = 7 - i, k = 3 - i; the hide/show split is
// `if (i != 0 && n <= 0) { hide } else { show }`; the visible branch keeps the two element pointers `&self->objs[j]` / `&self->objs[k]` in s7/s8 (stores reload through them) and
// the byte offsets j*4 / k*4 in s3 / s2; the mask `c & 0xffffff` is the bytewise reassembly `(((c>>16)&0xff)<<16)|(((c>>8)&0xff)<<8)|(c&0xff)` (ext/sll/or) on both objects.
// Not matched: retail takes the table base into t1 (we use a2) and builds the offsets as `sll s3,s1,2; addu v0,s5,s3` (ours folds `addu s3,s5,v0`).
// sn1 second pass (214/214 words, 46 differ): the byte offsets j*4 / k*4 stay in s3 / s2 and the sums are recomputed (`sll s3,s1,2; addu v0,s5,s3`) ONLY when the join accesses go through a
// `const Self *` helper: `static inline Digit *Obj(const Self *s, int i) { return s->objs[i]; }` used for `dj` and `dk` (type-keyed CSE: shares the shift, not the sum; MWCC-DIGEST section 8, 0xf3984).
// Remaining: temp register choice (retail table base t1 / value t0, join temps t3,v1,t2,t1; ours a2,a1 / t1,a0,a2,a3) and `Digit *oj = *pj; oj->f24 = vj; oj->f28 = vj;` (one reload of *pj
// instead of two) gives retail's single `lw a0,0(s7)` but costs a word elsewhere in this arrangement.
// near miss from lane sn1 (unreviewed)
