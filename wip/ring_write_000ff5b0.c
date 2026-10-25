/* HSTMATCH module=EBOOT.BIN start=0x000ff5b0 end=0x000ff678 symbol=FUN_000ff5b0 lang=c99 */
/* Near-miss for ring buffer write (best 9 differing words after lnm1's in-place count update).
   The wrap/copy loops and return are exact. Retail tests the original a2 argument, then copies it to s0
   after loading wr/rd/cap and before the avail subtraction; the best candidate mutates n for the clamp,
   which copies it to s0 at entry and tests s0. */
extern void FUN_002b77d8(char *dst, char *src, unsigned n);
extern void FUN_00011090(char *dst, char *src, unsigned n);

typedef struct Ring {
    int pad0;
    char *data;
    unsigned cap;
    unsigned rd;
    unsigned wr;
} Ring;

unsigned FUN_000ff5b0(Ring *r, char *src, unsigned n)
{
    unsigned avail;
    if ((int)n <= 0)
        return n;
    avail = r->cap - (r->wr - r->rd);
    if (avail < n) n = avail;
    {
        unsigned off = r->wr % r->cap;
        unsigned chunk = r->cap - off;
        if (n < chunk)
            chunk = n;
        FUN_002b77d8(r->data + off, src, chunk);
        if (chunk != n)
            FUN_00011090(r->data, src + chunk, n - chunk);
    }
    r->wr = r->wr + n;
    return n;
}
// improved by lane lnm1 (unreviewed): 35 -> 9 differing words
