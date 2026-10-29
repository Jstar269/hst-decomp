/* HSTMATCH module=EBOOT.BIN start=0x001cdf18 end=0x001ce020 symbol=FUN_001cdf18 lang=c++ */
/* Hand-written reconstruction from the disassembly (ds11 near-miss restructured: derived-to-base pointer compare, 16-aligned Vec4 buffers, && chain returning !ok); exact match verified; names and types await human review. */
extern "C" {
int FUN_001cde28(int h);
int FUN_001ce028(void *self, int h);
int FUN_001ce020(int h);
void FUN_000542e8(void *dst, int v, void *src);
void FUN_000c3f38(void *dst, const void *src);
float FUN_001cdda8(void *self, const void *src);
float FUN_001cdd68(float *state, const float *lo, const float *hi);
float FUN_0000c5bc(float v);

extern float DAT_002ea2dc;
extern float DAT_002ea2e0;
}
struct Vec4_001cdf18 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj_001cdf18 {
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int V3();
    virtual int V4();
    virtual int V5();
    virtual int V6();
};

struct B0_001cdf18 { char pad[0xe0]; };
struct Der_001cdf18 : B0_001cdf18, Obj_001cdf18 {};
extern Der_001cdf18 *DAT_0034a118;

extern "C" bool FUN_001cdf18(char *self, int *handle)
{
    Obj_001cdf18 *h = (Obj_001cdf18 *)*handle;
    bool r;
    if (FUN_001cde28((int)h) && FUN_001ce028(self, (int)h) && h != DAT_0034a118 && FUN_001ce020((int)h) < 1000) {
    float v;
    Vec4_001cdf18 buf2;
    Vec4_001cdf18 buf1;
    FUN_000542e8(&buf1, h->V6(), self + 0x30);
    FUN_000c3f38(&buf2, &buf1);
    v = FUN_001cdda8(self + 0x20, &buf2);
    float d = FUN_001cdd68(&v, &DAT_002ea2dc, &DAT_002ea2e0);
    r = FUN_0000c5bc(d) < *(float *)(self + 0x40);
    } else {
        r = false;
    }
    return !r;
}
