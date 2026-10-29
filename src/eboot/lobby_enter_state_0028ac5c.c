/* HSTMATCH module=EBOOT.BIN start=0x0028ac5c end=0x0028ad5c symbol=FUN_0028ac5c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/effect_source.h"

typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Mat4Rows { Vec4 r0, r1, r2, r3; } Mat4Rows;

/* Game object: only the words read here are named. */
typedef struct GameCtx {
    char pad00[0xcc];
    int unkcc;                  /* 0xcc */
    int unkd0;                  /* 0xd0 */
    char padd4[0x17c - 0xd4];
    int unk17c;                 /* 0x17c */
} GameCtx;

extern void FUN_001c6bec(void *ctx, int a, int b, int c, int d, int e);
extern void FUN_0028adc4(void);
extern void FUN_00055240(Mat4Rows *buf, ModelHolder *src, int mode);
extern void FUN_0028c204(int ctx, char *obj, Vec4 *vec, float value);
extern void FUN_0022ca9c(int a, int b, int c, int d);
extern int FUN_00014a40(char *text);
extern void FUN_001b28f0(void *ctx, char *text);
extern GameCtx *DAT_0034a114;
extern char DAT_0034179c[];

/* Starts the effect: already started -> notify the game; otherwise bind the holder's matrix position and node value, mark started, and play the named sound if there is one. */
void FUN_0028ac5c(EffectSource *self)
{
    if (self->started != 0) {
        FUN_001c6bec(DAT_0034a114, -1, -1, self->unka8, 0, 0);
    } else {
        FUN_0028adc4();
        ModelHolder *holder = self->modelA;
        ModelNode *node = holder->node;
        float value;
        if (node != 0)
            value = node->item->value;
        else
            value = 0.0f;
        Vec4 v;
        Mat4Rows buf;
        FUN_00055240(&buf, holder, self->effect);
        v = buf.r3;
        FUN_0028c204(DAT_0034a114->unk17c, self->unk80, &v, value);
        self->started = 1;
        FUN_0022ca9c(DAT_0034a114->unkcc, DAT_0034a114->unkd0,
                     self->unk88, 1);
        if (FUN_00014a40(self->name) != 0)
            FUN_001b28f0(DAT_0034179c, self->name);
    }
}
