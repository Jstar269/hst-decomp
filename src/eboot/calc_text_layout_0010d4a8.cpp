/* HSTMATCH module=EBOOT.BIN start=0x0010d4a8 end=0x0010d698 symbol=FUN_0010d4a8 lang=c++ */
/* Clone of src/sharing_main/calc_text_layout_00113a50.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: C++ struct layout, const-ref Clamp helper, and switch statement for alignment mode; exact match verified; names and types await human review. */
struct Self_0010d4a8 {
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
extern char DAT_002c10dc[];
extern float DAT_002d9224;
extern float DAT_002d9228;
extern float DAT_002d922c;
extern float DAT_002d9230;
extern int DAT_0034176c;
extern int DAT_003417a4;
extern int FUN_001987fc(int, int, char *, int);
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" void FUN_0010d4a8(Self_0010d4a8 *self)
{
    if (self->f0f8 != 0 && self->f14c == 0) {
        float w = (float)FUN_001987fc(DAT_0034176c, self->f0f8, DAT_002c10dc, 0);
        float base_h;
        if (DAT_003417a4 < 9) {
            base_h = 10.0f;
        } else {
            base_h = 16.0f;
        }
        w *= self->f108;
        base_h *= self->f10c;
        self->f0fc = 0;
        self->f0fe = 0;
        float dh = (float)(self->f102 - self->f0fe);
        self->f114 = Clamp(dh / base_h, DAT_002d9224, DAT_002d9228);
        float dw = (float)(self->f100 - self->f0fc);
        self->f110 = Clamp(dw / (w * self->f114), DAT_002d922c, DAT_002d9230);
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
