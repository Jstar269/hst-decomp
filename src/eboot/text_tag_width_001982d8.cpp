/* HSTMATCH module=EBOOT.BIN start=0x001982d8 end=0x001987fc symbol=FUN_001982d8 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: the custom-callback slot address is spelled as a byte offset ((char *)ctx->vars + (c - 0x60) * 4) for retail's offset-first addu; exact match verified; names and types await human review. */
/* Width of one text escape tag (codes 7, 8, 11, 12) for the line-width pass (Sharing twin FUN_001a4c58; called from
   text_layout_line_widths_001987fc.cpp): the tag either just advances the cursor or expands to a string from one of the
   context callbacks, whose glyph widths (plus the style's per-glyph spacing) are added to *width. */
#include "hst/text_draw.h"
#include "hst/glyph_style.h"

/* Escape codes handled by the tag width pass (names after the layout pass that draws them). */
enum { TAG_COLOR = 7, TAG_STRING = 8, TAG_ICON = 11, TAG_SIZE = 12 };

#define ICON_WIDTH 20 /* width added for an inline icon */

extern "C" int FUN_000447b8(TextFont *, unsigned short *, const char *);
extern "C" float FUN_00044858(TextFont *, unsigned short, GlyphStyle *);
extern "C" int FUN_00014a40(const char *);
extern "C" const char *FUN_00198d38(TextDraw *, int);

static inline void AddTextWidth(TextDraw *ctx, int *width, const char *s, GlyphStyle *style)
{
    int len = FUN_00014a40(s);
    int i = 0;
    while (i < len) {
        unsigned short ch;
        int n = FUN_000447b8(ctx->font, &ch, s + i);
        float w = FUN_00044858(ctx->font, ch, style);
        i += n;
        *width = (int)((float)*width + w);
        *width = (int)((float)*width + style->spacing);
    }
}

extern "C" void FUN_001982d8(TextDraw *ctx, int *width, int *adv, unsigned short tag, const char *str, GlyphStyle *style)
{
    switch (tag) {
    case TAG_COLOR:
        *adv += 1;
        break;
    case TAG_STRING:
        *adv += 2;
        if (ctx->fn80 != 0) {
            unsigned short lo = (unsigned char)str[2] - 0x10;
            unsigned short hi = (unsigned short)str[1] & 0xffbf;
            AddTextWidth(ctx, width, ctx->fn8(lo + hi * 0xf0), style);
        }
        break;
    case TAG_SIZE: {
        *adv += 1;
        int c = (unsigned char)str[1];
        if (c >= 0xd0) {
            if (ctx->fnD0 != 0)
                AddTextWidth(ctx, width, ((TextStrFn)ctx->fnD0)(), style);
        } else if (c >= 0xc0) {
            if (ctx->fnC0 != 0)
                AddTextWidth(ctx, width, ctx->fnC0(c - 0xc0), style);
        } else if (c >= 0x80) {
            if (ctx->fn80 != 0)
                AddTextWidth(ctx, width, ctx->fn80(c - 0x80), style);
        }
        break;
    }
    case TAG_ICON: {
        *adv += 1;
        int c = (unsigned char)str[1];
        if (c >= 0x40 && c < 0x4e) {
            *width += ICON_WIDTH;
            *width = (int)((float)*width + style->spacing);
        } else if (c >= 0x60 && c < 0x63) {
            TextStrFn *fp = (TextStrFn *)((char *)ctx->vars + (c - 0x60) * 4);
            if (*fp != 0 && (*fp)() != 0)
                AddTextWidth(ctx, width, (*fp)(), style);
        } else if (c >= 0x80 && c < 0x84) {
            AddTextWidth(ctx, width, FUN_00198d38(ctx, c - 0x80), style);
        }
        break;
    }
    }
}
