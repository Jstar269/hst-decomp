/* HSTMATCH module=EBOOT.BIN start=0x001a3fe8 end=0x001a4180 symbol=FUN_001a3fe8 lang=c++ */
/* Clone of src/sharing_main/sync_ctx_flags_001b15b4.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: C++ vector helpers with size() and operator[], separate else-if branches, and #pragma opt_strength_reduction off; exact match verified; names and types await human review. */
typedef struct {
    char pad00[0x3c9];
    unsigned char f3c9;
    unsigned char f3ca;
    unsigned char f3cb;
    char pad3cc[3];
    unsigned char f3cf;
    unsigned char f3d0;
    signed char f3d1;
    signed char f3d2;
    char pad3d3[9];
    unsigned char f3dc;
    signed char f3dd;
    char f3de;
    unsigned char f3df;
} Ctx_001a3fe8;

struct IntVec_001a3fe8 {
    int *data;
    unsigned int sz;
    int cap;
    unsigned int size() const { return sz; }
    int &operator[](unsigned int i) { return *(data + i); }
};

struct VecVec_001a3fe8 {
    IntVec_001a3fe8 *data;
    unsigned int sz;
    int cap;
    unsigned int size() const { return sz; }
    IntVec_001a3fe8 &operator[](unsigned int i) { return *(data + i); }
};

typedef struct {
    char pad00[0x2bc];
    int f2bc;
    char pad2c0[0x314 - 0x2c0];
    int f314;
    unsigned int f318;
    unsigned int f31c;
    char pad320[8];
    int f328;
    int f32c;
    VecVec_001a3fe8 vec330;
    char pad33c[0x390 - 0x33c];
    VecVec_001a3fe8 vec390;
} Self_001a3fe8;

extern "C" {
extern Ctx_001a3fe8 *FUN_001feec4(void);
extern void FUN_001a4588(Self_001a3fe8 *, unsigned char);
extern void FUN_001a4760(Self_001a3fe8 *, unsigned char);
extern void FUN_001a47a0(Self_001a3fe8 *, unsigned char);
extern void FUN_001a47e8(Self_001a3fe8 *, unsigned char);
extern void FUN_001a48a4(Self_001a3fe8 *, int);
extern void FUN_001a452c(Self_001a3fe8 *);
}

#pragma opt_strength_reduction off
extern "C" void FUN_001a3fe8(Self_001a3fe8 *self)
{
    Ctx_001a3fe8 *ctx = FUN_001feec4();
    self->f2bc = 0;
    FUN_001a4588(self, ctx->f3dc);
    FUN_001a4760(self, ctx->f3c9);
    FUN_001a47a0(self, ctx->f3ca);
    FUN_001a47e8(self, ctx->f3cb);
    int v = ctx->f3dd;
    if (ctx->f3df != 0) {
        v = -1;
    }
    FUN_001a48a4(self, v);
    FUN_001a452c(self);
    self->f314 = 0;
    self->f318 = ctx->f3cf;
    self->f31c = ctx->f3d0;
    self->f328 = 0;
    self->f32c = 0;
    for (unsigned int i = 0; i < self->vec390.size(); i++) {
        for (unsigned int j = 0; j < self->vec390[i].size(); j++) {
            if (ctx->f3d1 != 0 && ctx->f3d1 == self->vec390[i][j]) {
                self->vec330[i][j] = 1;
            } else if (ctx->f3d2 != 0 && ctx->f3d2 == self->vec390[i][j]) {
                self->vec330[i][j] = 1;
            } else {
                self->vec330[i][j] = 0;
            }
        }
    }
}
