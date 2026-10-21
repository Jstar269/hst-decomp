/* HSTMATCH module=EBOOT.BIN start=0x0001cd38 end=0x0001ce28 symbol=FUN_0001cd38 lang=c99 */
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef struct Entry { uchar len; uchar val; } Entry;
extern ushort *FUN_0001cc60(int a, Entry *tab);

void FUN_0001cd38(uchar *dst, int a, int n)
{
    Entry tab[1024];
    uchar *end;
    int nbits;
    uint buf;
    ushort *src;
    src = FUN_0001cc60(a, tab);
    end = dst + n;
    buf = 0;
    nbits = 0;
    if (dst < end) {
        do {
            Entry *e;
            if (nbits < 16) {
                buf |= (uint)*src++ << nbits;
                nbits += 16;
            }
            e = &tab[(ushort)buf & 0x3ff];
            if (e->len < 11) {
                *dst++ = e->val;
                buf >>= e->len;
                nbits -= e->len;
            } else {
                buf >>= 10;
                nbits -= 10;
                if (nbits < 16) {
                    buf |= (uint)*src++ << nbits;
                    nbits += 16;
}
// NEAR MISS (8 words): everything is exact except the a1/a2 pair. Retail keeps src = a1 and end = a2 (buf a3, nbits t0
// match); ours gives end = a1 and src = a2. The instruction sequence and schedule are byte-identical otherwise, so only
// MWCC's colouring of the {src, end} pair differs. Register order observed: retail src(a1) < end(a2) < buf(a3) < nbits(t0);
// ours end(a1) < src(a2) < buf(a3) < nbits(t0). {buf, nbits, src} always take a3/t0/a2 (earlier declared = higher
// register), so `end` competes with `src` for a1/a2: in retail `end` behaves like a named local (src, declared last,
// takes a1) and in ours like a temporary that takes the leftover low register.
// rt3 tried (2026-10-21), all still 8 words: 24 declaration permutations of {src,end,buf,nbits} (end first, end last,
// nbits/buf/end/src order, src first), end computed before the call / after the call / after buf+nbits, `end = &dst[n]`,
// `end = dst + (unsigned)n`, `end` as `const uchar *`, `src` as `const ushort *`, an `unsigned n` parameter, the callee
// returning `uchar *` with a cast to `ushort *` at the assignment, a cast at the assignment, and an explicit
// `float`-style temp for the loaded halfword. Moving the end computation before the call changes 54 words (the addu
// then precedes the jal), so the call has to stay first.
// Ruled out for the a1/a2 swap: while vs if+do-while, `base + n` loop bound, end = n + dst / dst; end += n,
// uchar* returning callee with cast, int end, extra end uses, block-scoped end, split src[0]/src++.
// Matching idioms: `(ushort)buf & 0x3ff` and `*dst++ = (ushort)buf` (retail keeps the andi 0xffff).

                *dst++ = (ushort)buf;
                buf >>= 8;
                nbits -= 8;
            }
        } while (dst < end);
    }
}
// near miss from lane rt3 (unreviewed)
