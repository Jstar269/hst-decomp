/* HSTMATCH module=hstp_trans_main.prx start=0x0001c984 end=0x0001ca74 symbol=FUN_0001c984 lang=c99 */
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef struct Entry { uchar len; uchar val; } Entry;
extern ushort *FUN_0001c8ac(int a, Entry *tab);

void FUN_0001c984(uchar *dst, int a, int n)
{
    Entry tab[1024];
    uchar *end;
    int nbits;
    uint buf;
    ushort *src;
    src = FUN_0001c8ac(a, tab);
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
                *dst++ = (ushort)buf;
                buf >>= 8;
                nbits -= 8;
            }
        } while (dst < end);
    }
}
// NEAR MISS (8 words, all register naming): everything is exact except that `end` (dst + n) takes a1 and `src` takes a2
// where retail has src = a1, end = a2 (buf a3, nbits t0 match). `end` was a1 in all 24 declaration orders of
// {src,end,buf,nbits}; among src/buf/nbits earlier-declared = higher register. Ruled out: while vs if+do-while,
// `base + n` loop bound, end = n + dst / dst; end += n / &dst[n], uchar* returning callee with cast, int end,
// extra end uses, block-scoped end, permuted init order, split src[0]/src++, temp for the loaded halfword.
// Matching idioms: `(ushort)buf & 0x3ff` and `*dst++ = (ushort)buf` (retail keeps the andi 0xffff).
