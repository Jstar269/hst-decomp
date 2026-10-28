/* HSTMATCH module=EBOOT.BIN start=0x00003c74 end=0x00003d64 symbol=FUN_00003c74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_00003778(void *self, void **data, unsigned *size);
extern void *FUN_00003c1c(void *obj, const char *msg);
extern void FUN_0000260c(const char *type, void *exc, void (*fn)(void));
extern unsigned *FUN_00003ba4(unsigned *a, unsigned *b);
extern int FUN_00003d64(const char *a, const char *b, unsigned n);
extern void FUN_00003bc0(void);

extern char DAT_002cf2a8[];
extern char DAT_002cf200[];

int FUN_00003c74(void *self, unsigned pos, unsigned n, const char *s, unsigned count)
{
    void *data;
    unsigned size;
    unsigned rest;
    unsigned rlen;
    unsigned x;
    int r;
    char exc[12];

    FUN_00003778(self, &data, &size);
    if (size < pos) {
        void *e = FUN_00003c1c(exc, DAT_002cf2a8);
        FUN_0000260c(DAT_002cf200, e, FUN_00003bc0);
    }
    rest = size - pos;
    rlen = *FUN_00003ba4(&rest, &n);
    x = *FUN_00003ba4(&rlen, &count);
    r = FUN_00003d64((const char *)data + pos, s, x);
    if (r == 0) {
        if (rlen < count) {
            r = -1;
        } else {
            r = rlen != count;
        }
    }
    return r;
}
// PARKED 2026-10-28 (2 compiles): 56/60 words. This is a std::string::compare(pos,n,s,count)
// overload: data/size out-params at 60/56, exception object at 44, rest=size-pos at 36,
// rlen=min(rest,n) at 40, x=min(rlen,count), memcmp(data+pos,s,x), ties -> -1 / != .
// The body compiles almost instruction-for-instruction; the whole gap is retail's FRAME
// POINTER: retail does `move s8,sp` after the saves, homes a2/t0 at 28/32(s8), addresses
// every local through s8 and ends `move sp,s8`. This lane's log records that shape for
// alloca/VLA frames; there is no alloca call in the retail body, so the original source
// must have had one that folded away. Declaring the locals in retail's slot order
// (data,size,exc[12],rlen,rest) is still needed for the offsets once the frame is solved.
// near miss from lane dsn2 (unreviewed)
