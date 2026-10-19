/* HSTMATCH module=EBOOT.BIN start=0x00198aa8 end=0x00198cb8 symbol=FUN_00198aa8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Measures the pixel height of a text string (sibling of text_layout_string_00197834.cpp and copy_string_tokens_00198098.cpp; called in set_text_and_measure_0010ef0c.cpp to compute o->f904): initializes Rec with default values (f0c=f10=1, f22=-32, f24=16) or copies param_3; walks string tokens with FUN_000447b8; control codes 7,8,11,12 skipped via FUN_00198cb8; '*Y' adds single-digit vertical skip; newline adds line height and resets line height to 0; other glyphs query FUN_0004490c and update line height. */

struct Font;

struct Glyphs {
    char pad0[0x18];
    float scale;
};

struct Text {
    Font *font;             /* 0x00 */
    char pad04[0x40 - 0x04];
    float x;                /* 0x40 */
    float y;                /* 0x44 */
    char pad48[0x50 - 0x48];
    unsigned short depth;   /* 0x50 */
    char pad52[0x60 - 0x52];
    float iconW;            /* 0x60 */
    float scale;            /* 0x64 */
    char pad68[0x70 - 0x68];
    float charSize;         /* 0x70 */
    float lineGap;          /* 0x74 */
    char pad78[0x80 - 0x78];
    unsigned char busy;     /* 0x80 */
    char pad81[0x84 - 0x81];
    int color;              /* 0x84 */
};

struct Rec {
    float x;            /* 0x00 */
    float y;            /* 0x04 */
    unsigned short w8;  /* 0x08 */
    float f0c;          /* 0x0c */
    float f10;          /* 0x10 */
    float f14;          /* 0x14 */
    float f18;          /* 0x18 */
    char f1c;           /* 0x1c */
    short f1e;          /* 0x1e */
    short f20;          /* 0x20 */
    short f22;          /* 0x22 */
    short f24;          /* 0x24 */

    Rec() : f0c(1.0f), f10(1.0f), f22(-32), f24(16), x(0.0f), y(0.0f), w8(0), f14(0.0f), f18(0.0f), f1c(0), f1e(0), f20(0) {}
};

struct TokenRec {
    unsigned short kind;
};

extern "C" {
extern int FUN_000447b8(Font *, unsigned short *, const char *);
extern int FUN_00198cb8(Text *, TokenRec *);
extern float FUN_0004490c(Font *, unsigned short, Rec *);
}

extern "C" int FUN_00198aa8(Text *self, const char *s, Rec *param_3)
{
    Rec rec;
    float lineH = 16.0f;
    float totalH = 0.0f;

    if (param_3 != 0) {
        rec = *param_3;
    } else {
        rec.f0c = self->iconW;
        rec.f10 = self->scale;
        rec.f14 = self->charSize;
        rec.f18 = self->lineGap;
        rec.f1c = (char)self->color;
    }

    unsigned short code;
    while (*s != '\0') {
        int len = FUN_000447b8(self->font, &code, s);
        if (FUN_00198cb8(self, (TokenRec *)&code) != 0) {
            len++;
        } else {
            int c = code;
            if (c == 0x2a && s[1] == 'Y') {
                totalH += (float)(s[2] - '0');
                s += 2;
            } else if (c == 10) {
                totalH += lineH;
                lineH = 0.0f;
            } else {
                float h = rec.f18 + FUN_0004490c(*(Font * volatile *)&self->font, *(volatile unsigned short *)&code, &rec);
                if (lineH < h) {
                    lineH = h;
                }
            }
        }
        s += len;
    }

    if (code != 10 && FUN_00198cb8(self, (TokenRec *)&code) == 0) {
        totalH += lineH;
    }
    return (int)totalH;
}
