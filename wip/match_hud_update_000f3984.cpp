/* HSTMATCH module=EBOOT.BIN start=0x000f3984 end=0x000f4060 symbol=FUN_000f3984 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (37 words, register allocation only); names and types await human review. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
extern "C" Vec4 *FUN_00022498(Vec4 *out, const Vec4 *v, float s);
inline Vec4 operator*(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

struct Sprite {
    unsigned color;
    char pad4[0x24 - 4];
    int frame0;
    int frame1;
    char pad2c[0xf8 - 0x2c];
    void *image;
    char padfc[0x118 - 0xfc];
    unsigned color_;
    int pad11c;
    Vec4 colorf_;
    char pad130[0x138 - 0x130];
    int dirty;
    void SetFrame(int f) { frame0 = f; frame1 = f; }
    void SetColor(unsigned c)
    {
        color_ = c;
        Vec4 v;
        v.x = (float)(c & 0xff);
        v.y = (float)((c >> 8) & 0xff);
        v.z = (float)((c >> 16) & 0xff);
        v.w = (float)((c >> 24) & 0xff);
        colorf_ = v * 0.008f;
    }
};

struct VObj {
    virtual void v0();
    virtual void Update();
};

struct SprDef { int x, y, frame; };

struct Self {
    char pad0[0x68];
    Sprite *spr[84];
    VObj *obj;
    char pad1bc[0x1c4 - 0x1bc];
    int m1c4;
    float m1c8;
    char pad1cc[0x1e0 - 0x1cc];
    int m1e0[2][2];
    unsigned char flags[4][2];
};

struct PlayerInfo {
    short id;               /* 0x18 */
    char pad2[0xe - 2];
    unsigned char me;       /* 0x26 */
    char padf[0x20 - 0xf];
    unsigned short m20;     /* 0x38 */
    char pad22[0x64 - 0x22];
    unsigned char m64;      /* 0x7c */
    char pad65[0xc8 - 0x65];
    unsigned char mc8;      /* 0xe0 */
    char padc9[3];
    char image[4];          /* 0xe4 */
};

struct Slot {               /* 0x120 bytes, table at DAT_003417b8 */
    char pad0[0x18];
    PlayerInfo info;
    char padE8[0x118 - 0xe8];
    unsigned char m118;
    char pad119[0x120 - 0x119];
};

struct Team { char pad0[0x144]; int m144; };
struct Match { char pad0[0x3c]; int m3c; char pad40[0x70 - 0x40]; Team *teams[4]; };
struct Rules { char pad0[0x45]; unsigned char singles; char pad46[0x50 - 0x46]; int m50; char pad54[0xb4 - 0x54]; int mb4; char padb8[0xc0 - 0xb8]; int mc0; };

extern Slot DAT_003417b8[];
extern Match *DAT_003386b0;
extern Rules *DAT_00338b44;
extern int DAT_0034a678;
extern unsigned char DAT_003386b8;
extern SprDef DAT_002d7cf4[];

extern "C" {
void FUN_000ffb3c(Sprite *, int);
void FUN_0010d4a8(Sprite *);
void *FUN_001fea10(int, int, int);
void FUN_000f4060(Self *);
int FUN_000dea20(Rules *, int);
int FUN_000de51c(Rules *, int);
int FUN_000de2c8(Rules *, int);
int FUN_000de3f0(Rules *, int);
int FUN_000def0c(Rules *);
}

static inline void SetNum(const Self *s, int j, int id)
{
    FUN_000ffb3c(s->spr[18 + j], 0);
    s->spr[18 + j]->SetFrame(id + DAT_002d7cf4[18 + j].frame);
}

static inline void Update68a(const Self *s, int j, int d)
{
    FUN_000ffb3c(s->spr[14 + j], 1);
    FUN_000ffb3c(s->spr[10 + j], 0);
    s->spr[10 + j]->SetFrame(d + DAT_002d7cf4[10 + j].frame);
}

static inline void SetScore(Self *self, int a, int b)
{
    self->spr[75]->SetFrame(a + DAT_002d7cf4[75].frame);
    self->spr[77]->SetFrame(DAT_002d7cf4[77].frame + b);
}

