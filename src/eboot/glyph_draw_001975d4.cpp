/* HSTMATCH module=EBOOT.BIN start=0x001975d4 end=0x00197834 symbol=FUN_001975d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/text_draw.h"

enum { SCREEN_W = 480, SCREEN_H = 272 };
enum { SHADOW_LIGHT = 2 }; /* shadow style drawn at 0.8 alpha; others use 0.5 */

extern "C" {
extern void FUN_0004315c(void *, float, float, float, float, unsigned short, int);
extern float FUN_00043180(void *, void *);
extern void FUN_00043004(void *, void *);
extern void FUN_00014788(void *, void *);

/* Draw one glyph string at the current pen position (with a drop shadow when a shadow style is set), append it to
   the output buffer and advance the byte count, glyph count and pen x. */
void FUN_001975d4(TextDraw *self, int *bytes, int *glyphs, float *pen_x,
                  int line, int len, void *str, TextInfo *info,
                  unsigned char draw, int p5, void *out) {
    float x = info->off + (self->x + *pen_x);
    float y = self->y + (float)line * (info->lineH + self->lineGap);
    float width = 0.0f;

    if (draw != 0) {
        FUN_0004315c(self->font, x, y, self->cellW, self->cellH, self->depth, self->color);
        width = FUN_00043180(self->font, str);

        if (self->shadow != 0) {
            float shadow_alpha = self->tint.a;
            if (self->shadow == SHADOW_LIGHT) {
                shadow_alpha *= 0.8f;
            } else {
                shadow_alpha *= 0.5f;
            }

            if (x < SCREEN_W) {
                float run = self->cellW * (float)len;
                if (x + self->cellW + (run * (float)self->font->unk19098) / 2.0f >= 0.0f) {
                    if (y < SCREEN_H) {
                        if (y + self->cellH * (float)self->font->lineHeight >= 0.0f) {
                            float b = self->tint.b;
                            float g = self->tint.g;
                            float r = self->tint.r;
                            TextColor shadow;
                            shadow.r = r;
                            shadow.g = g;
                            shadow.b = b;
                            shadow.a = shadow_alpha;

                            FUN_00043004(self->font, &shadow);
                            FUN_0004315c(self->font, x + self->cellW, y, self->cellW, self->cellH, self->depth, 0);
                            FUN_00043180(self->font, str);
                            FUN_00043004(self->font, &self->tint);
                        }
                    }
                }
            }
        }
    }

    if (out != 0) {
        FUN_00014788(out, str);
    }

    *bytes += len;
    *glyphs += 1;
    *pen_x += width + self->spacing;
}
}
