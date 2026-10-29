/* HSTMATCH module=EBOOT.BIN start=0x001987fc end=0x00198aa8 symbol=FUN_001987fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/text_draw.h"
#include "hst/glyph_style.h"

#define NEWLINE_CODE 10

extern "C" int FUN_000447b8(TextFont *, unsigned short *, const char *);
extern "C" int FUN_00198cb8(TextDraw *, unsigned short *);
extern "C" void FUN_001982d8(TextDraw *, int *, int *, unsigned short, const char *, GlyphStyle *);
extern "C" float FUN_00044858(TextFont *, unsigned short, GlyphStyle *);

/* Measures the widest line of str (lines end at newline tokens). When out_widths is given, each line's width is stored
   in it, including the last line. A one-byte token that is an escape (codes 7, 8, 11, 12) is measured by its own
   helper; other tokens add the glyph width plus the style's per-glyph spacing. */
extern "C" int FUN_001987fc(TextDraw *ctx, const char *str, const GlyphStyle *style_in, int *out_widths)
{
    int max_width = 0;
    unsigned short tag;
    int current_line_width = 0;
    GlyphStyle style;
    style.scaleX = 1.0f;
    style.scaleY = 1.0f;
    style.unk22 = -32;
    style.x = 0.0f;
    style.y = 0.0f;
    style.w8 = 0;
    style.spacing = 0.0f;
    style.lineGap = 0.0f;
    style.fixedPitch = 0;
    style.unk1e = 0;
    style.unk20 = 0;
    style.unk24 = 16;

    int line_count = 0;
    int adv;

    if (style_in != 0) {
        style = *style_in;
    } else {
        style.scaleX = ctx->cellW;
        style.scaleY = ctx->cellH;
        style.spacing = ctx->spacing;
        style.lineGap = ctx->lineGap;
        style.fixedPitch = (char)ctx->color;
    }

    if (*str != '\0') {
        int *out_ptr = out_widths;
        do {
            adv = FUN_000447b8(*(TextFont * volatile *)&ctx->font, &tag, str);
            if (tag == NEWLINE_CODE) {
                if (max_width < current_line_width) {
                    max_width = current_line_width;
                }
                if (out_widths != 0) {
                    *out_ptr = current_line_width;
                }
                out_ptr++;
                current_line_width = 0;
                line_count++;
            } else {
                switch (adv) { /* token length in bytes */
                case 1:
                    if (FUN_00198cb8(ctx, &tag)) {
                        FUN_001982d8(ctx, &current_line_width, &adv, *(volatile unsigned short *)&tag, str, &style);
                        break;
                    } else {
                        float w = FUN_00044858(*(TextFont * volatile *)&ctx->font, *(volatile unsigned short *)&tag, &style);
                        float t = (float)(int)((float)current_line_width + w);
                        current_line_width = (int)(t + style.spacing);
                        break;
                    }
                case 2:
                case 3:
                    {
                        float w = FUN_00044858(*(TextFont * volatile *)&ctx->font, *(volatile unsigned short *)&tag, &style);
                        float t = (float)(int)((float)current_line_width + w);
                        current_line_width = (int)(t + style.spacing);
                    }
                    break;
                default:
                    break;
                }
            }
            str += adv;
        } while (*str != '\0');
    }

    if (tag != NEWLINE_CODE) {
        if (max_width < current_line_width) {
            max_width = current_line_width;
        }
    }

    if (out_widths != 0) {
        out_widths[line_count] = current_line_width;
    }

    return max_width;
}
