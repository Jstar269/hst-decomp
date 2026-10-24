/* HSTMATCH module=EBOOT.BIN start=0x001975d4 end=0x00197834 symbol=FUN_001975d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Color {
    float r, g, b, a;
};

struct GlyphDef {
    char *mgr;              // 0x00
    char pad1[0x30 - 4];    // 0x04
    Color color;            // 0x30
    float f40;              // 0x40
    float f44;              // 0x44
    char pad2[0x50 - 0x48]; // 0x48
    unsigned short f50;     // 0x50
    char pad3[0x60 - 0x52]; // 0x52
    float f60;              // 0x60
    float f64;              // 0x64
    char pad4[0x70 - 0x68]; // 0x68
    float f70;              // 0x70
    float f74;              // 0x74
    char pad5[0x80 - 0x78]; // 0x78
    unsigned char f80;      // 0x80
    char pad6[0x84 - 0x81]; // 0x81
    int f84;                // 0x84
};

extern "C" {
extern void FUN_0004315c(void *, float, float, float, float, unsigned short, int);
extern float FUN_00043180(void *, void *);
extern void FUN_00043004(void *, void *);
extern void FUN_00014788(void *, void *);

void FUN_001975d4(GlyphDef *param_1, int *param_2, int *param_3, float *param_4,
                  int param_5, int param_6, void *param_7, float *param_8,
                  unsigned char param_9, int param_10, void *param_11) {
    float f22 = param_8[0] + (param_1->f40 + *param_4);
    float f21 = param_1->f44 + (float)param_5 * (param_8[1] + param_1->f74);
    float f20 = 0.0f;

    if (param_9 != 0) {
        FUN_0004315c(param_1->mgr, f22, f21, param_1->f60, param_1->f64, param_1->f50, param_1->f84);
        f20 = FUN_00043180(param_1->mgr, param_7);

        if (param_1->f80 != 0) {
            float f3 = param_1->color.a;
            if (param_1->f80 == 2) {
                f3 *= 0.8f;
            } else {
                f3 *= 0.5f;
            }

            if (f22 < 480.0f) {
                float f = param_1->f60 * (float)param_6;
                if (f22 + param_1->f60 + (f * (float)*(int *)(param_1->mgr + 0x19098)) / 2.0f >= 0.0f) {
                    if (f21 < 272.0f) {
                        if (f21 + param_1->f64 * (float)*(int *)(param_1->mgr + 0x1909c) >= 0.0f) {
                            float b = param_1->color.b;
                            float g = param_1->color.g;
                            float r = param_1->color.r;
                            Color shadow;
                            shadow.r = r;
                            shadow.g = g;
                            shadow.b = b;
                            shadow.a = f3;

                            FUN_00043004(param_1->mgr, &shadow);
                            FUN_0004315c(param_1->mgr, f22 + param_1->f60, f21, param_1->f60, param_1->f64, param_1->f50, 0);
                            FUN_00043180(param_1->mgr, param_7);
                            FUN_00043004(param_1->mgr, &param_1->color);
                        }
                    }
                }
            }
        }
    }

    if (param_11 != 0) {
        FUN_00014788(param_11, param_7);
    }

    *param_2 += param_6;
    *param_3 += 1;
    *param_4 += f20 + param_1->f70;
}
}
