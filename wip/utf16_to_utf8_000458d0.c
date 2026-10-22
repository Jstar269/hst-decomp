/* HSTMATCH module=EBOOT.BIN start=0x000458d0 end=0x000459f8 symbol=FUN_000458d0 lang=c99 */
/* NEAR MISS: 68/74 words, 43 differ.  Converts a UTF-16 string into UTF-8 and pushes the bytes
   through 0x45ac8; the six-argument call 0x3370 gets the (uninitialised) byte at +0x18 of the
   temporary and 0x3ed4 is told to reserve 0x100 bytes.
   MATCHED: the whole prologue (the frame, the saved registers, the pointer selection between
   self->f14 and self+0xe, the six arguments of 0x3370, the byte at +0x18 read as a signed char),
   the four zero bytes of the output buffer, the signed `slti` compares and the Allegrex `ext`
   instructions of the two- and three-byte encodings.
   IMPORTANT: mwccpsp 219 DOES emit the Allegrex `ext` for `(x >> n) & mask` (no -mext needed), so
   this function is matchable with the normal MWCC profile after all.
   DIFFERENCE: retail keeps the if/else-if chain of the code-unit size with the tests of the earlier
   arms repeated (the `slti v0,v1,128` after the one-byte store and the `bnezl v0` at +0x08 into
   the chain), while MWCC of this spelling jumps straight to the call after the one-byte case and
   reuses the `at` register for the 0x800 test; the chain layout has to be reproduced with a
   different source shape (nested ifs or an explicit goto).
   RULED OUT: the gcc171x profile (its frame layout and code shapes differ completely), an `int`
   code unit (the compares must be signed `slti`, so the unit is an unsigned short that is promoted
   to int), `ushort **` for the pointer at +0x14 (retail loads it once) and the buffer as a plain
   local array (retail has the byte at +0x18 and the buffer at +0x1c of one 8-byte temporary). */
typedef unsigned char uchar;
typedef unsigned short ushort;

typedef struct {
    volatile char c8;
    char pad1[3];
    uchar buf[4];
} Tmp;

typedef struct {
    char pad[0xc];
    int f0c;
    char pad1[2];
    ushort *f14;
} Obj;

extern void FUN_00003370(void *a, int b, int c, int d, int e, int f);
extern void FUN_00003ed4(void *a, int b);
extern void FUN_00045ac8(void *a, uchar *b);

void FUN_000458d0(Obj *self)
{
    ushort *p;
    if ((self->f0c & 1) != 0) {
        p = self->f14;
    } else {
        p = (ushort *)((char *)self + 0xe);
    }
    Tmp t;
    FUN_00003370(self, 0, -1, 0, 0, (int)t.c8);
    FUN_00003ed4(self, 0x100);
    while (*p != 0) {
        t.buf[0] = 0;
        t.buf[1] = 0;
        t.buf[2] = 0;
        t.buf[3] = 0;
        ushort u = *p;
        if (u < 0x80) {
            t.buf[0] = (uchar)(u & 0x7f);
        } else if (u < 0x800) {
            t.buf[0] = (uchar)(((u >> 6) & 0x1f) + 0xc0);
            t.buf[1] = (uchar)((u & 0x3f) + 0x80);
        } else if (u < 0x10000) {
            t.buf[0] = (uchar)(((u >> 12) & 0xf) + 0xe0);
            t.buf[1] = (uchar)(((u >> 6) & 0x3f) + 0x80);
            t.buf[2] = (uchar)((u & 0x3f) + 0x80);
        }
        FUN_00045ac8(self, t.buf);
        p++;
    }
}
// near miss from lane om1 (unreviewed)
