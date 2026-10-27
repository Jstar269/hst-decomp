/* HSTMATCH module=hstp_trans_main.prx start=0x001a4184 end=0x001a49ec symbol=FUN_001a4184 lang=c++ data=0x00388f74 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388f74-0x00388f87) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Text-string layout/draw (t_string.cpp): walks a string of glyphs and control codes (FUN_0004495c returns the
   token length and code); 10 newline, 7 colour (0x5x) or style (0x4x), 8 two-byte callback string, 12 size or
   callback strings, 11 inline icons (queued in the icon list) / variable strings / name slots, 16 a 10x20 glyph
   tile drawn directly; everything else goes to FUN_001a3f24. This Sharing twin of 0x197834 keeps the
   `default: ASSERT(false)` that falls through to case 0x40 (release leaves only a dead `li v0,64`). Info is
   16-byte aligned (frame slot at 96 below the colour); the icon add is an inline member taking its arguments
   (that fixes the scheduling); case 12 reads a plain char and widens it (lb + andi, seb for the size). */
struct Glyphs { char pad0[0x18]; float scale; };

struct Font {
    char pad0[0x19074];
    Glyphs *glyphs;         /* 0x19074 */
    char pad19078[0x19080 - 0x19078];
    void *tex;              /* 0x19080 */
    char pad19084[0x1909c - 0x19084];
    int lineHeight;         /* 0x1909c */
};

typedef const char *(*StrFn)();
typedef const char *(*StrFnI)(int);
typedef const char *(*StrFnU)(unsigned short);

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
    char pad88[0x8c - 0x88];
    StrFn vars[3];          /* 0x8c */
    StrFnI fn80;            /* 0x98 */
    StrFnU fn8;             /* 0x9c */
    char names[4][8];       /* 0xa0 */
    StrFnI fnC0;            /* 0xc0 */
    StrFnI fnD0;            /* 0xc4 */
};

struct Info { float off; float lineH; float z; float w; } __attribute__((aligned(16)));

struct Color { unsigned char r, g, b, a; };

struct Icon { int id; int x; int y; float w; float h; };
struct IconList {
    char pad0[0xf4];
    Icon icons[10];
    int count;
    void Add(int id, int x, int y, float w, float h)
    {
        if (count < 10) {
            Icon *ic = &icons[count];
            ic->id = id;
            ic->x = x;
            ic->y = y;
            ic->w = w;
            ic->h = h;
            count++;
        }
    }
};

extern IconList *DAT_003eaaa8;
extern const char *DAT_00388d48;
extern const char DAT_00388d44[];   /* "" */
extern const char DAT_00388f68[];   /* "\n" */

extern "C" {
void FUN_000114c0(void *p, int c, unsigned n);
void FUN_00011090(void *d, const void *s, unsigned n);
int FUN_001a517c(Text *self, const char *s, int a, int *widths);
void FUN_000149a8(char *d, const char *s);
void FUN_00014788(char *d, const char *s);
int FUN_0004495c(Font *f, unsigned short *code, const char *s);
void FUN_001a3f24(Text *self, int *a, int *b, float *x, int line, int len, const char *str, Info *st,
                  int draw, int p5, char *out);
void FUN_001a3e54(Text *self, int c);
const char *FUN_001a573c(Text *self, int i);
void FUN_001a33a4(const char *fmt, ...);
void FUN_00051d38(void *tex, float s);
void FUN_00051e30(void *tex, int a, int b, int w, int h, int c, int d);
void FUN_00052354(void *tex, Color col, float u0, float v0, float x0, float y0, float u1, float v1,
                  float x1, float y1, float z);
void FUN_000522c0(void *tex);
}

/* Debug build: assertions print through the (empty) variadic debug printf and hang. */
extern const char DAT_00388f14[];   /* "assertion \"%s\" failed: file \"%s\", line %d
" */
extern const char DAT_00388f48[];   /* "t_string.cpp" */
extern const char DAT_00388f6c[];   /* "false" */
#define HST_ASSERT(cond, text, line)     do { if (!(cond)) { FUN_001a33a4(DAT_00388f14, text, DAT_00388f48, line); for (;;) {} } } while (0)

