/* HSTMATCH module=EBOOT.BIN start=0x00220ba8 end=0x00220ed8 symbol=FUN_00220ba8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: both mode tests are switches (a combined case 0/1 group, then case 0 before case 1 in the 100+ branch, because MWCC emits the compare chain in reverse source order), the five stores through self->node come BEFORE the two float scalings (extent = grow*64, alpha_scaled = alpha*128) so the scheduler keeps the retail interleave; names and types await human review. */
#include "hst/fade_pane.h"
#include "hst/sprite_quad.h"

struct Vec { float x, y, z, w; };

/* Pane with a node and two sprite quads, driven by a timer and a mode (0 or 1). */
struct Obj {
    char pad0[0x60];
    int mode;
    int timer;      /* 0x64 negative while idle */
    float grow;     /* 0x68 growth factor of the quads */
    FadeNode *node; /* 0x6c */
    SpriteQuad *q1; /* 0x70 */
    SpriteQuad *q2; /* 0x74 */
};

extern "C" {
extern float DAT_002f0bbc;
extern float DAT_002f0bc0;
extern float DAT_0034a230;
extern Vec DAT_0034a210[];
float FUN_000ede98(float v, float target, float rate, float eps);
void FUN_00103480(Obj *o);
void FUN_00103128(Obj *o);
}

/* One step: eases the node's offset and alpha and the quad growth toward the targets for the current
   mode, resizes both quads, writes the alpha into the first quad's colour and advances the timer. */
extern "C" void FUN_00220ba8(Obj *self)
{
    if (self->timer >= 0) {
        FadeNode *o = self->node;
        float x = o->x;
        float y = o->y;
        float alpha = o->alpha;
        float grow = self->grow;
        if (self->timer < 100) {
            switch (self->mode) {
            case 0:
            case 1:
                x = FUN_000ede98(x, 0.0f, DAT_002f0bbc, 1.0f);
                y = FUN_000ede98(y, 0.0f, DAT_002f0bbc, 1.0f);
                alpha = FUN_000ede98(alpha, 1.0f, DAT_002f0bbc, 0.01f);
                grow = FUN_000ede98(grow, 1.0f, DAT_002f0bbc, 0.01f);
                break;
            }
        } else {
            switch (self->mode) {
            case 0:
                x = FUN_000ede98(x, DAT_0034a210[self->mode].x, DAT_002f0bbc * 0.5f, 1.0f);
                y = FUN_000ede98(y, DAT_0034a210[self->mode].y, DAT_002f0bbc * 0.5f, 1.0f);
                grow = FUN_000ede98(grow, DAT_002f0bc0, 0.1f, 0.01f);
                break;
            case 1:
                alpha = FUN_000ede98(alpha, DAT_0034a230, DAT_002f0bbc, 0.01f);
                break;
            }
        }
        self->node->x = x;
        self->node->y = y;
        self->node->unk6c = 1.0f;
        self->node->alpha = alpha;
        self->grow = grow;
        float extent = grow * 64.0f;
        float alpha_scaled = alpha * 128.0f;
        self->q1->x1 = (short)(int)((float)self->q1->x0 + extent);
        self->q1->y1 = (short)(int)((float)self->q1->y0 + extent);
        self->q2->x1 = (short)(int)((float)self->q2->x0 + extent);
        self->q2->y1 = (short)(int)((float)self->q2->y0 + extent);
        unsigned int alpha_byte = (unsigned char)(unsigned int)alpha_scaled;
        self->q1->color = (self->q1->color & 0xffffff) | (alpha_byte << 24);
        FUN_00103480(self);
        self->timer = self->timer + 1;
    }
    FUN_00103128(self);
}
