/* HSTMATCH module=EBOOT.BIN start=0x00198aa8 end=0x00198cb8 symbol=FUN_00198aa8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Measures the pixel height of a text string (sibling of text_layout_string_00197834.cpp and copy_string_tokens_00198098.cpp; called in set_text_and_measure_0010ef0c.cpp to compute o->f904): initializes the style with default values (scales 1, unk22=-32, unk24=16) or copies the one passed in; walks string tokens with FUN_000447b8; control codes 7,8,11,12 skipped via FUN_00198cb8; '*Y' adds single-digit vertical skip; newline adds line height and resets line height to 0; other glyphs query FUN_0004490c and update line height. */
#include "hst/text_draw.h"
#include "hst/glyph_style.h"

#define DEFAULT_LINE_HEIGHT 16.0f /* line height before any glyph is seen */
#define NEWLINE_CODE 10
#define SKIP_ESCAPE 0x2a          /* '*' starts a two-character vertical-skip escape ('Y' then a digit) */

/* Fills a style record with the default values the layout starts from. */
static inline void SetDefaults(GlyphStyle &r)
{
    r.x = 0.0f;
    r.y = 0.0f;
    r.w8 = 0;
    r.scaleX = 1.0f;
    r.scaleY = 1.0f;
    r.spacing = 0.0f;
    r.lineGap = 0.0f;
    r.fixedPitch = 0;
    r.unk1e = 0;
    r.unk20 = 0;
    r.unk22 = -32;
    r.unk24 = 16;
}

struct TokenRec {
    unsigned short kind;
};

extern "C" {
extern int FUN_000447b8(TextFont *, unsigned short *, const char *);
extern int FUN_00198cb8(TextDraw *, TokenRec *);
extern float FUN_0004490c(TextFont *, unsigned short, GlyphStyle *);
}

extern "C" int FUN_00198aa8(TextDraw *self, const char *s, GlyphStyle *style_in)
{
    GlyphStyle rec;
    SetDefaults(rec);
    float lineH = DEFAULT_LINE_HEIGHT;
    float totalH = 0.0f;

    if (style_in != 0) {
        rec = *style_in;
    } else {
        rec.scaleX = self->cellW;
        rec.scaleY = self->cellH;
        rec.spacing = self->spacing;
        rec.lineGap = self->lineGap;
        rec.fixedPitch = (char)self->color;
    }

    unsigned short code;
    while (*s != '\0') {
        int len = FUN_000447b8(self->font, &code, s);
        if (FUN_00198cb8(self, (TokenRec *)&code) != 0) {
            len++;
        } else {
            int c = code;
            if (c == SKIP_ESCAPE && s[1] == 'Y') {
                totalH += (float)(s[2] - '0');
                s += 2;
            } else if (c == NEWLINE_CODE) {
                totalH += lineH;
                lineH = 0.0f;
            } else {
                float h = rec.lineGap + FUN_0004490c(*(TextFont * volatile *)&self->font, *(volatile unsigned short *)&code, &rec);
                if (lineH < h) {
                    lineH = h;
                }
            }
        }
        s += len;
    }

    if (code != NEWLINE_CODE && FUN_00198cb8(self, (TokenRec *)&code) == 0) {
        totalH += lineH;
    }
    return (int)totalH;
}
