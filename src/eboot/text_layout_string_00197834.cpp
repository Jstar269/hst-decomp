/* HSTMATCH module=EBOOT.BIN start=0x00197834 end=0x0019806c symbol=FUN_00197834 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Text-string layout/draw (t_string.cpp): walks a string of glyphs and control codes (FUN_000447b8 returns the
   token length and code); 10 newline, 7 colour (0x5x) or style (0x4x), 8 two-byte callback string, 12 size or
   callback strings, 11 inline icons (queued in the icon list) / variable strings / name slots, 16 a 10x20 glyph
   tile drawn directly; everything else goes to FUN_001975d4. The Sharing twin (0x1a4184) keeps the
   `default: ASSERT(false)` that falls through to case 0x40 (release leaves only a dead `li v0,64`). TextInfo is
   16-byte aligned (frame slot at 96 below the colour); the icon add is an inline member taking its arguments
   (that fixes the scheduling); case 12 reads a plain char and widens it (lb + andi, seb for the size). */
#include "hst/text_draw.h"
#include "hst/text_ctx.h"

struct Color { unsigned char r, g, b, a; };

extern TextCtx *DAT_00341768;
extern const char *DAT_002e1604;
extern const char DAT_002e1600[];   /* "" */
extern const char DAT_002e17e0[];   /* "\n" */
extern const char DAT_002e17e4[];   /* "Error: codeTmp %d" */

extern "C" {
void FUN_000114c0(void *p, int c, unsigned n);
void FUN_00011090(void *d, const void *s, unsigned n);
int FUN_001987fc(TextDraw *self, const char *s, int a, int *widths);
void FUN_000149a8(char *d, const char *s);
void FUN_00014788(char *d, const char *s);
int FUN_000447b8(TextFont *f, unsigned short *code, const char *s);
void FUN_001975d4(TextDraw *self, int *char_count, int *glyph_count, float *pen_x, int line, int len, const char *text, TextInfo *info,
                  int draw, int p5, char *out);
void FUN_00197504(TextDraw *self, int c);
const char *FUN_00198d38(TextDraw *self, int i);
void FUN_0019806c(const char *fmt, ...);
void FUN_00051398(void *tex, float s);
void FUN_00051490(void *tex, int a, int b, int w, int h, int c, int d);
void FUN_00051894(void *tex, Color col, float u0, float v0, float x0, float y0, float u1, float v1,
                  float x1, float y1, float z);
void FUN_0005185c(void *tex);
}

/* Release build: assertions compile to nothing (the Sharing build keeps them, see the twin). */
#define HST_ASSERT(cond, text, line) ((void)0)