extern "C" void FUN_000f3984(Self *self, bool full)
{
    self->obj->Update();
    for (int i = 0; i < 2; i++) {
        FUN_000ffb3c(self->spr[i], 1);
        self->spr[i]->color = 0x80808080;
        int f = DAT_002d7cf4[i].frame;
        if (self->flags[0][i])
            self->spr[i]->SetFrame(f + 3);
        else if (self->flags[0][1 - i])
            self->spr[i]->SetFrame(f + 4);
        else if (self->flags[1][i])
            self->spr[i]->SetFrame(f + 2);
        else if (self->flags[2][i])
            self->spr[i]->SetFrame(f);
        else if (self->flags[3][i])
            self->spr[i]->SetFrame(f + 1);
        else {
            FUN_000ffb3c(self->spr[i], 1);
            self->spr[i]->color = 0x808080;
        }
        self->spr[54 + i]->color = 0x33000000;
        self->spr[56 + i]->color = 0x33000000;
        self->spr[46 + i * 4]->SetFrame(self->m1e0[i][0]);
        self->spr[47 + i * 4]->SetFrame(self->m1e0[i][1]);
        for (int k = 0; k < (DAT_00338b44->singles ? 1 : 2); k++) {
            int j = i + k * 2;
            Match *g = DAT_003386b0;
            Team *team = g->teams[j];
            Slot *slot = &DAT_003417b8[j];
            int c = slot->info.m64;
            int d = slot->m118;
            PlayerInfo *p = &slot->info;
            void *img = p->image;
            if (DAT_0034a678 == 0x31) {
                if (c != 15 && g->m3c != 9 && team->m144 == 1)
                    c = 17;
            } else if (DAT_0034a678 == 0x44) {
                if (p->me == 1)
                    img = FUN_001fea10(7, 0, p->m20);
                else if (p->mc8)
                    img = FUN_001fea10(12, 0, p->id);
            }
            Sprite *s = self->spr[80 + j];
            s->image = img;
            s->dirty = 1;
            FUN_0010d4a8(s);
            self->spr[80 + j]->SetColor(0x80191919);
            if (DAT_0034a678 == 0x44) {
                Update68a(self, j, d);
                if (p->me == 1)
                    FUN_000ffb3c(self->spr[18 + j], 1);
                else
                    SetNum(self, j, p->id);
            } else {
                FUN_000ffb3c(self->spr[10 + j], 1);
                FUN_000ffb3c(self->spr[18 + j], 1);
                FUN_000ffb3c(self->spr[14 + j], 0);
                self->spr[14 + j]->SetFrame(c + DAT_002d7cf4[14 + j].frame);
            }
        }
    }
    if (DAT_003386b8)
        FUN_000f4060(self);
    for (int i = 0; i < 2; i++) {
        int m = DAT_00338b44->m50;
        if (i == 0) {
            FUN_000ffb3c(self->spr[34 + i], m != 0);
            if ((DAT_00338b44->singles != 0) ^ 1)
                FUN_000ffb3c(self->spr[36 + i], m != 2);
        } else {
            FUN_000ffb3c(self->spr[34 + i], m != 1);
            if ((DAT_00338b44->singles != 0) ^ 1)
                FUN_000ffb3c(self->spr[36 + i], m != 3);
        }
    }
    if (full) {
        FUN_000ffb3c(self->spr[74], 0);
        for (int k = 75; k < 79; k++)
            FUN_000ffb3c(self->spr[k], 1);
        if (FUN_000dea20(DAT_00338b44, -1))
            self->spr[74]->SetFrame(DAT_002d7cf4[74].frame + 2);
        else if (FUN_000de51c(DAT_00338b44, -1))
            self->spr[74]->SetFrame(DAT_002d7cf4[74].frame + 1);
        else if (FUN_000de2c8(DAT_00338b44, -1) || FUN_000de3f0(DAT_00338b44, -1))
            self->spr[74]->SetFrame(DAT_002d7cf4[74].frame);
        else if (FUN_000def0c(DAT_00338b44))
            self->spr[74]->SetFrame(DAT_002d7cf4[74].frame + 3);
        else {
            FUN_000ffb3c(self->spr[74], 1);
            SetScore(self, DAT_00338b44->mb4, DAT_00338b44->mc0);
            for (int k = 75; k < 79; k++)
                FUN_000ffb3c(self->spr[k], 0);
        }
        self->m1c4 = 0;
    } else
        self->m1c4 = 0;
    self->m1c8 = 1.0f;
}
// NEAR MISS: 439/439 words, 37 differ, all register naming; the instruction stream is otherwise identical.
// - ~34 words: s-register rotation self/c/k: ours self=s7, c=s5, k=s6; retail self=s5, c=s6, k=s7 (d=s8, j=s4,
//   T0=j*4=s3, p=s2, T1=s1 already agree). Ruled out (no change): declaration order of c/d/k/p/slot, c/d declared
//   at function or outer-loop scope, member function with implicit this, self as a copy of a void* / Self* param,
//   whole body as a static inline, int/unsigned c, ++k, while loop, j = k*2 + i / 2*k / k+k, inline helpers for the
//   join/non-68/68 parts, const casts instead of const helpers, flags/m1e0/spr[46+4i] layout variants (12 combos),
//   moving or inlining the code after the outer loop (it does not influence the choice: removing it keeps self=s7).
// - 1 word: SetScore's first sum is `addu a0,a1,a0` (ours, a + tbl) vs `addu a0,a0,a1` (retail); `tbl + a` gets the
//   operand order right but swaps the a0/a1 load registers instead.
// - 2 words: slot address lands in v0 (ours) vs v1 (retail), so `lui v1; lw a0,mode` schedules above the lbu's.
// What made the rest match: inner-loop index `j = i + k * 2` recomputed per iteration (MWCC strength-reduces it
// to s4 += 2 but leaves j*4/j*0x120/j*12 unreduced, as retail; an explicit `j += 2` reduces every address);
// `Team *team = g->teams[j]` read at the top (keeps j*4 live in s3); the mode-0x44 sprite code through
// `const Self *` helpers (the type-keyed CSE then reuses j*4 but recomputes self + j*4 into s3, which is what
// pushes the four outer-loop strength-reduced pointers into the stack slots 56..68); `int id = p->id` before the
// call (helper argument); SetScore(self, mb4, mc0) evaluates mc0 then mb4 before the stores (right-to-left args).
