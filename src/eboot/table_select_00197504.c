/* HSTMATCH module=EBOOT.BIN start=0x00197504 end=0x001975d4 symbol=FUN_00197504 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/text_draw.h"

#define PALETTE_SIZE 13

extern float DAT_002c28e0[][4];
extern float DAT_002c28e4[][4];
extern float DAT_002c28e8[][4];
extern float DAT_002c29b0[][4];
extern float DAT_002c29b4[][4];
extern float DAT_002c29b8[][4];
extern void FUN_00043004(void *, TextColor *);

/* Pick the text colour from the palette row for `which` (alternate palette when alt is set) and scale the base colour by it. */
void FUN_00197504(TextDraw *self, unsigned int which)
{
    int idx = which % PALETTE_SIZE;
    float c;
    float b;
    float a;
    float d;

    if (self->alt != 0) {
        a = DAT_002c28e0[idx][0];
        b = DAT_002c28e4[idx][0];
        c = DAT_002c28e8[idx][0];
    } else {
        a = DAT_002c29b0[idx][0];
        b = DAT_002c29b4[idx][0];
        c = DAT_002c29b8[idx][0];
    }
    d = self->col.a;
    self->col.r = a;
    self->col.g = b;
    self->col.b = c;
    self->col.a = d;
    self->tint.r = a * self->base.r;
    self->tint.g = b * self->base.g;
    self->tint.b = c * self->base.b;
    self->tint.a = d * self->base.a;
    FUN_00043004(self->font, &self->tint);
}