/* measure: centre each line using its measured width; draw: emit the glyphs; out: optional buffer receiving the plain text. */
extern "C" void FUN_00197834(TextDraw *self, const char *s, int measure, int draw, int p5, char *out)
{
    unsigned short code;
    char tmp[18];
    int char_count;
    int glyph_count;
    float pen_x;
    float saved_spacing = 0.0f;
    int line_width = 0;
    int widths[10] = {0};
    Color col;
    TextInfo info;

    glyph_count = 0;
    char_count = 0;
    pen_x = 0.0f;
    int line = 0;
    info.lineH = self->cellH * (float)self->font->lineHeight;
    info.off = 0.0f;
    info.z = 0.0f;
    if (measure) {
        FUN_000114c0(widths, 0, sizeof(widths));
        line_width = FUN_001987fc(self, s, 0, widths);
        info.off = (float)((line_width - widths[0]) >> 1);
    }
    if (out)
        FUN_000149a8(out, DAT_002e1600);
    while (*s != 0) {
        int len = FUN_000447b8(self->font, &code, s);
        FUN_00011090(tmp, s, len);
        tmp[len] = 0;
        switch (code) {
        case 10:
            glyph_count = 0;
            char_count = 0;
            pen_x = 0.0f;
            line++;
            if (measure) {
                FUN_000114c0(widths, 0, sizeof(widths));
                FUN_001987fc(self, s + len, 0, widths);
                info.off = (float)((line_width - widths[0]) >> 1);
            }
            if (out)
                FUN_00014788(out, DAT_002e17e0);
            break;
        case 7:
            s++;
            if (draw) {
                char c = *s;
                switch (c & 0xf0) {
                default:
                    HST_ASSERT(false, "false", 783);
                case 0x40:
                    FUN_00197504(self, c - 0x40);
                    break;
                case 0x50: {
                    int v = c - 0x50;
                    self->color = v < 15 ? v + 10 : 0;
                    break;
                }
                }
            }
            break;
        case 8: {
            const char *text = DAT_002e1604;
            s++;
            if (self->fn8) {
                unsigned short lo = (unsigned char)s[1] - 0x10;
                unsigned short hi = (unsigned short)s[0] & 0xffbf;
                text = self->fn8(lo + hi * 0xf0);
            }
            FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, text, &info, draw, p5, out);
            s += len;
            break;
        }
        case 12: {
            s++;
            char ch = *s;
            unsigned char c = ch;
            if (c >= 0xd0) {
                const char *text = DAT_002e1604;
                if (self->fnD0)
                    text = self->fnD0(c);
                FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, text, &info, draw, p5, out);
            } else if (c >= 0xc0) {
                const char *text = DAT_002e1604;
                if (self->fnC0)
                    text = self->fnC0(c - 0xc0);
                FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, text, &info, draw, p5, out);
            } else if (c >= 0x80) {
                const char *text = DAT_002e1604;
                if (self->fn80)
                    text = self->fn80(c - 0x80);
                FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, text, &info, draw, p5, out);
            } else {
                int size = ch - 0x40;
                if (size == 15) {
                    self->spacing = saved_spacing;
                } else {
                    saved_spacing = self->spacing;
                    self->spacing = (float)size;
                }
            }
            break;
        }
        case 11: {
            s++;
            unsigned char c = *s;
            if (c >= 0x40 && c < 0x4e) {
                if (draw)
                    DAT_00341768->Add(c - 0x40, (int)(self->x + pen_x), (int)(self->y + line * (info.lineH + self->lineGap)),
                                      self->cellW, self->cellH);
                pen_x += self->spacing + 20.0f;
            } else if (c >= 0x60 && c < 0x63) {
                const char *text = DAT_002e1604;
                TextStrFn *fn = &self->vars[c - 0x60];
                if (*fn && (*fn)())
                    text = (*fn)();
                FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, text, &info, draw, p5, out);
            } else if (c >= 0x80 && c < 0x84) {
                FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, FUN_00198d38(self, c - 0x80), &info, draw, p5, out);
            } else if (c != 0) {
                FUN_0019806c(DAT_002e17e4, c);
            }
            break;
        }
        case 16: {
            s++;
            signed char c = *s;
            int u = c % 16 * 10;
            int v = c / 16 * 20;
            int px = (int)(self->x + pen_x);
            int py = (int)(self->y + line * (info.lineH + self->lineGap) - 1.0f);
            if (draw) {
                FUN_00051398(self->font->tex, self->font->glyphs->scale);
                FUN_00051490(self->font->tex, 0, 0, 480, 272, 0, 0);
                col.r = 128;
                col.g = 128;
                col.b = 128;
                col.a = 128;
                FUN_00051894(self->font->tex, col, (float)u, (float)v, (float)px, (float)py, (float)(u + 10),
                             (float)(v + 20), (float)(px + 10), (float)(py + 20), (float)(unsigned)self->depth);
                FUN_0005185c(self->font->tex);
            }
            pen_x += self->spacing + 10.0f;
            glyph_count++;
            break;
        }
        default:
            FUN_001975d4(self, &char_count, &glyph_count, &pen_x, line, len, tmp, &info, draw, p5, out);
            break;
        }
        s += len;
    }
    self->shadow = 0;
}
