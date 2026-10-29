/* Text drawing object: font, colours, cell size and the string callbacks used by the string layout. */
#ifndef HST_TEXT_DRAW_H
#define HST_TEXT_DRAW_H

typedef struct TextGlyphs {
    char pad00[0x18];
    float scale; /* 0x18 */
} TextGlyphs;

typedef struct TextFont {
    char pad00[0x19074];
    TextGlyphs *glyphs; /* 0x19074 */
    char pad19078[0x19080 - 0x19078];
    void *tex; /* 0x19080 */
    char pad19084[0x19098 - 0x19084];
    int unk19098; /* 0x19098 */
    int lineHeight; /* 0x1909c */
} TextFont;

typedef struct TextColor {
    float r, g, b, a;
} TextColor;

typedef const char *(*TextStrFn)();
typedef const char *(*TextStrFnI)(int);
typedef const char *(*TextStrFnU)(unsigned short);

typedef struct TextDraw {
    TextFont *font; /* 0x00 */
    char pad04[0x10 - 0x04];
    TextColor col; /* 0x10 */
    TextColor base; /* 0x20 */
    TextColor tint; /* 0x30 current draw colour */
    float x; /* 0x40 */
    float y; /* 0x44 */
    char pad48[0x50 - 0x48];
    unsigned short depth; /* 0x50 */
    char pad52[0x60 - 0x52];
    float cellW; /* 0x60 also the icon width */
    float cellH; /* 0x64 */
    char pad68[0x70 - 0x68];
    float spacing; /* 0x70 extra advance after each string */
    float lineGap; /* 0x74 */
    char pad78[0x80 - 0x78];
    unsigned char shadow; /* 0x80 drop shadow style (0 = none), cleared after a layout pass */
    char pad81[0x84 - 0x81];
    int color; /* 0x84 */
    unsigned char alt; /* 0x88 selects the alternate palette */
    char pad89[0x8c - 0x89];
    TextStrFn vars[3]; /* 0x8c */
    TextStrFnI fn80; /* 0x98 */
    TextStrFnU fn8; /* 0x9c */
    char names[4][8]; /* 0xa0 */
    TextStrFnI fnC0; /* 0xc0 */
    TextStrFnI fnD0; /* 0xc4 */
} TextDraw;

/* Per-line layout state passed to the glyph drawer. */
typedef struct TextInfo {
    float off;
    float lineH;
    float z;
    float w;
} __attribute__((aligned(16))) TextInfo;

#endif
