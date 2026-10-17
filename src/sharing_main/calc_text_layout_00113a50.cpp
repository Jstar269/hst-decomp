/* HSTMATCH module=hstp_trans_main.prx start=0x00113a50 end=0x00113c40 symbol=FUN_00113a50 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: C++ struct layout, const-ref Clamp helper, and switch statement for alignment mode; exact match verified; names and types await human review. */
struct Self_00113a50 {
    char pad00[0xf8];
    int f0f8;
    short f0fc;
    short f0fe;
    short f100;
    short f102;
    char pad104[4];
    float f108;
    float f10c;
    float f110;
    float f114;
    char pad118[0x138 - 0x118];
    int f138;
    char pad13c[0x14c - 0x13c];
    unsigned char f14c;
};

extern "C" {
extern char DAT_002d14bc[];
extern float DAT_0037fff8;
extern float DAT_0037fffc;
extern float DAT_00380000;
extern float DAT_00380004;
extern int DAT_003eaaac;
extern int DAT_003eaae0;
extern int FUN_001a517c(int, int, char *, int);
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" void FUN_00113a50(Self_00113a50 *self)
{
    if (self->f0f8 != 0 && self->f14c == 0) {
        float w = (float)FUN_001a517c(DAT_003eaaac, self->f0f8, DAT_002d14bc, 0);
        float base_h;
        if (DAT_003eaae0 < 9) {
            base_h = 10.0f;
        } else {
            base_h = 16.0f;
        }
        w *= self->f108;
        base_h *= self->f10c;
        self->f0fc = 0;
        self->f0fe = 0;
        float dh = (float)(self->f102 - self->f0fe);
        self->f114 = Clamp(dh / base_h, DAT_0037fff8, DAT_0037fffc);
        float dw = (float)(self->f100 - self->f0fc);
        self->f110 = Clamp(dw / (w * self->f114), DAT_00380000, DAT_00380004);
        int mode = self->f138;
        short rem_w = (short)(int)(dw - self->f110 * (w * self->f114));
        switch (mode) {
        case 1:
            self->f0fc = rem_w / 2;
            break;
        case 2:
            self->f0fc = rem_w;
            break;
        case 0:
            break;
        }
        short rem_h = (short)(int)(dh - base_h * self->f114);
        self->f0fe = rem_h / 2;
    }
}
