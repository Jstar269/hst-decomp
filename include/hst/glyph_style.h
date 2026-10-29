/* Per-run glyph style record handed to the glyph width and height queries of the text layout sources. */
#ifndef HST_GLYPH_STYLE_H
#define HST_GLYPH_STYLE_H

typedef struct GlyphStyle {
    float x;             /* 0x00 */
    float y;             /* 0x04 */
    unsigned short w8;   /* 0x08 */
    float scaleX;        /* 0x0c width scale (from the text object's cell width) */
    float scaleY;        /* 0x10 height scale (from the text object's cell height) */
    float spacing;       /* 0x14 extra advance added after each glyph */
    float lineGap;       /* 0x18 extra height added to each glyph's line height */
    char fixedPitch;     /* 0x1c nonzero selects a fixed glyph pitch */
    short unk1e;         /* 0x1e */
    short unk20;         /* 0x20 */
    short unk22;         /* 0x22 */
    short unk24;         /* 0x24 */
} GlyphStyle;

#endif
