/* HSTMATCH module=hstp_trans_main.prx start=0x001a4c58 end=0x001a517c symbol=FUN_001a4c58 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: the custom-callback slot address is spelled as a byte offset ((char *)ctx->custom + (c - 0x60) * 4) for retail's offset-first addu; exact match verified; names and types await human review. */
/* Width of one text escape tag (codes 7, 8, 11, 12) for the line-width pass (EBOOT twin FUN_001982d8, called from
   text_layout_line_widths_001987fc.cpp): the tag either just advances the cursor or expands to a string from one of the
   context callbacks, whose glyph widths (plus the style's per-glyph spacing) are added to *width. */
struct Style {
    float field_0;
    float field_4;
    unsigned short field_8;
    float scale_x;
    float scale_y;
    float pad_20;
};

typedef const char *(*TextFn)(void);
typedef const char *(*TextFnI)(int);
typedef const char *(*TextFnU)(unsigned short);

struct TextContext {
    void *font;
    char pad_04[0x8c - 4];
    TextFn custom[3];
    TextFnI fn98;
    TextFnU fn9c;
    char names[4][8];
    TextFnI fnc0;
    TextFn fnc4;
};

extern "C" int FUN_0004495c(void *, unsigned short *, const char *);
extern "C" float FUN_000449fc(void *, unsigned short, Style *);
extern "C" int FUN_00014a40(const char *);
extern "C" const char *FUN_001a573c(TextContext *, int);

static inline void AddTextWidth(TextContext *ctx, int *width, const char *s, Style *style)
{
    int len = FUN_00014a40(s);
    int i = 0;
    while (i < len) {
        unsigned short ch;
        int n = FUN_0004495c(ctx->font, &ch, s + i);
        float w = FUN_000449fc(ctx->font, ch, style);
        i += n;
        *width = (int)((float)*width + w);
        *width = (int)((float)*width + style->pad_20);
    }
}

extern "C" void FUN_001a4c58(TextContext *ctx, int *width, int *adv, unsigned short tag, const char *str, Style *style)
{
    switch (tag) {
    case 7:
        *adv += 1;
        break;
    case 8:
        *adv += 2;
        if (ctx->fn98 != 0) {
            unsigned short lo = (unsigned char)str[2] - 0x10;
            unsigned short hi = (unsigned short)str[1] & 0xffbf;
            AddTextWidth(ctx, width, ctx->fn9c(lo + hi * 0xf0), style);
        }
        break;
    case 12: {
        *adv += 1;
        int c = (unsigned char)str[1];
        if (c >= 0xd0) {
            if (ctx->fnc4 != 0)
                AddTextWidth(ctx, width, ctx->fnc4(), style);
        } else if (c >= 0xc0) {
            if (ctx->fnc0 != 0)
                AddTextWidth(ctx, width, ctx->fnc0(c - 0xc0), style);
        } else if (c >= 0x80) {
            if (ctx->fn98 != 0)
                AddTextWidth(ctx, width, ctx->fn98(c - 0x80), style);
        }
        break;
    }
    case 11: {
        *adv += 1;
        int c = (unsigned char)str[1];
        if (c >= 0x40 && c < 0x4e) {
            *width += 20;
            *width = (int)((float)*width + style->pad_20);
        } else if (c >= 0x60 && c < 0x63) {
            TextFn *fp = (TextFn *)((char *)ctx->custom + (c - 0x60) * 4);
            if (*fp != 0 && (*fp)() != 0)
                AddTextWidth(ctx, width, (*fp)(), style);
        } else if (c >= 0x80 && c < 0x84) {
            AddTextWidth(ctx, width, FUN_001a573c(ctx, c - 0x80), style);
        }
        break;
    }
    }
}
