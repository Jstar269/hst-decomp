/* HSTMATCH module=EBOOT.BIN start=0x000c16f0 end=0x000c1aa0 symbol=FUN_000c16f0 lang=c++ */
/* GAVE-UP — best attempt 230/236 words, first difference at +0x8 (register colouring of the /80 magic only).
   Structure is settled and every block matches apart from register names:
     - early exit: `int n = end - first - 1; if (n == 0) goto done;` with ONE shared tail (`c->size--; return first;`)
       so the `beqzl v0, done` carries `lw v1,4(a0)` in its delay slot; `dst` must be declared INSIDE the
       `if (src < end)` block or it takes that delay slot;
     - the record copy needs `{ Blob{char v[64]}; int b0..b3; Rec(const Rec&) }` - a nested block plus an explicit
       int memberwise ctor - or the four ints go through `lwc1/swc1`;
     - the bulk count is a SIGNED division by a literal 80 (`(int)(bytes + 79) / 80`); `sizeof(Rec)` makes it
       unsigned (multu/srl 6) and loses the mult/sra + sign-fix shape;
     - the eight records are eight separate source copies, then `first += 8; src += 8;`, looping
       `while (src < end - 8)`; the tail is a per-record loop into `dst`;
     - the 13-word guard in front of the bulk pass is NOT compiler-generated: it is written out as a SIGN-BIT
       test on the pointer difference and on difference+79, i.e.
         int bytes = (int)((char *)end - (char *)src);
         if ((bytes & 0x80000000) == 0 && (((bytes + 79) & 0x80000000) != 0)) goto flush;
       (plus a redundant `if (end < src) goto flush;` before it). That is what makes MWCC emit
       `lui t1,0x8000; and` twice instead of a `slt`; it lifted this file from 223 to 230 words. Ruled out:
       memmove/memcpy (no such symbol in the module), typed `Rec*` subtraction, ptrdiff_t/long difference,
       `(n * 80 + 79) / 80` (recomputes the divide, 231 words but wrong shape).
   Names provisional. */
struct Blob {
    char v[64];
};
struct Rec {
    Blob a;
    int b0, b1, b2, b3;
    Rec(const Rec &o) : a(o.a), b0(o.b0), b1(o.b1), b2(o.b2), b3(o.b3) {}
};
struct C {
    Rec *data;
    int size;
};
extern "C" Rec *FUN_000c16f0(C *c, Rec *first)
{
    Rec *end = c->data + c->size;
    int n = end - first - 1;

    if (n == 0)
        goto done;
    {
        Rec *src = first + 1;
        Rec *dst = first;
        if (src < end) {
            int bytes = (int)((char *)end - (char *)src);
            int m = (bytes + 79) / 80;
            if (m < 9)
                goto flush;
            if (end < src)
                goto flush;
            if ((bytes & 0x80000000) == 0 && (((bytes + 79) & 0x80000000) != 0))
                goto flush;
            {
                do {
                    first[0] = src[0];
                    first[1] = src[1];
                    first[2] = src[2];
                    first[3] = src[3];
                    first[4] = src[4];
                    first[5] = src[5];
                    first[6] = src[6];
                    first[7] = src[7];
                    first += 8;
                    src += 8;
                } while (src < end - 8);
            }
        flush:
            for (; src < end; ++src, ++dst)
                *dst = *src;
        }
    }
done:
    c->size--;
    return first;
}
// near miss from lane ds2 (unreviewed)
