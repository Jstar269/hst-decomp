/* HSTMATCH module=EBOOT.BIN start=0x00043180 end=0x0004344c symbol=FUN_00043180 lang=c++ */
/* Clone of src/sharing_main/layout_text_lines_00043264.cpp (hstclone.py tag s10170158a1r4e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Text layout pass over a Font (the object text_layout_string_001a4184.cpp passes to FUN_000447b8): walks the string, appends the glyph codes to the Font's 2048-entry code buffer (buf, cursor cur) and starts a new line record (recs, cursor rcur) at every newline (code 10), returning the widest line; both arrays are real members, so the end tests are `buf + 2048` / `buf + 2047` (a raw `(char *)f + 0x106a` is hoisted into a saved register). Matching idioms: `switch (code)` with the default written FIRST, then `case 0:`, then `case 10:` (an if/else-if chain lays the newline block out first), the ternary `maxw = linew > maxw ? linew : maxw` (an `if` threads the skip branch past the shared `b`), and `if (*s != 0) for (;;) { ..; if (*s == 0) break; }` (a `while (*s != 0 && ..)` is rotated and gives 141 differing words). */
struct Rec {
    float x;            /* 0x00 */
    float y;            /* 0x04 */
    unsigned short w8;  /* 0x08 */
    float f0c;
    float f10;
    float f14;
    float f18;
    char f1c;
    short f1e;
    short f20;
    short f22;
    short f24;
    unsigned short *start;  /* 0x28 */
    int f2c;
};

struct Font {
    char pad0[0x40];
    float x;            /* 0x40 */
    float y;            /* 0x44 */
    unsigned short w48;
    float f4c;
    float f50;
    float f54;
    float f58;
    char f5c;
    short f5e;
    short f60;
    short f62;
    short f64;
    int f68;
    unsigned short buf[2048];   /* 0x6c */
    unsigned short *cur;        /* 0x106c */
    Rec recs[2048];             /* 0x1070 */
    Rec *rcur;                  /* 0x19070 */
    char pad19074[0x1909c - 0x19074];
    int lineHeight;         /* 0x1909c */
};

extern "C" int FUN_000447b8(Font *f, unsigned short *code, const char *s);
extern "C" float FUN_00044858(Font *f, int code, float *x);
extern "C" float FUN_00043180(Font *f, const char *s);

static inline void Save(Font *f, Rec *r)
{
    r->x = f->x;
    r->y = f->y;
    r->w8 = f->w48;
    r->f0c = f->f4c;
    r->f10 = f->f50;
    r->f14 = f->f54;
    r->f18 = f->f58;
    r->f1c = f->f5c;
    r->f1e = f->f5e;
    r->f20 = f->f60;
    r->f22 = f->f62;
    r->f24 = f->f64;
    f->rcur->f2c = f->f68;
}

float FUN_00043180(Font *f, const char *s)
{
    float linew;
    float maxw = 0.0f;
    while (*s != 0) {
        if (f->cur == f->buf + 2048)
            return 0.0f;
        Rec *r = f->rcur;
        if (r == f->recs + 2048)
            return 0.0f;
        Save(f, r);
        f->rcur->start = f->cur;
        f->rcur = f->rcur + 1;
        linew = 0.0f;
        if (*s != 0) {
            for (;;) {
                if (f->cur == f->buf + 2047)
                    break;
                unsigned short code;
                int len = FUN_000447b8(f, &code, s);
                switch (code) {
                default:
                    *f->cur++ = code;
                    linew += FUN_00044858(f, code, &f->x);
                    maxw = linew > maxw ? linew : maxw;
                    break;
                case 0:
                    break;
                case 10:
                    f->y = f->y + (f->f58 + f->f50 * (float)f->lineHeight);
                    linew = 0.0f;
                    Save(f, f->rcur);
                    *f->cur++ = 0;
                    f->rcur->start = f->cur;
                    f->rcur = f->rcur + 1;
                    if (f->rcur == f->recs + 2048)
                        return 0.0f;
                    break;
                }
                s += len;
                if (*s == 0)
                    break;
            }
        }
        *f->cur++ = 0;
    }
    return maxw;
}
