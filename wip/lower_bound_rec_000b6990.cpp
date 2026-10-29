/* HSTMATCH module=EBOOT.BIN start=0x000b6990 end=0x000b6a8c symbol=FUN_000b6990 lang=c++ */
struct Rec {
    float f[20];
} __attribute__((aligned(16)));

struct It {
    Rec *p;
};

struct Tag {};

static inline It Make(Rec *p, Tag)
{
    It r;
    r.p = p;
    return r;
}

static inline int Dist(It f, Rec *l, Tag)
{
    return l - f.p;
}

extern "C" void FUN_000b6990(Rec **out, Rec *first, Rec *last, Rec *key)
{
    It f = Make(first, Tag());
    int n = Dist(f, last, Tag());

    if (n < 1) {
        *out = first;
        return;
    }
    Rec keyCopy = *key;
    Rec midCopy;
    while (n > 0) {
        int half = n / 2;
        midCopy = first[half];

        if (midCopy.f[14] < keyCopy.f[14]) {
            first += half + 1;
            n = n - (half + 1);
        } else {
            n = half;
        }
    }
    *out = first;
}
// NEAR 65/63 words, 58 differ (sy3). Replaces the volatile hack of wip/near_miss_000b6990.c: `It f = Make(first, Tag()); n = Dist(f, last, Tag());`
// with Make returning the one-pointer struct BY VALUE from an inline function gives retail's `sw a1,N; lwc1 f0,N; swc1 f0,M; lw t0,M` round trip.
// Rec is aligned(16) so key/mid copies are 16-aligned (retail 16 and 96). Still missing: retail's frame is 192 = 16 (bottom) + 2x80 + 16 (four
// never-written 4-byte slots at 176..191 above the Recs, f at 180, sret at 184); ours is 176 with the slots packed right above the Recs and no
// bottom 16. Empty Tag params of the inline helpers did not reserve slots here. Retail declares mid before key (mid at 96, key at 16).
// near miss from lane sy3 (unreviewed)