extern "C" void FUN_001a4184(Text *self, const char *s, int measure, int draw, int p5, char *out)
{
    unsigned short code;
    char tmp[18];
    int pa;
    int pb;
    float x;
    float saved = 0.0f;
    int lineEnd = 0;
    int widths[10] = {0};
    Color col;
    Info st;

    pb = 0;
    pa = 0;
    x = 0.0f;
    int line = 0;
    st.lineH = self->scale * (float)self->font->lineHeight;
    st.off = 0.0f;
    st.z = 0.0f;
    if (measure) {
        FUN_000114c0(widths, 0, sizeof(widths));
        lineEnd = FUN_001a517c(self, s, 0, widths);
        st.off = (float)((lineEnd - widths[0]) >> 1);
    }
    if (out)
        FUN_000149a8(out, DAT_00388d44);
    while (*s != 0) {
        int len = FUN_0004495c(self->font, &code, s);
        FUN_00011090(tmp, s, len);
        tmp[len] = 0;
        switch (code) {
        case 10:
            pb = 0;
            pa = 0;
            x = 0.0f;
            line++;
            if (measure) {
                FUN_000114c0(widths, 0, sizeof(widths));
                FUN_001a517c(self, s + len, 0, widths);
                st.off = (float)((lineEnd - widths[0]) >> 1);
            }
            if (out)
                FUN_00014788(out, DAT_00388f68);
            break;
        case 7:
            s++;
            if (draw) {
                char c = *s;
                switch (c & 0xf0) {
                default:
                    HST_ASSERT(false, DAT_00388f6c, 783);
                case 0x40:
                    FUN_001a3e54(self, c - 0x40);
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
            const char *str = DAT_00388d48;
            s++;
            if (self->fn8) {
                unsigned short lo = (unsigned char)s[1] - 0x10;
                unsigned short hi = (unsigned short)s[0] & 0xffbf;
                str = self->fn8(lo + hi * 0xf0);
            }
            FUN_001a3f24(self, &pa, &pb, &x, line, len, str, &st, draw, p5, out);
            s += len;
            break;
        }
        case 12: {
            s++;
            char ch = *s;
            unsigned char c = ch;
            if (c >= 0xd0) {
                const char *str = DAT_00388d48;
                if (self->fnD0)
                    str = self->fnD0(c);
                FUN_001a3f24(self, &pa, &pb, &x, line, len, str, &st, draw, p5, out);
            } else if (c >= 0xc0) {
                const char *str = DAT_00388d48;
                if (self->fnC0)
                    str = self->fnC0(c - 0xc0);
                FUN_001a3f24(self, &pa, &pb, &x, line, len, str, &st, draw, p5, out);
            } else if (c >= 0x80) {
                const char *str = DAT_00388d48;
                if (self->fn80)
                    str = self->fn80(c - 0x80);
                FUN_001a3f24(self, &pa, &pb, &x, line, len, str, &st, draw, p5, out);
            } else {
                int size = ch - 0x40;
                if (size == 15) {
                    self->charSize = saved;
                } else {
                    saved = self->charSize;
                    self->charSize = (float)size;
                }
            }
            break;
        }
        case 11: {
            s++;
            unsigned char c = *s;
            if (c >= 0x40 && c < 0x4e) {
                if (draw)
                    DAT_003eaaa8->Add(c - 0x40, (int)(self->x + x), (int)(self->y + line * (st.lineH + self->lineGap)),
                                      self->iconW, self->scale);
                x += self->charSize + 20.0f;
            } else if (c >= 0x60 && c < 0x63) {
                const char *str = DAT_00388d48;
                StrFn *fn = &self->vars[c - 0x60];
                if (*fn && (*fn)())
                    str = (*fn)();
                FUN_001a3f24(self, &pa, &pb, &x, line, len, str, &st, draw, p5, out);
            } else if (c >= 0x80 && c < 0x84) {
                FUN_001a3f24(self, &pa, &pb, &x, line, len, FUN_001a573c(self, c - 0x80), &st, draw, p5, out);
            } else if (c != 0) {
                FUN_001a33a4("Error, codeTmp=%d\n", c);
            }
            break;
        }
        case 16: {
            s++;
            signed char c = *s;
            int u = c % 16 * 10;
            int v = c / 16 * 20;
            int px = (int)(self->x + x);
            int py = (int)(self->y + line * (st.lineH + self->lineGap) - 1.0f);
            if (draw) {
                FUN_00051d38(self->font->tex, self->font->glyphs->scale);
                FUN_00051e30(self->font->tex, 0, 0, 480, 272, 0, 0);
                col.r = 128;
                col.g = 128;
                col.b = 128;
                col.a = 128;
                FUN_00052354(self->font->tex, col, (float)u, (float)v, (float)px, (float)py, (float)(u + 10),
                             (float)(v + 20), (float)(px + 10), (float)(py + 20), (float)(unsigned)self->depth);
                FUN_000522c0(self->font->tex);
            }
            x += self->charSize + 10.0f;
            pb++;
            break;
        }
        default:
            FUN_001a3f24(self, &pa, &pb, &x, line, len, tmp, &st, draw, p5, out);
            break;
        }
        s += len;
    }
    self->busy = 0;
}
