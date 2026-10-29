/* HSTMATCH module=hstp_trans_main.prx start=0x001dc5f4 end=0x001dc6fc symbol=FUN_001dc5f4 lang=c++ */
/* Clone of src/eboot/range_check_001cdf18.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (ds11 near-miss restructured: derived-to-base pointer compare, 16-aligned Vec4 buffers, && chain returning !ok); exact match verified; names and types await human review. */
extern "C" {
int FUN_001dc504(int h);
int FUN_001dc704(void *self, int h);
int FUN_001dc6fc(int h);
void FUN_00054e34(void *dst, int v, void *src);
void FUN_000c77a0(void *dst, const void *src);
float FUN_001dc484(void *self, const void *src);
float FUN_001dc444(float *state, const float *lo, const float *hi);
float FUN_0000c5d4(float v);

extern float DAT_00391f34;
extern float DAT_00391f38;
}
struct Vec4_001dc5f4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj_001dc5f4 {
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int V3();
    virtual int V4();
    virtual int V5();
    virtual int V6();
};

struct B0_001dc5f4 { char pad[0xe0]; };
struct Der_001dc5f4 : B0_001dc5f4, Obj_001dc5f4 {};
extern Der_001dc5f4 *DAT_003f3450;

extern "C" bool FUN_001dc5f4(char *self, int *handle)
{
    Obj_001dc5f4 *h = (Obj_001dc5f4 *)*handle;
    bool r;
    if (FUN_001dc504((int)h) && FUN_001dc704(self, (int)h) && h != DAT_003f3450 && FUN_001dc6fc((int)h) < 1000) {
    float v;
    Vec4_001dc5f4 buf2;
    Vec4_001dc5f4 buf1;
    FUN_00054e34(&buf1, h->V6(), self + 0x30);
    FUN_000c77a0(&buf2, &buf1);
    v = FUN_001dc484(self + 0x20, &buf2);
    float d = FUN_001dc444(&v, &DAT_00391f34, &DAT_00391f38);
    r = FUN_0000c5d4(d) < *(float *)(self + 0x40);
    } else {
        r = false;
    }
    return !r;
}
