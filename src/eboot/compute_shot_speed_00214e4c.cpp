/* HSTMATCH module=EBOOT.BIN start=0x00214e4c end=0x002150fc symbol=FUN_00214e4c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"

struct Vec4 {
    float x, y, z, w;
};

struct Player {
    char pad0[0x154];
    int f154;               /* 0x154 */
    char pad1[0x580 - 0x158];
    Vec4 f580;              /* 0x580 */
    char pad2[0x869 - 0x590];
    unsigned char f869;     /* 0x869 */
    char pad3[0x880 - 0x86a];
    Vec4 f880;              /* 0x880 */
    Vec4 f890;              /* 0x890 */
    char pad4[0x8a5 - 0x8a0];
    unsigned char f8a5;     /* 0x8a5 */
};

struct Cfg {
    char pad0[0x45];
    unsigned char f45;      /* 0x45 */
    char pad1[0x5c - 0x46];
    unsigned char f5c;      /* 0x5c */
};

struct A30 {
    char pad0[0x1c];
    float f1c;              /* 0x1c */
};

struct A124 {
    char pad0[0x58];
    float f58;              /* 0x58 */
    float f5c;              /* 0x5c */
    char pad1[0x204 - 0x60];
    float f204;             /* 0x204 */
};

extern "C" {
extern Cfg *DAT_00338b44;
extern const float DAT_002bfccc;
extern const float DAT_002ef9bc;
extern const float DAT_002ef9c0;
extern const float DAT_002ef9c4;

float sqrtf(float);
u32 FUN_0001342c(void);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022498(Vec4 *, const Vec4 *, float);
int FUN_000b3c68(Player *);
float FUN_00163d68(int, int);
A124 *FUN_00215a20(Player *);
A124 *FUN_00215a58(Player *);
A30 *FUN_00215ab8(Player *);
}

static inline float Max(const float &a, const float &b) { return !(a > b) ? b : a; }
static inline float Min(const float &a, const float &b) { return !(a > b) ? a : b; }

extern "C" void FUN_00214e4c(Player *self, const Vec4 *param_2, int param_3)
{
    if (DAT_00338b44->f5c == 0) {
        self->f880.x = param_2->x;
        self->f880.y = param_2->y;
        self->f880.z = param_2->z;
        self->f880.w = param_2->w;
        self->f880.z = Min(self->f880.z, DAT_002bfccc);
        self->f869 = 1;
        self->f890.w = -1.0f;

        if (param_3 != 0) {
            Vec4 diff;
            float unit_len;
            float dist;
            float scale;
            float z;
            float span;
            float base;
            float x;

            FUN_00022434(&diff, &self->f880, &self->f580);
            dist = sqrtf(diff.x * diff.x + diff.z * diff.z);
            unit_len = FUN_00163d68(FUN_000b3c68(self), self->f154) * 0.01f;
            dist = (0.7f * (dist / unit_len)) * ((float)(int)(FUN_0001342c() & 0xfffff800) * 4.656613e-10f);

            if (self->f8a5 != 0) {
                float s = FUN_00215a58(self)->f5c + FUN_00215a20(self)->f5c;
                scale = 0.01f * Max(DAT_002ef9bc, s);
            } else if (DAT_00338b44->f45 != 0) {
                float s = FUN_00215a58(self)->f58 + FUN_00215a20(self)->f58;
                scale = 0.01f * Max(DAT_002ef9c0, s);
            } else {
                float s = FUN_00215ab8(self)->f1c + FUN_00215a20(self)->f204;
                scale = 0.01f * Max(DAT_002ef9c4, s);
            }

            span = 4.656613e-10f * (scale + scale);
            base = -scale;
            z = base + span * (float)(int)(FUN_0001342c() & 0xfffff800);
            x = base + span * (float)(int)(FUN_0001342c() & 0xfffff800);

            self->f890.x = x;
            self->f890.y = 0.0f;
            self->f890.z = z;
            self->f890.w = 0.0f;

            FUN_00022498(&self->f890, &self->f890, 1.0f / dist);
            self->f890.w = dist;
        }
    }
}
// The random factors are written with the FUN_0001342c() call inside the expression (as a FRAND-style macro would
// expand). MWCC orders commutative operands by Sethi-Ullman weight, lighter operand first (fs), a call being the
// heaviest; with the call result held in a local first, the random product (weight 1) outweighed nothing and took fs
// of the final mul.s (1 word off); with the call in the operand, `0.7f * (dist / unit_len)` keeps fs like retail.
