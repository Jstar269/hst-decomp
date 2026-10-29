/* HSTMATCH module=EBOOT.BIN start=0x001fd50c end=0x001fd7e8 symbol=FUN_001fd50c lang=c++ data=0x002ef050 */
/* Regulation_InitOnce: data/menu/regulation/reg_param.csv, reg_tall_param.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: V4 (aligned 16) has a user ctor `V4(x,y,z,w)` so every Vec4 is built from register-loaded arguments (the batched lwc1 block, then the stores), a named `V4() {}` default ctor; the dead normalise is an inline wrapper `V4 Norm3(V4 *)` (out-of-line sret call + `r.w = 0`) used as an expression statement so its temporaries sit below the named Vec4 locals; the parameter block pointer `cfg` is hoisted after the loop counter (`int i = 0; Params *p = &self->params; for (; ...)`), the light array is indexed through `self->lights[i]` each time (no element pointer); the file names and the "," separator are anonymous .data placed with data=0x002ef050; names and types await human review. */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }
} __attribute__((aligned(16)));

struct Params {
    float f[21];
};

struct Light {
    char sub[0x1d0];
    V4 pos;
    V4 dir;
    char pad1f0[0x200 - 0x1f0];
    float unk200, unk204, unk208;
    int unk20c, unk210;
    float unk214;
    char pad218[0x2c0 - 0x218];
};

struct RegulationScreen {
    char pad0[0xc8];
    char sub0c8[0xcd0 - 0xc8];
    Light lights[2];
    char pad1250[0x1291 - 0x1250];
    unsigned char initialized;
    char pad1292[2];
    char readerParams[0x30];
    char readerTall[0x12f4 - 0x12c4];
    Params params;
};

extern "C" {
void FUN_002042c8();
void FUN_0017ae48(Params *, char *, const char *, int);
void FUN_000651b8(char *, const char *, int, int, const char *);
float FUN_0000c000(float);
V4 FUN_00022518(const V4 *);
void FUN_0005c7a4(char *, int, V4 *);
void FUN_0005c810(char *, int, V4 *);
void FUN_0005c76c(char *, float, float, float, float);
void FUN_0005bc58(char *);
void FUN_001ffdbc(char *, int);
}

static inline V4 Norm3(V4 *v)
{
    V4 r = FUN_00022518(v);
    r.w = 0.0f;
    return r;
}
/* One-time init: loads the regulation parameter tables and sets up both lights. */
extern "C" void FUN_001fd50c(RegulationScreen *self, int mode)
{
    if (self->initialized == 0) {
        FUN_002042c8();
        FUN_0017ae48(&self->params, self->readerParams, "data/menu/regulation/reg_param.csv", 0x54);
        FUN_000651b8(self->readerTall, "data/menu/regulation/reg_tall_param.csv", 1, 0, ",");
        int i = 0;
        Params *cfg = &self->params;
        for (; i < 2; i++) {
            self->lights[i].unk200 = 25.0f;
            self->lights[i].unk214 = FUN_0000c000(0.008726646f * self->lights[i].unk200);
            self->lights[i].pos = V4(0.0f, self->params.f[1], self->params.f[0], 1.0f);
            self->lights[i].dir = V4(0.0f, 0.0f, -1.0f, 1.0f);
            self->lights[i].unk204 = 1.0f;
            self->lights[i].unk208 = 10.0f;
            self->lights[i].unk210 = 0xf001;
            self->lights[i].unk20c = 0xffff;
            V4 vec0(cfg->f[5], cfg->f[6], cfg->f[7], 0.0f);
            V4 vec1(cfg->f[11], cfg->f[12], cfg->f[13], 0.0f);
            if (vec0.x == 0.0f && vec0.y == 0.0f && vec0.z == 0.0f) {
                V4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                FUN_0005c810(self->lights[i].sub, 0, &zero);
            } else {
                Norm3(&vec0);
                FUN_0005c7a4(self->lights[i].sub, 0, &vec0);
                V4 vec0b(cfg->f[8], cfg->f[9], cfg->f[10], 0.0f);
                FUN_0005c810(self->lights[i].sub, 0, &vec0b);
            }
            if (vec1.x == 0.0f && vec1.y == 0.0f && vec1.z == 0.0f) {
                V4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                FUN_0005c810(self->lights[i].sub, 1, &zero);
            } else {
                Norm3(&vec1);
                FUN_0005c7a4(self->lights[i].sub, 1, &vec1);
                V4 vec1b(cfg->f[14], cfg->f[15], cfg->f[16], 0.0f);
                FUN_0005c810(self->lights[i].sub, 1, &vec1b);
            }
            FUN_0005c76c(self->lights[i].sub, cfg->f[17], cfg->f[18], cfg->f[19], 1.0f);
            FUN_0005bc58(self->lights[i].sub);
        }
        FUN_001ffdbc(self->sub0c8, mode);
        self->initialized = 1;
    }
}
